{
  description = "A flake for installing norpie's dwm build";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = {
    self,
    nixpkgs,
    flake-utils,
  }:
    flake-utils.lib.eachDefaultSystem (
      system: let
        pkgs = import nixpkgs {
          inherit system;
          overlays = [
            (final: prev: {
              dwm-norpie = prev.dwm.overrideAttrs (oldAttrs: rec {
                version = "master";
                src = ./.;
              });
            })
          ];
        };
      in rec {
        apps = {
          dwm = {
            type = "app";
            program = "${defaultPackage}/bin/dwm";
          };
        };

        packages.dwm-norpie = pkgs.dwm-norpie;
        defaultApp = apps.dwm;
        defaultPackage = pkgs.dwm-norpie;

        devShell = pkgs.mkShell {
          buildInputs = with pkgs; [xorg.libX11 xorg.libXft xorg.libXinerama gcc bear];
        };
      }
    );
}
