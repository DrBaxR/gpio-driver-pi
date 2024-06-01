# Description

This is a GPIO driver for the Raspberry Pi mainly made for learning purposes.

## Prerequisites

You will need a Raspberry Pi to which you installed its kernel module headers. If you are running Raspbian on it, you can do this by running `sudo apt install raspberrypi-kernel-headers`.

## Makefile

The most important targets are `make install` (which should be run with `sudo`, since it also loads the module into the kernel) and maybe `make deploy`, in case you cloned the code onto a machine that is not the Raspberry Pi to which you want to install the driver.

In order for the `deploy` target to work, you will need to adjust the `PI_DIR` (directory where you'll copy the cloned directory on the Pi) and `PI_HOST` (Pi's `user@hostname`) variables in the `Makefile`.

## Credits

This project was inspired by Low Level Learning's playlist, [Writing a Driver on the Raspberry Pi: Kernel Mode Programming](https://www.youtube.com/watch?v=lWzFFusYg6g&list=PLc7W4b0WHTAX4F1Byvs4Bp7c8yCDSiKa9). I highly recommend watching it if you want to learn more about Linux kernel modules.
