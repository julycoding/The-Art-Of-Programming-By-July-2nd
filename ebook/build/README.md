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


##Bugs

*	when reading in ibooks, error reported in several chapter(Maybe due to informal format)
	*	第三十章：字符串转换成整数
	*	第三十一章：带通配符的字符串匹配问题
	*	第三十二章：最小操作数
	*	第三十三章：木块砌墙
	*	第三十五章：完美洗牌算法
	
	
##TODO
