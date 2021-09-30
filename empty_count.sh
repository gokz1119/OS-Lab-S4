#! /bin/bash
cd $1
c=`find ./ -type d -empty`
cd -
echo $c >> EmptyDirs.txt