{
  description = "My keyboard firmware";

  inputs = {
    nixpkgs.url = github:NixOS/nixpkgs;

    kaleidoscope = {
      url = "github:keyboardio/Kaleidoscope";
      flake = false;
    };

    keymap-drawer-src = {
      url = "github:caksoylar/keymap-drawer";
      flake = false;
    };

    poetry2nix = {
      url = "github:nix-community/poetry2nix";
      inputs.nixpkgs.follows = "nixpkgs";
    };

    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = {
    self,
    nixpkgs,
    kaleidoscope,
    keymap-drawer-src,
    poetry2nix,
    flake-utils,
  }:
    flake-utils.lib.eachDefaultSystem
    (
      system: let
        overlay = nixpkgs.lib.composeManyExtensions [
          poetry2nix.overlays.default
          (final: prev: {
            keymap-drawer = prev.poetry2nix.mkPoetryApplication {
              projectDir = keymap-drawer-src;

              overrides =
                prev.poetry2nix.defaultPoetryOverrides.extend
                (self: super: {
                  deptry =
                    super.deptry.overridePythonAttrs
                    (
                      old: {
                        buildInputs = (old.buildInputs or []) ++ [super.poetry];
                      }
                    );
                });
            };
          })
        ];

        pkgs = import nixpkgs {
          inherit system;
          overlays = [overlay];
        };
      in {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            arduino-cli
            clang-tools
            git
            hid-listen # For keylogging
            qmk
          ];

          shellHook = let
            kaleidoscopeSetup = ''
              export KALEIDOSCOPE_DIR=${kaleidoscope}
              export ARDUINO_DIRECTORIES_USER=/tmp/arduino/user
              export ARDUINO_DIRECTORIES_DATA=/tmp/arduino/data
              export ARDUINO_DIRECTORIES_DOWNLOADS=/tmp/arduino/downloads
              make -f ${kaleidoscope}/Makefile setup
              export PATH="${kaleidoscope}/bin:${pkgs.keymap-drawer}/bin:$PATH"
            '';

            qmkSetup = ''
              export QMK_HOME=/tmp/qmk_firmware
              qmk setup -y
              rm -rf /tmp/qmk_firmware/.build
              rm -rf /tmp/qmk_firmware/keyboards/keyboardio
              ln -fs ${self}/QMK/keyboards/* /tmp/qmk_firmware/keyboards
              ln -fs ${self}/QMK/users/* /tmp/qmk_firmware/users
            '';

            vialSetup = ''
              alias vial-qmk='env QMK_HOME=/tmp/vial_firmware qmk'
              vial-qmk setup SiriusStarr/svalboard-vial-qmk -b vial -y
              rm -rf /tmp/vial_firmware/.build
            '';
          in
            kaleidoscopeSetup + vialSetup + qmkSetup;
        };
      }
    );
}
