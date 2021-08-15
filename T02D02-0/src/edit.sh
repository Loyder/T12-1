#!/bin/bash

# script replacement row in file

# read file
read -p "input path of your file: " file
file_log="files.log"

if [ -n "$file" ]; then
	if [ -e $file ]; then
		# show file before change
		cat $file

		# read source_row
		read -p "input source row: " source_row

		if [ -n "$source_row" ]; then
			# read replace_row
			read -p "input row for replacement: " replace_row
			if [ "$source_row" != "$replace_row" ]; then
				# replacement row (number_of_row)
				sed -i '' -e 's/'$source_row'/'$replace_row'/g' $file
				cat $file

				# input logs to src/files.log							
				echo `pwd | cut -d/ -f5`'/'"$file"' - '`stat -f%z $file`' - '`stat -f %Sm -t %F" "%R $file`' - '`shasum -a 256 $file | awk '{print $1}'`' - sha256' >> $file_log
				cat $file_log
			else
				echo 'Source row and replace row is equal. Nothing to do. Bye!'	
			fi
		else
			echo 'Void string. Bye!'
		fi
	else
		echo "file not exist. Bye!"
	fi
else
	echo 'Null result. Bye!'
fi
