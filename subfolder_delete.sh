#! /bin/bash

read -p "Enter the directory name: " dir
cd $dir
c=`find ./ -type d -empty`
echo "The deleted directories are: $c"
find ./ -type d -empty -delete
echo -n "Returning to original directory "
cd -