#!/bin/bash

PROJ=/home/mi/Desktop/mpsis/MwPSiS-Projekt
#PROJ2=`git rev-parse --show-toplevel`

cd "$PROJ"
./ModelDataGenerator/Generator "$1" >> /dev/null

start=$(($(date +%s%N)/1000000)); 
./solve_gmpl model.mod data.dat | grep -v " = 0" | grep FINAL  | sed 's/FINAL_LOG://' | tr '\n' 'Y' | sed 's/Y/\<br\>/g' | tee res.txt
end=$(($(date +%s%N)/1000000)); 

echo "Execution time: "$(((end-start)/1000))"s<br><br>" | tee -a res.txt

start=$(($(date +%s%N)/1000000)); 
./Heuristic/heuristic data.dat | grep FINAL  | sed 's/FINAL_LOG://' | tr '\n' 'Y' | sed 's/Y/\<br\>/g' | tee -a res.txt
end=$(($(date +%s%N)/1000000)); 

echo "Execution time: "$(((end-start)/1000))"s<br><br>" | tee -a res.txt

curl --request POST --data-binary "@res.txt" 127.0.0.1/cgi-bin/upload.sh
