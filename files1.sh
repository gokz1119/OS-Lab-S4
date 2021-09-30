#! /bin/bash

echo -e "Enter the name of the file: \c"
read file_name

# if [ -e $file_name ] #To check if a file exists use '-e'
# then
#     echo "File exists"
# else
#     echo "File doesn't exist"
# fi

# if [ -s $file_name ] #To check if a file is empty use '-s'
# then
#     echo "File empty"
# else
#     echo "File isn't empty"
# fi

if [ -f $file_name ] 
then
    if [ -w $file_name ]
    then
        echo "Type the text to be appended. To quit, press CTRL + D"
        cat >> $file_name # '>>' is used for appending with cat
    else
        echo "File doesn't have write permissions"
    fi
else
    echo "File doesn't exist"
fi