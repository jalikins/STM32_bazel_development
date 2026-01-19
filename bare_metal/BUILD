load("//third_party:stm32cubeg4.bzl", "hal_library")


platform(
    name = "stm32_platform",
    constraint_values = [
        "@platforms//cpu:armv7e-m", # Standard constraint for Cortex-M7
        "@platforms//os:none",      # Bare metal 
    ],
)

cc_binary(
    name = "main.elf",
    srcs = [
        "interrupts.c", 
        "main.c",       
        "startup.c",
    ],
    linkopts = [
        "-T $(execpath :stm32g441.ld)", 
        "-Wl,--no-warn-rwx-segments",
    ],
    target_compatible_with = [
        "@platforms//cpu:armv7e-m", # I touched this
        "@platforms//os:none",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":hal",
        ":stm32g441.ld", 
    ],
)

cc_library(
    name = "hal_conf",
    hdrs = ["stm32g4xx_hal_conf.h"],
    includes = ["."],
    visibility = ["//visibility:private"],
)

hal_library(
    name = "hal",
    device = "STM32G441xx",
    hal_config_lib = ":hal_conf",
    hse_value = 16000000,
    visibility = ["//visibility:private"],
)