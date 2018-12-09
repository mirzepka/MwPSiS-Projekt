#!/bin/bash

PROJ=/home/grzegorz/MwPSiS-Projekt
#PROJ2=`git rev-parse --show-toplevel`

cd "$PROJ"
./ModelDataGenerator/Generator "$1" >> /dev/null

start=$(($(date +%s%N)/1000000)); 
./solve_gmpl model.mod data.dat | grep FINAL  | sed 's/FINAL_LOG://' | tee res.txt
end=$(($(date +%s%N)/1000000)); 

echo "Execution time: "$(((end-start)/1000))s | tee -a res.txt

start=$(($(date +%s%N)/1000000)); 
./Heuristic/heuristic data.dat | grep FINAL  | sed 's/FINAL_LOG://' | tee -a res.txt
end=$(($(date +%s%N)/1000000)); 

echo "Execution time: "$(((end-start)/1000))s | tee -a res.txt

curl --request POST --data-binary "@res.txt" 127.0.0.1/cgi-bin/upload.sh
