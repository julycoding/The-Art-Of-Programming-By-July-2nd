//1.2 字符串是否包含问题
//@author leiyonglin <leiyonglin@gmail.com>
//http://play.golang.org/p/sO4hYrRtYT

package main

import (
	"fmt"
	"sort"
	"strings"
)

//方法一: 暴力轮询
func compare1(a string, b string) bool {
	la := len(a)
	lb := len(b)
	for i := 0; i < lb; i++ {
		for j := 0; j < la; j++ {
			if b[i] == a[j] {
				break
			}
			if j >= la-1 {
				return false
			}
		}
	}

	return true
}

//方法二:普通排序
func compare2(a string, b string) bool {
	as := sortString(a)
	bs := sortString(b)
	la := len(as)
	lb := len(bs)
	pa := 0
	pb := 0
	for pb < lb {
		for pa < la && as[pa] < bs[pb] {
			pa++
		}
		if pa >= la || as[pa] > bs[pb] {
			return false
		}
		pb++
	}

	return true
}

func sortString(w string) string {
	s := strings.Split(w, "")
	sort.Strings(s)
	return strings.Join(s, "")
}

//方法三:记数比较
func compare3(a string, b string) bool {
	var have [26]int = [26]int{}
	ab := []byte(a)
	bb := []byte(b)
	la := len(a)
	lb := len(b)

	//A ASCII code is 65
	for i := 0; i < la; i++ {
		have[ab[i]-65] = 1
	}

	for i := 0; i < lb; i++ {
		if have[bb[i]-65] == 0 {
			return false
		}
	}

	return true
}

//方法四: 巧用hashtable
func compare4(a string, b string) bool {
	var hash [26]int = [26]int{}
	var m int = 0
	ab := []byte(a)
	bb := []byte(b)
	la := len(a)
	lb := len(b)

	for i := 0; i < lb; i++ {
		x := bb[i] - 65
		if hash[x] == 0 {
			hash[x] = 1
			m++
		}
	}

	for i := 0; i < la && m > 0; i++ {
		x := ab[i] - 65
		if hash[x] == 1 {
			hash[x] = 0
			m--
		}
	}

	return m == 0
}

//解法五:素数相乘
func compare5(a string, b string) bool {
	return true
}

//解法六:位运算
func compare6(a string, b string) bool {
	hash := 0
	ab := []byte(a)
	bb := []byte(b)
	la := len(a)
	lb := len(b)

	for i := 0; i < la; i++ {
		hash |= (1 << (ab[i] - 65))
	}
	for i := 0; i < lb; i++ {
		if (hash & (1 << (bb[i] - 65))) == 0 {
			return false
		}
	}

	return true
}

func main() {
	//true
	a := "ABCDEFGHLMNOPQRS"
	b := "DCGSRQPO"

	fmt.Println("字符串a:", a)
	fmt.Println("字符串b:", b)

	fmt.Println("compare1 - a包含b:", compare1(a, b))
	fmt.Println("compare2 - a包含b:", compare2(a, b))
	fmt.Println("compare3 - a包含b:", compare3(a, b))
	fmt.Println("compare4 - a包含b:", compare4(a, b))
	fmt.Println("compare6 - a包含b:", compare6(a, b))

	//false
	a = "ABCDEFGHLMNOPQRS"
	b = "DCGSRQPOZ"

	fmt.Println("字符串a:", a)
	fmt.Println("字符串b:", b)

	fmt.Println("compare1 - a包含b:", compare1(a, b))
	fmt.Println("compare2 - a包含b:", compare2(a, b))
	fmt.Println("compare3 - a包含b:", compare3(a, b))
	fmt.Println("compare4 - a包含b:", compare4(a, b))
	fmt.Println("compare6 - a包含b:", compare6(a, b))
}
