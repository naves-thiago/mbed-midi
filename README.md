# mbed-midi
This is a simple MIDI test using the MBED SDK.
This simply map the position of a potentiometer conected to a mbed's pin p20 to a control change MIDI message on control 1 channel 1.

build instructions for LPC1768 with Arm GCC toolchain:
------------------------------------------------------
```
$ python workspace_tools/build.py -t GCC_ARM -m LPC1768 --usb
$ python workspace_tools/make.py -t GCC_ARM -m LPC1768 -n MIDI --usb
```
