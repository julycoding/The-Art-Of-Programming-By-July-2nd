
BUILD = build
BOOKNAME = TAOP_July
METADATA = metadata.yaml
SRC_DIR = ../zh/
#CHAPTERS = ch01.md ch02.md
TOC = --toc --toc-depth=2
LATEX_CLASS = report

all: book

book: epub html pdf

clean:
	rm -r $(BUILD)

epub: $(BUILD)/epub/$(BOOKNAME).epub

html: $(BUILD)/html/$(BOOKNAME).html

pdf: $(BUILD)/pdf/$(BOOKNAME).pdf

#pandoc generate great TOC for epub, html, pdf
#so In this makefile, we will omit Readme.md
$(BUILD)/epub/$(BOOKNAME).epub: $(TITLE) 
	mkdir -p $(BUILD)/epub
	pandoc $(TOC) -S -o $@ $(METADATA) `ls $(SRC_DIR)*.md | grep "$(SRC_DIR)[0-9]"`

$(BUILD)/html/$(BOOKNAME).html:
	mkdir -p $(BUILD)/html
	cp -r ../images/ $(BUILD)/images
	pandoc $(TOC) --standalone --to=html5 -o $@ `ls $(SRC_DIR)*.md | grep "$(SRC_DIR)[0-9]"`

$(BUILD)/pdf/$(BOOKNAME).pdf: $(TITLE)
	mkdir -p $(BUILD)/pdf
	pandoc $(TOC) --latex-engine=xelatex -V documentclass=$(LATEX_CLASS) -o $@ `ls $(SRC_DIR)*.md | grep "$(SRC_DIR)[0-9]"`

.PHONY: all book clean epub html pdf
