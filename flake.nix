{
  description = "gtk crash";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs, ... } @ inputs:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
    in
      {
        devShells."${system}".default = pkgs.mkShell {
          packages = with pkgs; [
            meson
            ninja

            blueprint-compiler
            gtk4
            libadwaita
            pkg-config
          ];
        };

        packages."${system}".default = pkgs.stdenv.mkDerivation rec {
          name = "crasher";
          src = self;
          outputs = [ "out" "dev" ];          

          buildInputs = with pkgs; [
            libadwaita
          ];
          nativeBuildInputs = with pkgs; [
            meson
            ninja

            blueprint-compiler
            gtk4
            libadwaita
            pkg-config
          ];
        };

      };
}
