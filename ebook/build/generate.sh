#!/bin/sh
#This script is for generating a epub book for you

#generate TOC to the begin of book
mv ../zh/Readme.md ../zh/00.0.md
echo "generating TAOP_July.epub"
pandoc -S  -o TAOP_July.epub metadata.yaml ../zh/*.md --highlight-style haddock
#after generation, change it back
mv ../zh/00.0.md ../zh/Readme.md
