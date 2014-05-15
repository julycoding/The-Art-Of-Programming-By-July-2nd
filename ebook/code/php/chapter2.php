<?php
/**
 * 解法一、暴力轮询 
 *
 **/
function compare_1($a,$b){
    assert("is_string('$a')");
    assert("is_string('$b')");
    $a_ary = str_split($a);
    $b_ary = str_split($b);
    for ($i = 0; $i < count($b_ary); $i++){
        $j = 0;
         for (; $j < count($a_ary) && ($a_ary[$j] != $b_ary[$i]) ; $j++){
            //pass
         }
         if($j >= count($a_ary)){
            return false;
         }
    }
    return true;
}

/**
 * 解法二、普通排序 
 *
 **/
function compare_2($a,$b){
    assert("is_string('$a')");
    assert("is_string('$b')");
    $a_ary = str_split($a);
    $b_ary = str_split($b);
    sort($a_ary);
    sort($b_ary);
    for ($i = 0, $j =0; $j < count($b_ary); ) {
         while(($i < count($a_ary)) && ($a_ary[$i] < $b_ary[$j])){
            $i++;
         }
         if(($i >= count($a_ary)) || ($a_ary[$i] > $b_ary[$j])){
            return false;
         }
         $j++;
    }
    return true;
}

/**
 * 解法三、计数比较 
 *
 **/
function compare_3($a,$b){
    assert("is_string('$a')");
    assert("is_string('$b')");
    $a_ary = str_split($a);
    $b_ary = str_split($b);
    $have = array_fill(0,26,0);
    $ordA = ord('A');
    for ($i = 0; $i < count($a_ary); $i++) {
        $loca =  (ord($a_ary[$i]) - $ordA);
        $have[$loca]++;
    }
    for ($i = 0; $i < count($b_ary); $i++) {
        $loca =  (ord($b_ary[$i]) - $ordA);
        if($have[$loca] == 0){
            return false;
        }
        //若A中需要包含B中所有重复出现字符
        //即A：AAACCDBBCCE    B：AABBCC 合法
        //即A：BCDEFA B：AABBCC 非法
        //if ($have[$loca]-- == 0) {
        //  return false;
        //}
    }
    return true;
}

/**
 * 解法四、巧用hashtable 
 *
 **/
function compare_4($a,$b){
    assert("is_string('$a')");
    assert("is_string('$b')");
    $a_ary = str_split($a);
    $b_ary = str_split($b);
    $hash = array_fill(0,26,0);
    $ordA = ord('A');
    for ($i = 0; $i < count($b_ary); $i++) {
        $x = ord($b_ary[$i]) - $ordA;
        if ($hash[$x] == 0) {
            $hash[$x] = 1;
            $m++;
        }
    }
    for ($i = 0; $i < count($a_ary); $i++) {
        $x = ord($a_ary[$i]) - $ordA;
        if($hash[$x] == 1){
            --$m;
            $hash[$x] = 0;
        }
    }
    return ($m == 0);
}

/**
 * 解法五、素数相乘(仅为体验思路，有可能会溢出) 
 *
 **/
function compare_5($a,$b) {
    assert("is_string('$a')");
    assert("is_string('$b')");
    $a_ary = str_split($a);
    $b_ary = str_split($b);
    $ordA = ord('A');
    $p = array(2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,61, 67, 71, 73, 79, 83, 89, 97, 101);
    $f = 1;
    for ($i = 0; $i < count($a_ary); $i++) {
        $loca = ord($a_ary[$i]) - $ordA;
        $x = $p[$loca];
        if ($f % $x) {
            $f *= $x;
        }
    }
    for ($i = 0; $i < count($b_ary); $i++) {
        $loca = ord($b_ary[$i]) - $ordA;
        $x = $p[$loca];
        if ($f % $x) {
            return false;
        }
    }
    return true;
}


/**
 * 解法六、位运算 
 *
 **/
function compare_6($a,$b) {
    assert("is_string('$a')");
    assert("is_string('$b')");
    $a_ary = str_split($a);
    $b_ary = str_split($b);
    $ordA = ord('A');
    $hash = 0;
    for ($i = 0; $i < count($a_ary); $i++) {
        $x = ord($a_ary[$i]) - $ordA;
        $hash |= (1 << $x);
    }
    for ($i = 0; $i < count($b_ary); $i++) {
        $x = ord($b_ary[$i]) - $ordA;
        if (($hash & (1 << $x)) == 0) {
           return false;
        }
    }
    return true;
}

/**
 * 测试函数 
 *
 **/
function test($a,$b){
    var_dump (compare_1($a,$b));
    var_dump (compare_2($a,$b));
    var_dump (compare_3($a,$b));
    var_dump (compare_4($a,$b));
    var_dump (compare_5($a,$b));
    var_dump (compare_6($a,$b));
    echo "<br>";
}

$a = 'BCDEFGHLMNOPQRS';
$b = 'DCGSRQPO';
test($a,$b);
$a1 = 'ABCDEFGHLMNOPQRS';
$b1 = 'DCGSRQPOZ';
test($a1,$b1);
?>
