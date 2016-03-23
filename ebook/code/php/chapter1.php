<?php

function LeftShiftOne($string){
    assert("is_string('$string')");
    $len = mb_strlen($string,'utf-8');
    return mb_substr($string,1,$len,'utf-8') . mb_substr($string,0,1,'utf-8');
}

function LeftShiftString($string,$m){
    assert("is_string('$string')");
    assert("is_int($m)");
    $len = mb_strlen($string,'utf-8');
    $m %= $len;                 //求余数，减少移动长度大于字符串长度时的比较次数
    $m = $m<0 ? $m+$len : $m;   //防止输入为负数导致while死循环
    while($m--){
        $string = LeftShiftOne($string);
    }
    return $string;
}

function reverse($string){
    assert("is_string('$string')");
    return strrev($string);
}

function LeftRotateString($string,$m){
    assert("is_string('$string')");
    assert("is_int($m)");
    $len = mb_strlen($string,'utf-8');
    $m %= $len;   //求余数，减少移动长度大于字符串长度时的比较次数
    $head = reverse(mb_substr($string , 0  , $m   , 'utf-8')); //反转[0..m - 1]，套用到上面举的例子中，就是X->X^T，即 abc->cba
    $tail = reverse(mb_substr($string , $m , $len , 'utf-8')); //反转[m..n - 1]，例如Y->Y^T，即            def->fed
    return reverse($head.$tail);                               //反转[0..n - 1]，即如整个反转，(X^TY^T)^T=YX，即 cbafed->defabc
}

//"暴力移位法"测试用例
function LeftShiftTest($str){
    var_dump(LeftShiftString($str , 0));
    var_dump(LeftShiftString($str , 1));
    var_dump(LeftShiftString($str , 6));
    var_dump(LeftShiftString($str , 7));
    var_dump(LeftShiftString($str , -1));
    var_dump(LeftShiftString($str , -6));
    var_dump(LeftShiftString($str , -7));
}

//"三步反转法"测试用例
function LeftRotateTest($str){
    var_dump(LeftRotateString($str , 0));
    var_dump(LeftRotateString($str , 1));
    var_dump(LeftRotateString($str , 6));
    var_dump(LeftRotateString($str , 7));
    var_dump(LeftRotateString($str , -1));
    var_dump(LeftRotateString($str , -6));
    var_dump(LeftRotateString($str , -7));
}

//基本测试用例
$str = "abcdef";
LeftShiftTest($str);
LeftRotateString($str);
//中文utf8测试用例
$str = "一二三四五六";
LeftShiftTest($str);
LeftRotateString($str);
