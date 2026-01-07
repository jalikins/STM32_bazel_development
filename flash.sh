#!/bin/bash
# Bazel passes the path to the elf via the runfiles directory
ELF_PATH=$(find . -name "blinky.elf" | head -n 1)

if [ -z "$ELF_PATH" ]; then
    echo "Error: blinky.elf not found."
    exit 1
fi

openocd -f interface/stlink.cfg -f target/stm32g4x.cfg -c "program $ELF_PATH verify reset exit"