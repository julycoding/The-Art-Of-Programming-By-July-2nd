#Build epub Books

##Requirement
*	pandoc
*	git
*	make(OS X users should install XCode command line tools(xcode-select --install)
*	latex (OS X users should probably install MacTex.)
*	calibre(For mobi)

##Usage

Now scripts support three format generation:

*	epub
*	html
*	pdf(need latex support)
*	mobi([calibre](http://www.calibre-ebook.com/) is needed, and install command line tools)

To make all three format, use `make`.

To make specific format, use `make (format)`, e: `make epub`
	
##TODO
