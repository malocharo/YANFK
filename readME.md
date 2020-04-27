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

`cd qemu && ./configure --target-list=aarch64-softmmu && make -j 4`

It will use 4 core to build, if you have more change the number but it's a fast build even with 4.

Congrats you made it.

## Execute

First run `make` at project top dir. You now have a `kernel8.img`. Then launch qemu with this image.

`path/to/qemu/aarch64-softmmu/qemu-system-arch64 -M raspi3 -kernel kernel8.img -serial null -serial stdio`

The `-serial null -serial stdio` allow to have the mini-uart output on the terminal.

## So far...
So far we have a single cpu booting (qemu doesn't emulate multicore idk why).

A little kprintf() like function that only work with as identifier:
* %d for integer
* %h for hexa
* %c for char
* %s for strings

A function to get the running CPU id and another to get the current CPU exception level. The cpu switch from exception level 2 to level 1 where it will be executed CH style.

## Planning on...
intrinsics implementation of memset,memcpy etc in assembly to be BLAZZING fast and look like a cool kid.

Scheduler with O(1) algorithm.

Use space process and sys call.

I will probably give up before that anyway.
