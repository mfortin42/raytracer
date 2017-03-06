#!/bin/bash

RED_COLOR='tput setaf 1'
GREEN_COLOR='tput setaf 2'
NORMAL_COLOR='tput sgr0'
if [ "$1" = "" ]
then
	echo "Wrong arguments"
else
	FILE=()
	while read line; do
		FILE+=($line)
	done < $1
	if [ ! -f "raytracer" ];
	then
		make re
	fi
	count=${FILE[0]}
	folder=${FILE[1]}
	filename=${FILE[2]}
	if [ -d $folder ]; then
		read -p "$(${RED_COLOR})There is already a folder there, do you really want to overwrite it ? y/n      $(${NORMAL_COLOR})" -n 1 -r
		echo
		if [[ $REPLY =~ ^[Yy]$ ]]
		then
			rm -rf "$folder" && mkdir "$folder"
		else
			exit
		fi
	else
		mkdir "$folder"
	fi
	echo "$(${GREEN_COLOR})Correctly created render folder$(${NORMAL_COLOR})"
	for (( i=0; i < $count; ++i))
	do
		echo "$(${NORMAL_COLOR})rendering image n ${i}$(${GREEN_COLOR})"
		./raytracer ${filename}${i}.xml -screenshot_headless ${folder}/screenshot
	done
		if [ "$(uname)" == "Darwin" ]; then
			open ${folder}
		elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
			xdg-open ${folder}
		fi
	echo "$(${NORMAL_COLOR})"
fi
