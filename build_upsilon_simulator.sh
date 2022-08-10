#!/bin/bash

cd ../
git clone --recursive https://github.com/UpsilonNumworks/Upsilon.git

cp -r Cnake/inc Upsilon/apps/external/app
cp Cnake/*.c Upsilon/apps/external/app
cp Cnake/sources.mak Upsilon/apps/external/app
