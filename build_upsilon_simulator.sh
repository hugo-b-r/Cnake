#!/bin/bash

cd ../
git clone --recursive https://github.com/UpsilonNumworks/Upsilon.git

cp -r Cnake/inc Upsilon/apps/external/app
cp Cnake/*.c Upsilon/apps/external/app
cp Cnake/sources.mak Upsilon/apps/external/app

wget https://raw.githubusercontent.com/lemoustachu/Upsilon-External/Cnake/apps/Cnake/Makefile -O Upsilon/apps/external/app/Makefile
wget https://raw.githubusercontent.com/lemoustachu/Upsilon-External/Cnake/apps/Cnake/inc/init.h -O Upsilon/apps/external/app/inc/init.h

cd Upsilon
make PLATFORM=simulator -j8 #you may want to configure building processes here.
