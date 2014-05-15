#Build Ebooks

##Requirement
*	[pandoc](http://johnmacfarlane.net/pandoc/)
*	[mdtogh](https://github.com/marchtea/mdtogh)
*	git
*	make(OS X users should install XCode command line tools(xcode-select --install)
*	latex (OS X users can use [MacTex](http://www.tug.org/mactex/morepackages.html).)
*	[calibre](http://calibre-ebook.com)(For mobi)

##Usage

Now scripts support three format generation:

*	epub
*	html
*	mobi([calibre](http://www.calibre-ebook.com/) is needed with its command line tools installed)

To make all three format, use `make`.

To make specific format, use `make (format)`, e: `make epub`
	
##TODO

*	pdf support