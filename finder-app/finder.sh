#!/bin/sh

filesdir=$1
searchstr=$2

if [ "$#" -ne 2 ]
then
	echo "Requires 2 arguments: file directory and search string"
	exit 1
elif [ ! -d "$filesdir" ]
then
	echo "File director $filesdir cannot be found"
	exit 1
else
	num_files=$(find $filesdir -type f | wc -l)
	num_matching_lines=$(grep -r $searchstr $filesdir | wc -l)
	echo "The number of files are $num_files and the number of matching lines are $num_matching_lines"
fi
