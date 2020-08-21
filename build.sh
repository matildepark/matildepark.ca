#!/bin/bash

mkdir site
mkdir site/about
mkdir site/cv
mkdir site/posts
mkdir site/projects

cd posts
for f in *.md; do pandoc -f markdown -t html "$f" -o "../site/posts/${f%.md}.html";done

cd ../about
pandoc -f markdown -t html index.md -o ../site/about/index.html

cd ../cv
pandoc -f markdown -t html index.md -o ../site/cv/index.html

cd ..

cc -std=c99 -DDEBUG -Wall -Wpedantic -Wshadow -Wextra -Werror=implicit-int -Werror=incompatible-pointer-types -Werror=int-conversion -g -Og -fsanitize=address -fsanitize=undefined main.c -o main

./main
rm ./main

cp -R assets site
cp -R img site
cp index.html CNAME site