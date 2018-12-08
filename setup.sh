#!/bin/bash

PROJ=/home/pat/MwPSiS-projekt
#PROJ2=`git rev-parse --show-toplevel`

cd "$PROJ"
./ModelDataGenerator/Generator "$1" >> /dev/null

./solve_gmpl model.mod data.dat | tee tmp.log | sed -n '/^y\[/p' 

rm -f tmp.log
