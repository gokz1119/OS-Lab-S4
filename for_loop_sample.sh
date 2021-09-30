#! /bin/bash

# for i in {1..5}
# do
#     for j in {1..$i}
#     do
#         echo -n "a"
#     done
#     echo
# done

for (( i=0; i<5; i=i+2 ))
do
    for (( j=0; j<=i; j++ ))
    do
        echo -n $j
    done
    echo
done