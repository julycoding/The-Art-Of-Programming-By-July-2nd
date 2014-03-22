#include <iostream>

using namespace std;

/* brute force */
void leftShiftOne(string &str) 
{
    int n = str.length();
    if (n < 2) return; // args check
    char t = str[0];  //保存第一个字符
    for (int i = 1; i < n; ++i) 
    {
        str[i - 1] = str[i];
    }
    str[n - 1] = t;
}

void rotate_1(string &str, int m) 
{
    while (m--) 
    {
        leftShiftOne(str);
    }
}

/* pointer manipulation part 1 */
void rotate_2(string &str, int m)
{

    if (str.length() == 0 || m <= 0)
        return;

    int n = str.length();

    if (m % n <= 0)
        return;

    int p1 = 0, p2 = m;
    int k = (n - m) - n % m;

    // 交换p1，p2指向的元素，然后移动p1，p2
    while (k --)
    {
        swap(str[p1], str[p2]);
        p1++;
        p2++;
    }

    // 处理尾部，r为尾部左移次数
    int r = n - p2;
    while (r--)
    {
        int i = p2;
        while (i > p1)
        {
            swap(str[i], str[i-1]);
            i--;
        }
        p2++;
        p1++;
    }
}

/* pointer manipulation part 2 */
void rotate_3(string &str, int m)
{
    if (str.length() == 0 || m < 0)
        return;

    //初始化p1，p2
    int p1 = 0, p2 = m;
    int n = str.length();

    // 处理m大于n
    if (m > n)
        return;

    // 循环直至p2到达字符串末尾
    while(true)
    {
        swap(str[p1], str[p2]);
        p1++;
        if (p2 < n - 1)
            p2++;
        else
            break;
    }

    // 处理尾部，r为尾部循环左移次数
    int r = m - n % m;
    while (r--) //外循环执行一次
    {
        int i = p1;
        char temp = str[p1];
        while (i < p2) //内循环执行俩次
        {
            str[i] = str[i+1];
            i++;
        }
        str[p2] = temp;
    }
}

/* pointer manipulation part 3 */
/*
 *左旋字符串str，m为负数时表示右旋abs（m）个字母
 */
void rotate_4(string &str, int m) 
{
    if (str.length() == 0)
        return;

    int n = str.length();

    //处理大于str长度及m为负数的情况,positiveMod可以取得m为负数时对n取余得到正数
#define positiveMod(m, n) ((m) % (n) + (n)) % (n)
    m = positiveMod(m, n);
    if (m == 0)
        return;

    int p1 = 0, p2 = m;
    int round;

    //p2当前所指和之后的m-1个字母共m个字母，就可以和p2前面的m个字母交换。
    while (p2 + m - 1 < n) 
    {
        round = m;
        while (round--)
        {
            swap(str[p1], str[p2]);
            p1++;
            p2++;
        }
    }

    //剩下的不足m个字母逐个交换
    int r = n - p2;
    while (r--)
    {
        int i = p2;
        while (i > p1) 
        {
            swap(str[i], str[i - 1]);
            i--;
        }
        p2++;
        p1++;
    }
}

/* recursion */
void rotate_5(string &str, int n, int m, int head, int tail, bool flag)
{
    //n 待处理部分的字符串长度，m：待处理部分的旋转长度
    //head：待处理部分的头指针，tail：待处理部分的尾指针
    //flag = true进行左旋，flag = false进行右旋

    // 返回条件
    if (head == tail || m <= 0)
        return;

    if (flag == true)
    {
        int p1 = head;
        int p2 = head + m;  //初始化p1，p2

        //1、左旋：对于字符串abc def ghi gk，
        //将abc右移到def ghi gk后面，此时n = 11，m = 3，m’ = n % m = 2;
        //abc def ghi gk -> def ghi abc gk

        int k = (n - m) - n % m;   //p1，p2移动距离，向右移六步

        for (int i = 0; i < k; i++, p1++, p2++)
            swap(str[p1], str[p2]);

        rotate_5(str, n - k, n % m, p1, tail, false);  //flag标志变为false，结束左旋，下面，进入右旋
    }
    else
    {
        //2、右旋：问题变成gk左移到abc前面，此时n = m’ + m = 5，m = 2，m’ = n % m 1;
        //abc gk -> a gk bc

        int p1 = tail;
        int p2 = tail - m;

        // p1，p2移动距离，向左移俩步
        int k = (n - m) - n % m;

        for (int i = 0; i < k; i++, p1--, p2--)
            swap(str[p1], str[p2]);

        rotate_5(str, n - k, n % m, head, p1, true);  //再次进入上面的左旋部分，
        //3、左旋：问题变成a右移到gk后面，此时n = m’ + m = 3，m = 1，m’ = n % m = 0;
        //a gk bc-> gk a bc。 由于此刻，n % m = 0，满足结束条件，返回结果。
    }
}

/* using gcd */

//所有序号为 (j+i *m) % n (j 表示每个循环链起始位置，i 为计数变量，m表示左旋转位数，n表示字符串长度)，
//会构成一个循环链（共有gcd(n,m)个，gcd为n、m的最大公约数），

//每个循环链上的元素只要移动一个位置即可，最后整个过程总共交换了n次
//（每一次循环链，是交换n/gcd(n,m)次，共有gcd(n,m)个循环链，所以，总共交换n次）。

int gcd (int m, int n)
{
    int c;
    while ( m != 0 ) 
    {
        c = m; 
        m = n % m;  
        n = c;
    }
    return n;
}

void rotate_6(string &str, int m)
{
    int lenOfStr = str.length();
    int numOfGroup = gcd(lenOfStr, m);
    int elemInSub = lenOfStr / numOfGroup;

    for(int j = 0; j < numOfGroup; j++)
        //对应上面的文字描述，外循环次数j为循环链的个数，即gcd(n, m)个循环链
    {
        char tmp = str[j];
        int i;
        for (i = 0; i < elemInSub - 1; i++)
            //内循环次数i为，每个循环链上的元素个数，n/gcd(m,n)次
            str[(j + i * m) % lenOfStr] = str[(j + (i + 1) * m) % lenOfStr];
        str[(j + i * m) % lenOfStr] = tmp;
    }
}

//对上述方案4的改写。
//④ 所有序号为 (i+t*k) % n (i为指定整数，t为任意整数)，....
//copyright@ hplonline && July 2011.04.18。
//July、sahala、yansha，updated，2011.06.02。
void rotate_7(char *begin, char *mid, char *end)
{
    int n = end - begin;
    int k = mid - begin;
    int d = gcd(n, k);
    int i, j;
    for (i = 0; i < d; i ++)
    {
        int tmp = begin[i];
        int last = i;

        //i+k为i右移k的位置，%n是当i+k>n时从左重新开始。
        for (j = (i + k) % n; j != i; j = (j + k) % n)    //多谢laocpp指正。
        {
            begin[last] = begin[j];
            last = j;
        }
        begin[last] = tmp;
    }
}

/* 3 step rotation */
//Copyright@ 小桥流水 && July
//c代码实现，已测试正确。
//July、updated，2011.04.17。
char *invert(char *start, char *end)
{
    char tmp, *ptmp = start;
    while (start != NULL && end != NULL && start < end)
    {
        tmp = *start;
        *start = *end;
        *end = tmp;
        start ++;
        end --;
    }
    return ptmp;
}

char *rotate_8(char *s, int len, int pos)   //pos为要旋转的字符个数，或长度，下面主函数测试中，pos=3。
{
    invert(s, s + (pos - 1));  //如上，X->X^T，即 abc->cba
    invert(s + pos, s + (len - 1)); //如上，Y->Y^T，即 def->fed
    invert(s, s + (len - 1));  //如上，整个翻转，(X^TY^T)^T=YX，即 cbafed->defabc。
    return s;
}

int main () {

    string s;
    int shift = 3;

    s = "abcdefghi";
    cout << "testing rotate_1" << endl;
    cout << "before shift: " << s << endl;
    rotate_1(s, shift);
    cout << "after  shift: " << s << endl << endl;

    s = "abcdefghi";
    cout << "testing rotate_2" << endl;
    cout << "before shift: " << s << endl;
    rotate_2(s, shift);
    cout << "after  shift: " << s << endl << endl;

    s = "abcdefghi";
    cout << "testing rotate_3" << endl;
    cout << "before shift: " << s << endl;
    rotate_3(s, shift);
    cout << "after  shift: " << s << endl << endl;

    s = "abcdefghi";
    cout << "testing rotate_4" << endl;
    cout << "before shift: " << s << endl;
    rotate_4(s, shift);
    cout << "after  shift: " << s << endl << endl;

    s = "abcdefghi";
    cout << "testing rotate_4 (shift right)" << endl;
    cout << "before shift: " << s << endl;
    rotate_4(s, -3);
    cout << "after  shift: " << s << endl << endl;

    s = "abcdefghi";
    cout << "testing rotate_5" << endl;
    cout << "before shift: " << s << endl;
    rotate_5(s, s.length(), shift, 0, s.length() - 1, true);
    cout << "after  shift: " << s << endl << endl;

    s = "abcdefghi";
    cout << "testing rotate_5 (shift right)" << endl;
    cout << "before shift: " << s << endl;
    rotate_5(s, s.length(), shift, 0, s.length() - 1, false);
    cout << "after  shift: " << s << endl << endl;

    s = "abcdefghi";
    cout << "testing rotate_6" << endl;
    cout << "before shift: " << s << endl;
    rotate_6(s, shift);
    cout << "after  shift: " << s << endl << endl;

    char str1[] = "abcdefghi";
    cout << "testing rotate_7" << endl;
    cout << "before shift: " << str1 << endl;
    rotate_7(&str1[0], &str1[shift], &str1[9]);
    cout << "after  shift: " << str1 << endl << endl;

    char str2[] = "abcdefghi";
    cout << "testing rotate_8" << endl;
    cout << "before shift: " << str2 << endl;
    cout << "after  shift: " << rotate_8(str2, 9, shift) << endl;

    return 0;
}
