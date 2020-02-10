# Wake-on-LAN (WoL)

## What It Is
Wake-on-LAN is an ethernet computer networking standard that allows a computer to be turned on remotely, whether it's *hibernating*, *sleeping*, or even completely *powered off*

## Why Use It?
- To use a computer remotely outside for work
- To turn on the computer on an emergency
- To turn on the computer without waking up from the bed!

## How It's Done
WoL works by receiving what's called a **magic packet**

## Requirements
- the computer needs to support Wake-on-LAN with a compatible BIOS and NIC (network interface card)
- works regardless of the operating system


## WoL Setup
### BIOS Setup
1. Enter BIOS or UEFI
2. Look for **Power Management** section and enable WoL
3. Save the changes.

### OS Setup
This website shows the step-by-step guides to enable WoL from different operating systems (Windows, macOS and Linux): https://www.lifewire.com/wake-on-lan-4149800

## Issues and Solutions
### WoL is not working when the computer is in hibernate mode
- NIC-level power management configuration is required
- You need to **disable the following three entries** in the *Power Management* section in *Device Manager*-*Network adapters*-*Ethernet Adapter-Properties*
  1. Allow the computer to turn off this device to save power
  2. Allow this device to wake the computer
  3. Only allow a magic packet to wake the computer
