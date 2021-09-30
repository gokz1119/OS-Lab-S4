# #! /bin/bash

# read -p "Enter the file name: " file_name #Reads the file name from the user
# n=$(wc -l < $file_name)

# echo "File before deletion of duplicate lines"
# while read line
# do
#     echo $line
# done < $file_name

# for(( i=1; i<=n; i++ ))
# do
#     l1=`awk "NR==$i" $file_name` #Gets the ith line and stores it in l1
#     for(( j=i+1; j<=n; j++ ))
#     do
#         l2=`awk "NR==$j" $file_name`
#         if [[ $l1 == $l2 ]]
#         then
#             sed -i "$j d" $file_name
#             # j=$((j-1))
#         fi    
#     done
# done

# echo
# echo "--------------------"
# echo

# echo "File after deletion of duplicate lines"
# while read line
# do
#     echo $line
# done < $file_name

#! /bin/bash 
sort $1 > sorted.txt
uniq sorted.txt nondupe.txt
rm sorted.txt