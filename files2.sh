#! /bin/bash

read -p "Enter the name of the file: " file_name
n=$(wc -l < $file_name)
echo "Number of lines - $n"
i=4
j=5
k=6
echo -n "4th line - "
head -n $i $file_name | tail -n +$i
l=`awk "NR==$j" $file_name`
echo "5th line - $l"
echo "Deleting 6th line"
sed -i "$k d" $file_name
while read line
do
    echo $line
done < $file_name
i=10
echo "oldi = $i"
i=$((i-1))
echo "newi = $i"