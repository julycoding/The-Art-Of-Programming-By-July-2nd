## About

看过[结构之法算法之道blog](http://blog.csdn.net/v_july_v)的朋友可能知道，从2010年10月起，[July](http://weibo.com/julyweibo) 开始整理一个微软面试100题的系列，他在整理这个系列的过程当中，越来越强烈的感觉到，可以从那100题中精选一些更为典型的题，每一题详细阐述成章，不断优化，于此，便成了程序员编程艺术系列。

原编程艺术系列从2011年4月至今，写了42个编程问题，在创作的过程当中，得到了很多朋友的支持，特别是博客上随时都会有朋友不断留言，或提出改进建议，或show出自己的思路、代码，或指正bug。

为了方便大家更好的改进、优化、增补编程艺术系列，特把博客上的这个**程序员编程艺术系列和博客内其它部分经典文章**同步到此，成立本项目「Csdn 600万博客结构之法算法之道部分经典博文优化版：《程序员编程艺术 — 面试和算法心得》」，邀请各位一起修正和优化。

若发现任何问题、错误、bug，或可以优化的每一段代码，欢迎随时pull request或发issue反馈，thanks。

## Start Reading
 * [中文目录](ebook/zh/Readme.md) Enhancement in progress
 * [English Contents](ebook/en/Readme.md) Translation in progress


## How To Contribute
 * 邀请大家帮忙把github上的文章导出到word上，欢迎到这里认领：https://github.com/julycoding/The-Art-Of-Programming-By-July/issues/337 」
 * 一章一章的测试所有代码，指正 bug，修正错误。 「必选，可到这里认领：https://github.com/julycoding/The-Art-Of-Programming-By-July/issues/210 」
 * 优化原文章上的C/C++ 代码，优化后的代码可以放到[ebook/code](ebook/code/)文件夹内，并注意代码命名规范的问题：https://github.com/julycoding/The-Art-Of-Programming-By-July/issues/234 。 「必选」
 * 添加其它语言如Java、python、go 的代码，放在[ebook/code](ebook/code/)文件夹内，同样如上，注意代码命名规范的问题。 「可选」
 * 重绘所有的图片：https://github.com/julycoding/The-Art-Of-Programming-by-July/issues/80
 * 翻译成英文版，参考[中文目录](ebook/zh/Readme.md)，把翻译后的文章编辑到这[English Version](ebook/en/Readme.md),注：不必逐字翻译，精简大气即可（如有兴趣翻译，请到这里领取感兴趣的章节翻译：https://github.com/julycoding/The-Art-Of-Programming-by-July/issues/84 )
 * 自己主导续写新的章节；
 * 任何你想做的事情，包括痛批你觉得写的烂的章节，所有你的意见都将改进此系列。

你可以做以上任何一件或几件事情，如遇到任何问题或疑惑，咱们可以随时讨论：
<https://github.com/julycoding/The-Art-Of-Programming-by-July/issues?state=open>。
「如不知如何在github上提交及同步作者的更新，可参考此文：http://www.cnblogs.com/rubylouvre/archive/2013/01/24/2874694.html 」

## Code Style
本项目暂约定以下代码风格(不断逐条添加中)：
 - 关于空格
- 所有代码使用4个空格缩进
- 运算符后使用一个空格
- "," 和for循环语句中的";" 后面跟上一个空格
- 条件、分支保留字，如 if for while else switch 后留出一个空格
- "[]", "."和"->" 前后不留空格
 - 用空行把大块代码分成逻辑上的“段落
 - C 指针中的指针符靠近类型名，如写成int* p，而不写成int *p
 - 关于标点
- 中文表述，使用中文全角的标点符号，如：（）、。，？
- 数学公式（包括文中混排的公式）和英文代码，使用英文半角的标点符号，如：(),.?…
 - 关于注释
- 注释统一用中文
- 尽量统一用"//"，一般不用"/\*...\*/"
 - 关于命名
- 类名为大写字母开头的单词组合
- 函数名比较长，由多个单词组成的，每个单词的首字母大写，如MaxSubArray；函数名很短，由一个单词组成，首字母小写，比如swap
- 变量名比较长，由多个单词组成的，首个单词的首字母小写，后面紧跟单词的首字母大写，如maxEnd；变量名很短，由一个单词组成，首字母小写，如left
- 变量尽量使用全名，能够描述所要实现的功能，如 highestTemprature；对于已经公认了的写法才使用缩写，如 tmp mid prev next
- 变量名能“望文生义”，如v1, v2不如area, height
- 常量的命名都是大写字母的单词，之间用下划线隔开，比如MY_CONSTANT
- il < 4384 和 inputLength < MAX_INPUT_LENGTH，后一种写法更好
 - 一个函数只专注做一件事
 - 时间复杂度小写表示，如O(nlogn)，而不写成O(N*logN)
 - 正文中绝大部分采用C实现，少量C++代码，即以C为主，但不去刻意排斥回避C++；
 - 关于的地得
- 形容词（代词） + 的 + 名词，例如：我的小苹果
- 副词 + 地 + 动词，例如：慢慢地走
- 动词 + 得 + 副词，例如：走得很快
 - 关于参考文献
- 格式：主要责任者.书名〔文献类型标识 ] .其他责任者.版本.出版地：出版者，出版年.文献数量.丛编项.附注项.文献标准编号。例子：1 刘少奇.论共产党员的修养.修订 2 版.北京：人民出版社，1962.76 页.
 - ..
 - 此外，更多C++ 部分可参考Google C++ Style Guide，中文版见：http://zh-google-styleguide.readthedocs.org/en/latest/contents/ ；

有何问题或补充意见，咱们可以随时到这里讨论：https://github.com/julycoding/The-Art-Of-Programming-By-July/issues/81 。

## Ver Note
 - 2013年12月-2014年3月，Contributors 转移结构之法算法之道blog部分经典文章到本github上；
 - 2014年3月，通读全部文章，修正明显错误；
 - 2014年4月，精简篇幅，调整目录，Contributors 贡献其它语言代码，并翻译部分文章；
 - 2014年5月，逐章逐节逐行逐字优化文字描述，测试重写优化每一段每一行每一个代码，确定代码基本风格；
 - 2014年6月，第一周，压缩篇幅，宁愿量少，但求质精；第二周，全面 review；第三周，全部文章从github转到word上，在word 上做出最后彻底的改进，若未发现bug或pull request，github将暂不再改动；第四周，最后一周review；
- 实际情况：6月30日，稿件延期，理由：目前版本不是所能做到的最好的版本。
 - 2014年7月，出版社重绘全部图片，编辑加工，复审，三审；
- 实际情况：7月1日交付初稿，上半个月再交一版本，择期交定稿 
 - 2014年8月，发稿审批，排版校对；
- 实际情况：稿件预计最快8月底交付出版社。
 - 2014年9月，出胶片，印刷，装订成书；
 - 2014年10月..
 - 2014年11月...


## Contributors
感谢所有贡献的朋友：https://github.com/julycoding/The-Art-Of-Programming-by-July/graphs/contributors ，并非常期待你的加入，thanks。

同时，欢迎所有已经贡献过本github的95位朋友加入程序员编程艺术室QQ群：149638123，验证信息为你贡献本项目时用的github昵称。

孤军奋战的时代早已远去，我们只有团结起来，才能帮助到更多人。[@研究者July](http://weibo.com/julyweibo)，始于二零一三年十二月十四日。

## Copyright
本电子书的版权属于July 本人，严禁其他任何人出版，严禁用于任何商业用途，违者必究法律责任。July、二零一四年五月十一日晚。

## July' PDF
* 《支持向量机通俗导论（理解SVM的三层境界）》Latex排版精细版：http://vdisk.weibo.com/s/zrFL6OXKgnlcp ；Latex版本②：https://raw.githubusercontent.com/liuzheng712/Intro2SVM/master/Intro2SVM.pdf 。
* 原《程序员编程艺术第一~三十七章PDF》：http://download.csdn.net/detail/v_july_v/6694053 ，本github上的文章已经对此PDF进行了极大的优化和改进。
* 《微软面试100题系列之PDF》：http://download.csdn.net/detail/v_july_v/4583815
* 《十五个经典算法研究与总结之PDF》：http://download.csdn.net/detail/v_july_v/4478027
* 编程艺术HTML网页版：http://taop.marchtea.com/
* 2014年4月29日《武汉华科大第5次面试&算法讲座PPT》：http://pan.baidu.com/s/1hqh1E9e ；
* 持续更新..
