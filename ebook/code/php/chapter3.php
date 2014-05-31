<?php
class Wildcard{
    /**
     * 拼接结果字符串 
     *
     **/
    private static function str_join($a,$b,$lenb){
        $t = ''; 
        if(empty($a)){
            $t = substr($b,0,$lenb);
            return $t;
        }else{
            $lena = strlen($a);
            $t = substr($a,0,$lena);
            $t .= ' ';
            $t .= substr($b,0,$lenb);
            return $t;
        }
    }

    /**
     * 匹配通配符 
     *
     **/
    private static function canMatch($input,$rule){
    // 返回最长匹配长度 -1表示不匹配
        if(empty($rule)){
            return 0;
        } 
        $r = -1;
        $may = 0;
        if(substr($rule,0,1) == '*'){
            $r = Wildcard::canMatch($input,substr($rule,1));// *匹配0个字符
            if(!empty($input)){
                $may = Wildcard::canMatch(substr($input,1),$rule); 
                if(($may>=0)&&(++$may>$r) ){
                    $r = $may;
                }
            }
        }
        if(empty($input)){
            return $r;
        }
        if((substr($rule,0,1)=='?') || (substr($rule,0,1)==substr($input,0,1)) ){
            $may = Wildcard::canMatch(substr($input,1),substr($rule,1));
            if(($may>=0) && (++$may > $r)){
                $r = $may;
            }
        }
        return $r;
    }

    /**
     * 匹配通配符 
     *
     **/
    public static function my_find($input,$rule){
        assert("is_string('$input')");
        assert("is_string('$rule')");
        $len = strlen($input);
        $i = -1;
        $match = array();
        $max_pos = -1;
        $output = '';
        for($i=0;$i<$len;++$i){
            $match[$i] = Wildcard::canMatch(substr($input,$i),$rule);
            if($max_pos < 0 || $match[$i]>$match[$max_pos] ){
                $max_pos = $i;
            }
        }
        if(($max_pos<0) || ($match[$max_pos]<=0)){
        //不匹配 
            $output = '';
            return $output;
        }
        for ($i = 0; $i < $len;) {
            if($match[$i]==$match[$max_pos] ){
                $output = Wildcard::str_join($output,substr($input,$i),$match[$i]);
                $i += $match[$i];
            }else{
                $i++;
            }
        }
        return $output;
    }
}

function test($input,$rule){
    $rst = Wildcard::my_find($input,$rule);
    echo "input:".$input;
    echo "<br>rule:".$rule;
    echo "<br>result:".$rst;
    echo "<br><br>";
}

$input = "absdfsdfabc";
$rule = "ab";
test($input,$rule);
$input = "absdadbakk";
$rule = "a*b";
test($input,$rule);
?
