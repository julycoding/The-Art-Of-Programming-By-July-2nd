#!/bin/sh
##preprocess
##as all links of image are ended by ?raw=true, which make pandoc failed to read image,
##this would deal with it
echo "preprocessing files"
sed -i "" -e 's/!\[\](\(.*\)\?raw=[a-z]*\(.*\))/![](\1\2)/g' -e 's/!\[\](\(.*\)\?raw=[a-z]*\(.*\))/![](\1\2)/g' ../zh/*.md
echo "generating TAOP_July.epub"
pandoc -S  -o TAOP_July.epub metadata.yaml ../zh/*.md --highlight-style haddock
echo "reverse changes"
git reset --hard
