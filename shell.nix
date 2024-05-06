{ pkgs ? import <nixpkgs> {} }:
  pkgs.mkShell {
    nativeBuildInputs = with pkgs; [
      gnumake
      xorg.libX11.dev
      xorg.xhost
      xorg.libXft
      xorg.libXinerama
    ];
}
