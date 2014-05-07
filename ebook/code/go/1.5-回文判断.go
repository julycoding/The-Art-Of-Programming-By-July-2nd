//1.5 回文判断
//@author leiyonglin <leiyonglin@gmail.com>
//http://play.golang.org/p/K4NyYq-Teo
package main

import (
	"fmt"
)

//解法一
func isPalindrome(s string) bool {
	l := len(s)
	if l < 1 {
		return false
	}

	left := 0
	right := l - 1
	for left < right {
		if s[left] != s[right] {
			return false
		}
		left++
		right--
	}

	return true
}

//解法二
func isPalindrome2(s string) bool {
	l := len(s)
	if l < 1 {
		return false
	}

	m := l / 2
	left := m - 1
	right := m + l%2

	for left >= 0 {
		if s[left] != s[right] {
			return false
		}
		left--
		right++
	}

	return true
}

func main() {
	s := "madam"

	fmt.Printf("字符串%s是否为回文：%v \n", s, isPalindrome(s))
	fmt.Printf("字符串%s是否为回文：%v \n", s, isPalindrome2(s))

	s = "david"

	fmt.Printf("字符串%s是否为回文：%v \n", s, isPalindrome(s))
	fmt.Printf("字符串%s是否为回文：%v \n", s, isPalindrome2(s))
}
