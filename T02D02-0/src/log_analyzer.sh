#!/bin/bash

# Script analyse log of file

# read file
read -p "input path of your file: " file

if [ -n "$file" ]; then
	if [ -e $file ]; then
		echo `awk '{print $1}' "$file" | wc -l`' '`awk '{print $1}' "$file" | uniq | wc -l`' '`awk '{print $8}' "$file" | uniq | wc -l`		
	else
		echo "file not exist. Bye!"
	fi
else
	echo 'Null result. Bye!'
fi
