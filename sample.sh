#! /bin/sh 
sort $1 > sorted.txt
uniq sorted.txt unique.txt
rm sorted.txt