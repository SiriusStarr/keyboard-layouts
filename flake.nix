{
  description = "My keyboard firmware";

  inputs = {
    nixpkgs.url = github:NixOS/nixpkgs;

    kaleidoscope = {
      url = "github:keyboardio/Kaleidoscope";
      flake = false;
    };

    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = {
    self,
    nixpkgs,
    kaleidoscope,
    flake-utils,
  }:
    flake-utils.lib.eachDefaultSystem
    (
      system: let
        pkgs = nixpkgs.legacyPackages.${system};
      in {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            arduino-cli
          ];

          shellHook = ''
            export KALEIDOSCOPE_DIR=${kaleidoscope}
            export ARDUINO_DIRECTORIES_USER=/tmp/arduino/user
            export ARDUINO_DIRECTORIES_DATA=/tmp/arduino/data
            export ARDUINO_DIRECTORIES_DOWNLOADS=/tmp/arduino/downloads
            make -f ${kaleidoscope}/Makefile setup
            export PATH="${kaleidoscope}/bin:$PATH"
          '';
        };
      }
    );
}
