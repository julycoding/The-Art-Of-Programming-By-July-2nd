package org.yousharp.julycoding.string;

/**
 * 1.2 字符串包含
 * (july github链接：https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/01.02.md)
 *
 * User: lingguo
 * Date: 14-6-29
 */
public class StringContain {

    /**
     *  * 问题描述：
     *  给定两个分别由字母组成的字符串A和字符串B，字符串B的长度比字符串A短。请问，如何最快地判断字符串B
     *  中所有字母是否都在字符串A里？为了简单起见，我们规定输入的字符串只包含大写英文字母。比如String A：ABCD，String B：BAD，
     *  返回true；string A：ABCD，string B：BCE，返回false；String A：ABCD，String B：AA，返回true。
     *
     * 思路：
     *  思路一：遍历字符串B，判断每一个字符是否出现在字符串A中，时间复杂度O(n*m)，空间复杂度O(1);
     *  思路二：先对两个字符串排序，然后同时遍历字符串A和B，判断B中的每一个字符是否都在字符串A中。时间复杂度O(nlogn)，空间复杂度O(1)；
     *  思路三：将每一个字符映射到一个素数上，对字符串A中的每一个字符表示的素数，求累积；然后遍历字符串B，用每一个字符表示的素
     *  数去除字符串A的累积，判断余数是否为0。时间复杂度：O(n)，空间复杂度O(1)。可能存在的问题：乘积时可能会溢出。
     *  思路四：如果可以使用Java中的数据结构，HashMap和Set可以很方便地解决问题；如果不能，我们可以构造一个“签名”，将每一个字
     *  符映射为整数(范围：0到26)，然后遍历A中的每一个字符，将32位整数的对应位置1(整数初始为0)，最后遍历B中的每一个字符，判断
     *  每一个字符代表的整数在整数中是否已置位。时间复杂度O(n)，空间复杂度O(1)，思路四为最优算法。
     *
     *  这里仅给出思路四的示例代码。
     *
     * @param s1
     * @param s2
     * @return
     */
    public static boolean hashCheck(char[] s1, char[] s2) {
        int mask = 0;
        for (char c: s1) {
            mask = mask | (1 << (c - 'A'));
        }
        for (char c: s2) {
            if ((mask & (1 << (c - 'A'))) == 0) {
                return false;
            }
        }
        return true;
    }
}
