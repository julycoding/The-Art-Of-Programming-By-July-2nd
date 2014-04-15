/**
 * Copyright (c) 2014 The TAOPP book Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be found 
 * in the LICENSE file.
 * 
 * 	Filename:	LCAProblem.c
 * 	Brief:		The C program for solving LCA problem
 * 	Version:	0.1
 * 	Created:	Tue Mar 18 21:25:58 2014
 * 
 * 	Author(s):	Liang Wang<fairywell28@yahoo.com>
 *          	eriol
 *          	July
 * 
 */

/** 
 * @brief 在二叉排序树中查找给定两个节点的LCA节点
 *
 * @author C version 0.1, 2014/3/18, Liang Wang<fairywell28@yahoo.com>
 *         C++ version 0.2, 2014, July
 *         C++ version 0.1, 2011, eriol 
 * @brief 在二叉排序树中查找给定两个节点的LCA节点
 *
 * @param root 该二叉排序树的根节点指针
 * @param u 给定节点一的指针
 * @param v 给定节点二的指针
 *
 * @return 找到LCA节点返回其指针；否则返回NULL
 */
Node* FindLowestCommonAncestorBst(Node* root, Node* u, Node* v)
{
    
    // 参数检查
    if (NULL == root || NULL == u || NULL == v) {
        fprintf(stderr, "Wrong input data! Exit!");
        return NULL;
    }
    
     if (root == u || root == v) {
         return root;
     }
     if (u == v) {
         return u;
     }
    
    //这段必须放在参数检查之后，不然有空指针异常
    
    int left_value = u->value;    
    int right_value = v->value;    
    Node* parent_node = NULL;
    Node* cur_node = root;
    

    // 调整左右节点值到正确
    if (left_value > right_value) {    
        swap(left_value, right_value);
    }    

    while (cur_node) {
        // 如果cur_node的值小于u、v的值，说明LCA节点应该在其右子树中
        if (cur_node->value < left_value) {    
            parent_node = cur_node;    
            cur_node = cur_node->right;    
        } else if (cur_node->value > right_value) {    
            // 如果cur_node的值大于u、v的值，则应该查询其左子树
            parent_node = cur_node;    
            cur_node = cur_node->left;    
        } else if (cur_node->value == left_value || cur_node->value == right_value) {
            // 找到节点u或者v处，说明其父节点即为所求
            return parent_node;
        } else {
            // 现在cur_node的值处于u和v的值之间，显然即为所求
            return cur_node;
        }    
    } 
    
    // 数据有误，找不到任何的LCA节点
    return NULL;
}

/** 
 * @brief 在二叉排序树中查找给定两个节点的LCA节点，递归版本
 *
 * @author C version 0.1, 2014/3/19, Liang Wang<fairywell28@yahoo.com> 
 *
 * @param root 该二叉排序树的根节点指针
 * @param u 给定节点一的指针
 * @param v 给定节点二的指针
 *
 * @return 找到LCA节点返回其指针；否则返回NULL
 */
Node* FindLcaBstRecursively(Node* root, Node* u, Node* v)
{
    // 参数检查
    // NOTICE:特别包含了u、v即是root节点的情况，此时应该返回NULL
    if (NULL == root || NULL == u || NULL == v
        || root == u || root == v || u == v) {
        fprintf(stderr, "Wrong input data: Arguments check failed! Exit!");
        return NULL;
    }
    
    int left_value = u->value;    
    int right_value = v->value;    

    // 调整左右节点值到正确
    if (left_value > right_value) {    
        swap(left_value, right_value);
    }    
    
    // 判断当前节点是否为所求LCA节点
    // 情形1：u、v分别在root的左右子树上
    if (root->value > left_value
        && root->value < right_value) {
        return root;
    }

    // 情形2：u、v都在root的同一棵子树且u、v有一个节点是root的子节点
    if (root->right == u || root->right == v
        || root->left == u || root->left == v) {
        return root;
    }

    // 当前节点不是所求LCA，则递归返回左右子树的LCA节点
    if (root->value < left_value) { // 查找右子树
        return FindLcaBstRecursively(root->right, u, v);
    } else if (root->value > right_value) { // 查找左子树
        return FindLcaBstRecursively(root->left, u, v);
    }
}
