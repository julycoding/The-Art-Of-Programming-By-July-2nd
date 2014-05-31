REBOL [
       Title: "判断a字符串是否包含b字符串的字母 假定都没有重复字符出现"
       Date: 2014-04-06
       File:  %1.2：字符串是否包含问题.reb
       Author: "network061(yping061@gmail.com)"
       Version: 1.0.0
]

contain1: func[
                "暴力轮询"
                stra [ string! ] 
                strb [ string! ]
                /local index-a index-b  ;分别用于轮询stra、strb
][
    index-a: index-b: 1
    while [ index-b <= length? strb] [
        while [ 
            all [  stra/:index-a != strb/:index-b index-a <= length? stra ]  
         ] [
            ++ index-a
        ]
        either index-a > length? stra [
            return false
        ] [
             index-a: 1
             ++ index-b
        ]
    ]
    return true
]

contain2: func[
                "排序比较"
                stra [ string! ] 
                strb [ string! ]
                /local index-a index-b  ;分别用于轮询stra、strb
][
    sort stra
    sort strb
    
    index-a: index-b: 1
    while [ index-b <= length? strb] [
        while [ 
            all [ stra/:index-a < strb/:index-b index-a <= length?  stra ]  
         ] [
            ++ index-a
        ]
        either any [ index-a > length? stra  stra/:index-a > strb/:index-b ] [
            return false
        ] [
             index-a: 1
             ++ index-b
        ]
    ]
    return true
]

contain3: func[
                "计数排序 只针对大写字母。"
                stra [ string! ] 
                strb [ string! ]
                /local index-a index-b index-have have  char_to_int  
                ;index-a、index-b、index-have分别用于轮询stra、strb、数组have
                ;have 声明数组 char_to_int 把字符转化为数字
][
   have: array 26 /initial 0
   index-a: index-b: 1
   while [ index-a <= length? stra] [
        char_to_int: to-integer to-char stra/:index-a
        index-have: char_to_int - 65 + 1  ;整数索引从1开始
        have/:index-have: 1 ;将stra中的字符按字母表相应位置置1
        ++ index-a
   ]
   while [ index-b <= length? strb ] [
        char_to_int: to-integer to-char strb/:index-b
        index-have: char_to_int - 65 + 1
        if not have/:index-have   [ return false ] ;利用not  把不是逻辑的none转化为true
        ++ index-b
   ]
    return true
]

contain4: func[
                "hash测试法"
                stra [ string! ] 
                strb [ string! ]
                /local index-a index-b index-hash hash  char_to_int count 
                ;index-a、index-b、index-hash分别用于轮询stra、strb、数组hash
                ;hash 声明数组 char_to_int 把字符转化为数字 count用于统计hash中1的个数
][
   hash: array 26 /initial 0
   index-a: index-b: 1
   count: length? strb
   while [ index-b <= length? strb] [
        char_to_int: to-integer to-char strb/:index-b
        index-hash: char_to_int - 65 + 1  ;整数索引从1开始
        hash/:index-hash: 1                      ;将stra中的字符按字母表相应位置置1
        ++ index-b
   ]
   while [ all [ index-a <= length? stra  count > 0 ] ] [
        char_to_int: to-integer to-char stra/:index-a
        index-hash: char_to_int - 65 + 1
        unless not not hash/:index-hash [ -- count ]
        ++ index-a
   ]
   return count = 0 
]

contain5: func[
                "素数相乘,此方法只有理论意义, 因为整数乘积很大, 有溢出风险。"
                stra [ string! ] 
                strb [ string! ]
                /local index-a index-b index-prime arrPrime  char_to_int bigNumber  
                ;index-a、index-b、index-prime分别用于轮询stra、strb、数组arrPrime
                ;arrPrime 声明数组 char_to_int 把字符转化为数字 
                ;bigNumber arrPrime中所有素数的乘积
][
        arrPrime: [ 2  3  5  7  11  13  17  19  23  29  31  37  41  43  47  53  59 61  67  71  73  79  83  89  97  101 ]
        index-a: index-b: bigNumber: 1
        while [ index-a <= length? stra ] [
            char_to_int: to-integer to-char stra/:index-a
            index-prime: char_to_int - 65 + 1
            print bigNumber 
            bigNumber: bigNumber * arrPrime/:index-prime
            ++ index-a
        ]
        while [ index-b <= length? strb] [
            char_to_int: to-integer to-char strb/:index-b
            index-prime: char_to_int - 65 + 1
            either 0 != remainder bigNumber arrPrime/:index-prime [
                       ++ index-b 
            ] [
                       return false 
            ]
        ]
        return true
]

contain6: func[
                "位运算,实质上把hash测试法对应的数组用一个整数代替。"
                stra [ string! ] 
                strb [ string! ]
                /local index-a index-b index-bit bitsetA  char_to_int  
                ;index-a、index-b、index-bit分别用于轮询stra、strb、bitsetA
                ;bitsetA,用于表示stra中各字符的"签名" char_to_int 把字符转化为数字
][
   bitsetA: to-bitset to-binary 0
   index-a: index-b: 1
   while [ index-a <= length? stra ] [
        char_to_int: to-integer to-char stra/:index-a 
        index-bit: char_to_int - 65              ;由于下面将用到位运算,故索引从0开始
        bitsetA: bitsetA | to-bitset to-binary shift 1 index-bit
        ++ index-a
   ]
   while [ index-b <= length? strb ] [
       char_to_int: to-integer to-char strb/:index-b
       index-bit: char_to_int - 65 
       if 0 = to-integer to-binary bitsetA & to-bitset to-binary shift 1 index-bit [ return false ]
       ++ index-b
   ]
   return true
]

stra: "ABCDEFGHLMNOPQRS"
strb: "DCGSRQPO"
print [ "stra:" stra  ]
print [ "strb:" strb ] 
print [ "暴力轮询 :"  either contain1 stra strb [ "stra contains strb "] [ "stra not contains strb "] ]
print [ "排序比较 :"  either contain2 stra strb [ "stra contains strb "] [ "stra not contains strb "] ]
print [ "计数比较 :"  either contain3 stra strb [ "stra contains strb "] [ "stra not contains strb "] ]
print [ "hash测试 :"  either contain4 stra strb [ "stra contains strb "] [ "stra not contains strb "] ]
;素数相乘因溢出问题只给出实现代码,没有测试代码
print [ "位运算 :"  either contain6 stra strb [ "stra contains strb "] [ "stra not contains strb "] ]

