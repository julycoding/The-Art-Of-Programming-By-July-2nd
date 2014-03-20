<?php
/*
* Chapter One - Left Rotating String
* @author by howaichun
* @email: howaichun@foxmail.com
*/

/*
*method3
*/
function left_rotate3($string){
	$arr_string = str_split($string);
	$tmp_arr = array();
	$num = count($arr_string);
	for(;$num > 0; $num--){
		$tmp_arr[] = array_pop($arr_string);
	}
	$rotate_string = implode($tmp_arr);
	return $rotate_string;
}

/*
* method2
* @params string $string
*/
function left_rotate2($string){
	$num = strlen($string); 
	$arr = array();
	for($n = $num - 1;$n >= 0; $n--){
		$arr[] = $string["$n"];
	}
	$rotate_string = implode("", $arr);
	return $rotate_string;
}

/*
* method1 
* @params string $string left move string
*  
*/
function left_rotate1($str){
	$arr = str_split($str);
	$result = array_reverse($arr);
	$rotate_string = implode("", $result);
	return $rotate_string;
}
	
