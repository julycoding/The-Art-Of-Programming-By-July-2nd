## About

**July的新书《编程之法》纸质版在本github上的基础上做了极大彻底的改进、优化，无论是完整度、还是最新度、或质量上，都远非博客、github所能相比。换言之，新书《编程之法》的质量是博客、github质量的至少10倍。**

**此外，散落在网上其他任何地方的“编程之法”电子材料均是盗版自本github，更无质量可言。所以，July只唯一推荐《编程之法》纸质版。**

《编程之法》纸质版已于2015年10月14日陆续开卖！目前，京东、当当、亚马逊等各大网店均已有现货销售。
 - 京东：http://item.jd.com/11786791.html 。
 - 当当：http://product.dangdang.com/23796222.html 。
 - 亚马逊：[点击进入](http://www.amazon.cn/%E7%BC%96%E7%A8%8B%E4%B9%8B%E6%B3%95-%E9%9D%A2%E8%AF%95%E5%92%8C%E7%AE%97%E6%B3%95%E5%BF%83%E5%BE%97-July/dp/B016N0UUJG/ref=sr_1_1?ie=UTF8&qid=1445598929&sr=8-1&keywords=%E7%BC%96%E7%A8%8B%E4%B9%8B%E6%B3%95)。

看过[结构之法算法之道blog](http://blog.csdn.net/v_july_v)的朋友可能知道，从2010年10月起，[July](http://weibo.com/julyweibo) 开始整理一个微软面试100题的系列，他在整理这个系列的过程当中，越来越强烈的感觉到，可以从那100题中精选一些更为典型的题，每一题详细阐述成章，不断优化，于此，便成了程序员编程艺术系列。

原编程艺术系列从2011年4月至今，写了42个编程问题，在创作的过程当中，得到了很多朋友的支持，特别是博客上随时都会有朋友不断留言，或提出改进建议，或show出自己的思路、代码，或指正bug。为更好的改进、优化、增补编程艺术系列，特把博客上的这个**程序员编程艺术系列和博客内其它部分经典文章**同步到此，成立本项目。

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
 - 关于括号 
- 大括号另起一行
- 即便只有一行代码也加大括号
 - C 指针中的指针符靠近类型名，如写成int* p，而不写成int *p
 - 关于标点
- 中文表述，使用中文全角的标点符号，如：（）、。，？
- 数学公式（包括文中混排的公式）和英文代码，使用英文半角的标点符号，如：(),.?…
 - 关于注释
- 注释统一用中文
- 尽量统一用"//"，一般不用"/\*...\*/"
 - 关于命名
- 类名为大写字母开头的单词组合
- 函数名比较长，由多个单词组成的，每个单词的首字母大写，如int MaxSubArray()；函数名很短，由一个单词组成，首字母小写，比如int swap()
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
 - 专业术语
- 统一一律用“树结点”，而不是“树节点”。
- 用左子树、右子树表示树的左右子树没问题，但是否用左孩子、右孩子表示树或子树的左右结点？
 - ..
 - 此外，更多C++ 部分可参考Google C++ Style Guide，中文版见：http://zh-google-styleguide.readthedocs.org/en/latest/contents/ ；

有何问题或补充意见，咱们可以随时到这里讨论：https://github.com/julycoding/The-Art-Of-Programming-By-July/issues/81 。

## Ver Note
 - 2010年10月11日，在CSDN上正式开博，感谢博客上所有读者的访问、浏览、关注、支持、留言、评论、批评、指正；
 - 2011年1月，在学校的时候，第一家出版社联系出书，因“时机未到，尚需积累”的原因婉拒，随后第二家、第三家出版社陆续联系，因总感觉写书的时机还没到，一律婉拒；
 - 2011年10月， 当时在图灵教育的杨海玲老师（现在人民邮电信息技术分社）再度联系出书，再度认为“时机未到”；
 - 2014年1月18日，想通了一件事：如果什么都不去尝试，那么将年年一事无成，所以元旦一过，便正式确认今2014年之内要把拖了近3年之久的书出版出来；
 - 2013年12月-2014年3月，本github的Contributors 转移结构之法算法之道blog的部分经典文章到本github上，感谢这近100位Contributors，包括但不限于：
- Boshen（除我之外，贡献本github的次数最多）
- sallen450
- marchtea（专门为本github书稿弄了一个HTML网页）
- nateriver520（劝我把书稿放在github上，才有了本github）
 - 2014年3月，通读全部文章，修正明显错误，并邀请部分朋友review本github上的全部文章，包括cherry、王威扬、邬勇、高增琪、武博文、杨忠宝等；
 - 2014年4月
- 整个4月，精简篇幅，调整目录，Contributors 贡献其它语言代码，并翻译部分文章；
- 4月25日，跟人民邮电出版社信息技术分社签订合同，书名暂定《程序员编程艺术：面试和算法心得》，有更好的名字再替换。
 - 2014年5月，逐章逐节逐行逐字优化文字描述，测试重写优化每一段每一行每一个代码，确定代码基本风格；
 - 2014年6月
- 第一周，压缩篇幅，宁愿量少，但求质精；
- 第二周，全面 review；
- 第三周，本github的部分Contributors 把全部文章从github转到word上，这部分contributors 包括包括：zhou1989、qiwsir、DogK、x140yu、ericxk、zhanglin0129、idouba.net、gaohua、kelvinkuo等；
- 第四周，继续在Word 上做出最后彻底的改进，若未发现bug或pull request，本github将暂不再改动；
- 6月30日，与出版社约定的交稿日期延期，理由：目前版本不是所能做到的最好的版本。
 - 2014年7月，邀请部分好友进行第一轮审稿，包括曹鹏、邹伟、林奔、王婷、何欢，其中，曹鹏重写优化了部分代码。此外，葛立娜对书稿中的语言描述做了不少改进；
 - 2014年8月
- 8月上旬，新增KMP一节内容；
- 8月下旬，重点修改SVM一节内容；
 - 2014年9月
- 9月上旬，和一些朋友一起重绘稿件中的部分图和公式，这部分朋友包括顾运（@陈笙）、mastermay、在山东大学读研二的丰俊丙、厦门大学电子工程系陈友和等等；
- 9月下旬，再度邀请另一部分好友进行第二轮审稿，包括许利杰、王亮、陈赢、李祥老师、litaoye等，并在微博上公开征集部分读者审稿，包括李元超、刘琪等等；
 - 2014年10月
- 10月8日起，开始一章一章陆续交Word 稿给出版社初审
- 10月9日，第一章、字符串完成修改；
- 10月10日，第二章、数组完成修改；
- 10月22日，第三章、树完成修改；
 - 2014年11月
- 11月5日，第三章、树完成第二版修改，主要修正部分图片、公式、语言描述的错误；
 - 2014年12月
- 12月1日，第四章、查找完成修改。至此，前4 章的修改稿交付出版社。 
- 12月8日，第五章、动态规划完成修改，等出版社反馈中。一个人坚持有点枯燥。
- 12月31日，第六章仍未修改完。
 - 2015年1月
- 1月12日凌晨，第六章、海量数据处理完成修改，交付出版社。
 - 2015年4月
- 4月27日凌晨，交完第七章初稿，接下来编辑老师反馈，我修改审阅反馈稿。且书名由原来的《程序员编程艺术：面试和算法心得》暂时改为《编程之法：面试和算法心得》。
 - 2015年5月
- 5月2日，开始写书的前言，大致是：为何要写这本书，写的过程是怎样的；这是本什么书，有何特色，内容是什么，为什么这么写；写给谁看，怎么看更好。当然我还会加一些自己觉得比较个性化的内容。
- 5月5日，审阅完编辑老师的第一章反馈，并合并。
- 5月6日，审阅完第二章的一半。海玲姐两位老师给出了大量细致、详尽的修改建议，包括文字表述、语言表达、标点符号、字体格式、出版规范，尤其是正斜体、大小写、上下角。
- 5月15日，和海玲姐审完第一、二章，标点、术语、表述、逻辑、图片、代码等一切细节。书稿进入一审阶段。
 - 2015年6月
- 6月28日，经过反复修改、确认，书稿第一、二、三章基本定稿。 
 - 2015年7月
- 7月10日，书稿全部七章基本定稿，即将进入二审。
- 7月23日，补齐前言、封底、内容提要、邀请曹鹏、邹伟两位博士写推荐序，书稿进入二审，出版社重绘全部图片和公式。
 - 2015年8月
- 8月6日，三审结束。书稿取得阶段性的胜利。 
- 8月下旬，发稿审批。
 - 2015年9月
- 9月上旬，排版校对，出胶片、印刷、装订成书 
- 9月21日，几经易稿，终于敲定新书封面。
- 9月22日，开始印刷。
 - 2015年10月
- 进入10月份，万众期待的《编程之法》，终于终于要来了！
- 10月13日晚，终于拿到第一批样书。
- 10月14日下午三点半，我的新书《编程之法》终于在异步社区上首发开卖！
- 10月28日，新书正式上架京东。目前京东、当当、亚马逊等各大网店均已有现货销售。

## Contributors
感谢所有贡献的朋友：https://github.com/julycoding/The-Art-Of-Programming-by-July/graphs/contributors ，并非常期待你的加入，thanks。

同时，欢迎加入《编程之法》讨论交流QQ群：74631723，需要写验证信息。

孤军奋战的时代早已远去，我们只有团结起来，才能帮助到更多人。[@研究者July](http://weibo.com/julyweibo)，始于二零一三年十二月十四日。

## Copyright
本电子书的版权属于July 本人，严禁其他任何人出版，严禁用于任何商业用途，违者必究法律责任。July、二零一四年五月十一日晚。

## July' PDF
- 《支持向量机通俗导论（理解SVM的三层境界）》Latex排版精细版：http://vdisk.weibo.com/s/zrFL6OXKgnlcp ；Latex版本②：https://raw.githubusercontent.com/liuzheng712/Intro2SVM/master/Intro2SVM.pdf 。
- 原《程序员编程艺术第一~三十七章PDF》：http://download.csdn.net/detail/v_july_v/6694053 ，本github上的文章已经对此PDF进行了极大的优化和改进。
- 《微软面试100题系列之PDF》：http://download.csdn.net/detail/v_july_v/4583815
- 《十五个经典算法研究与总结之PDF》：http://download.csdn.net/detail/v_july_v/4478027
- 编程艺术HTML网页版：http://taop.marchtea.com/
- 2014年4月29日《武汉华科大第5次面试&算法讲座PPT》：http://pan.baidu.com/s/1hqh1E9e ；
- 新书初稿的4个PDF
 - B树的PDF：http://yun.baidu.com/s/1jGwup5k ；
 - 海量数据处理的PDF：http://yun.baidu.com/s/1dDreICL ；
 - 支持向量机的PDF：http://yun.baidu.com/s/1ntwof7j ；
 - KMP的PDF：http://yun.baidu.com/s/1eQel3PK ；
- 2014年9月3日西电第8次面试&算法讲座视频：http://v.youku.com/v_show/id_XNzc2MDYzNDg4.html ；PPT：http://pan.baidu.com/s/1pJ9HFqb ；
- 北京10月机器学习班的所有上课PPT：http://yun.baidu.com/share/home?uk=4214456744&view=share#category/type=0；
- 截止到2014年12月9日，结构之法算法之道blog所有155篇博文集锦CHM文件下载地址：http://pan.baidu.com/s/1gdrJndp ；
- 持续更新..
