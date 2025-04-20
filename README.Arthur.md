Get the toolchain from https://github.com/tttapa/docker-arm-cross-toolchain?tab=readme-ov-file
use armv8-rpi3-linux-gnueabihf, for x86

Extract into /home/box:

    tar xJf Downloads/x-tools-armv8-rpi3-linux-gnueabihf-gcc12.tar.xz

Configure waf:

    cd /home/box/ardupilot
    ./waf configure --board=navio2 --toolchain=/home/box/x-tools/armv8-rpi3-linux-gnueabihf/bin/armv8-rpi3-linux-gnueabihf

Compile:

    ./waf rover
