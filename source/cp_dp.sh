#!/bin/bash

# script qui copier les fichiers dans leur empecement

OB=$(ls | grep *.o | wc -l)
BIB=$(ls | grep *.so | wc -l)
SRC=$(ls | grep -v *.c | grep -v *.h | wc -l)

# copier le fichier source .o
if [[ $OB -gt 0 ]]; then
	mv *.o ../objet
fi

# copier le fichier source .so
if [[ $BIB -gt 0 ]]; then
	mv *.so '../source'

fi

# copier les restes non fichier source .h ou .c dans ../
if [[ $SRC -gt 0 ]]; then
	while [[ $SRC -le 0 ]]
	do
		a=$(grep -v *.c | grep -v *.h | head -n 1)
		mv $a ../
		SRC = $(( $SRS - 1))
	done
fi
