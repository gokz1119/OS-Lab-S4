#! /bin/bash

for (( i=1; i<=13; i=i+2 ))
do 
    for (( j=1; j<=i; j++ ))
    do
        echo -e "#\c"
    done
    echo
done