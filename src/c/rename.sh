#!/bin/bash
set -e

echo -n "renaming $1 to $2: "

sed -i "" "s/#include \"$1.h\"/#include \"$2.h\"/g" src/$1.c test/$1.c

mv inc/$1.h inc/$2.h
mv src/$1.c src/$2.c
mv test/$1.c test/$2.c

echo "all done."
