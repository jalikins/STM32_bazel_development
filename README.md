# bazel_stm32

This repository contains Bazel build configurations for STM32 microcontrollers.

To build the `bare_metal` project:

```Shell
bazel build --config=m4 //bare_metal:main.elf
```
To build specific targets, you can use:

```Shell
bazel bazel build --config=m4 //mkiii/software/lv/throttle:throttle.elf
```
