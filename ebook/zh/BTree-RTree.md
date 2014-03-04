# 从B树、B+树、B\*树谈到R 树

作者：July、weedge、Frankie。编程艺术室出品。  
说明：本文从B树开始谈起，然后论述B+树、B\*树，最后谈到R 树。其中B树、B+树及B\*树部分由weedge完成，R 树部分由Frankie完成，全文最终由July统稿修订完成。  
出处：[http://blog.csdn.net/v_JULY_v](http://blog.csdn.net/v_JULY_v) 。

## 第一节、B树、B+树、B*树

#### 1.前言：

动态查找树主要有：二叉查找树（Binary Search Tree），平衡二叉查找树（Balanced Binary Search Tree），[红黑树](http://blog.csdn.net/v_JULY_v/article/category/774945)(Red-Black Tree )，B-tree/B+-tree/ B*-tree (B~Tree)。前三者是典型的二叉查找树结构，其查找的时间复杂度$$O(log_2N)$$与树的深度相关，那么降低树的深度自然会提高查找效率。









