#!/bin/sh

writefile=$1
writestr=$2

if [ $# -ne 2 ]
then
	echo "Requires 2 arguments: file to write and string to write"
	exit 1
else
	mkdir -p "$(dirname $writefile)"
	echo $writestr > $writefile
fi
