#!/bin/bash

rm -rf site

mkdir temp
mkdir temp/about
mkdir temp/cv
mkdir temp/posts
mkdir temp/projects

cd posts
for f in *.md; do pandoc -f markdown -t html "$f" -o "../temp/posts/${f%.md}.html";done

cd ../about
pandoc -f markdown -t html index.md -o ../temp/about/index.html

cd ../cv
pandoc -f markdown -t html index.md -o ../temp/cv/index.html

cd ..
cp -R projects temp

mkdir site

cp -R temp/ site

cc -std=c99 -DDEBUG -Wall -Wpedantic -Wshadow -Wextra -Werror=implicit-int -Werror=incompatible-pointer-types -Werror=int-conversion -g -Og -fsanitize=address -fsanitize=undefined main.c -o main

./main
rm ./main

cp -R assets site
cp -R img site
cp index.html CNAME site

rm -rf temp main.dSYM