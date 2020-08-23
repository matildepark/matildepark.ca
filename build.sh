#!/bin/bash

rm -rf site

mkdir temp
mkdir temp/about
mkdir temp/cv
mkdir temp/posts
mkdir temp/projects

cd posts
for f in *.md; do pandoc -f markdown -t html "$f" -o "../temp/posts/${f%.md}.html";done

cd ../temp/posts

posts=(*)

# reverse array, newest date first
min=0
max=$(( ${#posts[@]} -1 ))

while [[ min -lt max ]]
do
    x="${posts[$min]}"
    posts[$min]="${posts[$max]}"
    posts[$max]="$x"

    (( min++, max-- ))
done

# grab title, desc, date
titleregex='<h1 class="h1-title">.(.*).</h1>'
descregex='<meta name="twitter:description" content="(.*)" \/>'
dateregex='<time datetime=".*">(.*)</time>'

# write the directory as html
touch index.html
echo -en '<h1 class="h1-title">blog</h1>\n' >> index.html

for p in "${posts[@]}"
do
  echo -en '<div class="post-block">\n\t' >> index.html
  post=$(<$p)
  if [[ $post =~ $dateregex ]]
  then
    date="${BASH_REMATCH[1]}"
    echo -en "<time>${date}</time>\n\t" >> index.html
  fi
  if [[ $post =~ $titleregex ]]
  then
    title="${BASH_REMATCH[1]}"
    mv $p "$title.html"
    echo -en "<h2 class='highlighter'>\n\t\t<a href=\"./${title}.html\">${title}</a></h2>\n\t" >> index.html
  fi
  if [[ $post =~ $descregex ]]
  then
    description="${BASH_REMATCH[1]}"
    echo -en "<p>${description}</p>\n" >> index.html
  fi
  echo -en "</div>\n" >> index.html
done

cd ../../about
pandoc -f markdown -t html index.md -o ../temp/about/index.html

cd ../cv
pandoc -f markdown -t html index.md -o ../temp/cv/index.html

cd ..
cp -R projects temp

mkdir site

cp -R temp/* site

cc -std=c99 -DDEBUG -Wall -Wpedantic -Wshadow -Wextra -Werror=implicit-int -Werror=incompatible-pointer-types -Werror=int-conversion -g -Og -fsanitize=address -fsanitize=undefined main.c -o main

./main
rm ./main

cp -R assets site
cp -R img site
cp index.html _redirects site

rm -rf temp main.dSYM