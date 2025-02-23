#!/bin/bash

for f in $(find . -name "*.c" | sed -e"s/.c//g")
do
        printf "TEST: $f ... "
        make $f 1>/dev/null
        if ./$f >>log.txt
        then
                echo "OK"
        else
                echo "ERR"
        fi
        rm $f
done
