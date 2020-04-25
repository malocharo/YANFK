# YANFK

## Introduction
Yet Another Never Finished Kernel or YANFK (pronounced "KaaAAris" [ˌʌnɪmˈplɔɪd] in French) is a project where I learn about OS dev using Raspberry Pi 3 emulated on Qemu. Sloppy code, poor arch choices and failure are to be expected.

## Setup
### Toolchain
You need a cross compiler, so just `apt-get install gcc-aarch64-linux-gnu build-essential`  and you good mate.
### Qemu
As you might expecting the setup is easy.

First we'll need some tools: `libglib2.0-dev autoconf libpixman-1-dev`

Then get qemu: `git clone git://git.qemu.org/qemu.git` and configure it to build for emulate raspi3.

`cd qemu && ./configure --targer-list=aarch64-softmmu && make -j 4`

It will use 4 core to build, if you have more change the number but it's a fast build even with 4.

Congrats you made it.

## Execute

First run `make` at project top dir. You now have a `kernel8.img`. Then launch qemu with this image.

`path/to/qemu/aarch64-softmmu/qemu-system-arch64 -M raspi3 -kernel kernel8.img -serial null -serial stdio`

The `-serial null -serial stdio` allow to have the mini-uart output on the terminal, right now you should see a nice "Hello,World" and then a end-less loop.