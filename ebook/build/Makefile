BUILD = build
BOOKNAME = TAOP_July
METADATA = metadata.yaml
SRC_DIR = ../zh/
TOC = --toc --toc-depth=1
LATEX_CLASS = report
GHUSER = 
GHPASS = 

all: book

book: epub mobi html

epub: $(BUILD)/epub/$(BOOKNAME).epub

html: $(BUILD)/html/$(BOOKNAME).html

pdf: $(BUILD)/pdf/$(BOOKNAME).pdf

mobi: $(BUILD)/mobi/$(BOOKNAME).mobi

clean:
	rm -r $(BUILD)

#pandoc generate great TOC for epub, html, pdf
#so In this makefile, we will omit Readme.md
$(BUILD)/epub/$(BOOKNAME).epub: $(TITLE) 
	mkdir -p $(BUILD)/epub
	pandoc $(TOC) -S -o $@ $(METADATA) `ls $(SRC_DIR)*.md | grep "$(SRC_DIR)[0-9]"`

$(BUILD)/html/$(BOOKNAME).html:
	mkdir -p $(BUILD)/html
	cp -r ../images/ $(BUILD)/images
	cp TAOP.png $(BUILD)/html
	@tmpdir=`pwd`;\
		cd $(BUILD)/html;\
		mdtogh --css --user=$(GHUSER) --pass=$(GHPASS) --toc --toc_file=$$tmpdir/$(SRC_DIR)Readme.md --book=$$tmpdir/book.json --file_reg='^\d.+\.md$$' $$tmpdir/$(SRC_DIR);

$(BUILD)/pdf/$(BOOKNAME).pdf: $(TITLE)
	mkdir -p $(BUILD)/pdf
	pandoc $(TOC) --latex-engine=xelatex -V documentclass=$(LATEX_CLASS) -o $@ `ls $(SRC_DIR)*.md | grep "$(SRC_DIR)[0-9]"`

$(BUILD)/mobi/$(BOOKNAME).mobi: $(TITLE)
	mkdir -p build/mobi
	@if [ ! -e $(BUILD)/epub/$(BOOKNAME).epub ];\
		then \
		echo "make epub first"; \
		make epub ;\
		fi;
	@echo "generating mobi now"
	@ebook_convert_cmd=`which ebook-convert`; \
		if [ -z $$ebook_convert_cmd ]; \
		then \
		mac_osx_path='Applications/calibre.app/Contents/MacOS/ebook-convert';\
		ebook_convert_cmd=$$mac_osx_path;\
		fi;\
		if [ ! -e $$ebook_convert_cmd ];\
		then \
		echo "You need install calibre first!";\
		exit 1;\
		fi; \
		$$ebook_convert_cmd "$(BUILD)/epub/$(BOOKNAME).epub" "$(BUILD)/mobi/$(BOOKNAME).mobi" \
		--cover TAOP.png \
		--authors July \
		--level1-toc 'h1'\
		--language zh_CN ;

.PHONY: all book clean epub html pdf mobi
