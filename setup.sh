#!/bin/bash

PROJ=/home/mi/Desktop/mpsis/MwPSiS-Projekt

cd "$PROJ"
./ModelDataGenerator/Generator "$1" >> /dev/null

echo "Wybrana liczba lotnisk: $(($1*$1))<br><br>" | tee res.txt
echo "Wybrana liczba pasażerów: $((2*$1))<br><br>" | tee res.txt

start=$(($(date +%s%N)/1000000)); 
cbc model.mod%data.dat -randomCbcSeed 0 -randomSeed 0 -proximity on -threads 8 -printi csv -solve -solu modelname.csv | grep "Objective value" | sed 's/Objective value:                /Cost: /' | cut -f1 -d "." | tr '\n' 'Y' | sed 's/Y/\<br\>/g' | tee -a res.txt
end=$(($(date +%s%N)/1000000)); 

echo "Execution time: "$(((end-start)/1000))"s<br><br>" | tee -a res.txt

start=$(($(date +%s%N)/1000000)); 
./Heuristic/heuristic data.dat | grep FINAL  | sed 's/FINAL_LOG://' | tr '\n' 'Y' | sed 's/Y/\<br\>/g' | tee -a res.txt
end=$(($(date +%s%N)/1000000)); 

echo "Execution time: "$(((end-start)/1000))"s<br><br>" | tee -a res.txt

curl --request POST --data-binary "@res.txt" 127.0.0.1/cgi-bin/upload.sh
