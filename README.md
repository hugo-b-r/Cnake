# Cnake
Cnake is a simple Snake game made in C. It will work in Linux and Windows, maybe MacOS (I could never try).


### Building

Clone repo:
```shell
git clone https://github.com/lemoustachu/Cnake.git
```

Change directory:
```shell
cd Cnake
```

and then:
```bash
make clean
make
```

If you want to build for another platform, declare PLATFORM among `windows`,
`linux` & `numworks`. For example on linux to build for windows:
```bash
make clean
make PLATFORM=windows
```


### Gameplay

<img src="assets/gameplay.gif" alt="gameplay" width="282"/> 


### Installing

#### Numworks n0110 running Omega/Upsilon
You can go to this [website](https://lemoustachu.github.io/Upsilon-External/) using a chromium-based browser to install this app (FOr now, the old app from 2022) on your calculator. 
WARNING: The installation of a new app will erase the old external apps and games. 

#### Simulator
You can execute the script specially made for buildidng the simulator using the external app. You may want to install dependencies before.
For debian-based distros:
```bash
apt install wget gdb gcc g++ libgmp-dev libmpfr-dev libmpfi-dev libpari-dev libgsl0-dev libxext-dev libpng-dev libjpeg-dev libreadline-dev libncurses5-dev mesa-common-dev libx11-dev libxt-dev libxft-dev libntl-dev libgl1-mesa-dev libgl-dev libao-dev hevea debhelper libfltk1.3-dev build-essential git imagemagick libx11-dev libxext-dev libfreetype6-dev libpng-dev libjpeg-dev pkg-config gcc-arm-none-eabi binutils-arm-none-eabi dfu-util texinfo autoconf-archive
```
Please refer to [this doc](https://github.com/UpsilonNumworks/Upsilon-External/blob/master/docs/install-sdk.md) to get sdk for your operating system.

Then, to get the repo, just:
```bash
make upsilonrepo
```

And for building:
```bash
make upsilon
```

Before rebuilding:
```bash
make upsilonclean
```

Rebuilding without cleaning:
```bash
make upsilonsimulator
```


### Roadmap

- [x] Menu
- [x] Fix to big when starting and score > height
- [x] Fix able to go on top border
- [x] Create more general functions in menu.c
- [x] Get level input and output on numworks calculator
- [x] Clean input code (extapp_getKey or isKeypressed())
- [x] Add linux support
- [x] Make error messages work on windows
- [ ] Finish winows support
