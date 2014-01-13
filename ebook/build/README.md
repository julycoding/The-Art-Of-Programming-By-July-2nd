#Build epub Books

##Requirement
*	pandoc

##Usage
*	chmod +x generate.sh

This will generate TAOP_July.epub for you.

##Notice

The script will **reset** your repo's status. Please **commit** before start generating.

注意: 这个脚本由于使用了`git reset`, 会重置你的库的状态.如果在生成前对库里的文件有任何的修改,请先`commit`提交后再调用生成脚本.

Reason for that:

*	some **image link** in .md file ended with **?raw=true**
*	while `pandoc` processing convert, it will **failed** to read such file
*	So, this script do some preprocess, remove all that tail of image link
*	After generation, `git reset` is performed to reset those files

原因:

*	有些图片在引用时的路径添加上了?raw=true
*	当pandoc处理时,其读取不到相应的文件,导致无法继承图片到图书中
*	为了解决这个问题,生成脚本做了一些预处理,删除掉了图片链接中的?raw=true
*	在生成后,脚本调用了`git reset`,来重置这些预处理


##Bugs
*	03.04.md
	* image lost in 03.04.md(because of img wrapped in \<img\>)
*	when reading in ibooks, error reported in several chapter(Maybe due to informal format)
	* 	第三章再续：快速选择SELECT算法的深入分析与实现
	*	第三章：寻找最小的 k 个数
	*	第三章：寻找最小的 k 个数
	*	第五章：寻找和为定值的两个或多个数
	*	第十一章：最长公共子序列（LCS）问题
	*	第二十二章：最短摘要的生成
	*	第二十六章：基于给定的文档生成倒排索引的编码与实践
	*	第二十八章：最大连续乘积子串
	*	第二十九章：字符串编辑距离
	*	第三十章：字符串转换成整数
	*	第三十一章：带通配符的字符串匹配问题
	*	第三十二章：最小操作数
	*	第三十三章：木块砌墙
	*	第三十五章：完美洗牌算法
	