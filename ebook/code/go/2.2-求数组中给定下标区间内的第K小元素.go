//2.2 求数组中给定下标区间内的第K小元素
//@author leiyonglin <leiyonglin@gmail.com>
//http://play.golang.org/p/eGkDSKGnhq

package main

import (
	"fmt"
	"sort"
)

type Node struct {
	Num  int
	Data int
}

type SortNodeByData []Node

func (a SortNodeByData) Len() int {
	return len(a)
}
func (a SortNodeByData) Swap(i, j int) {
	a[i], a[j] = a[j], a[i]
}
func (a SortNodeByData) Less(i, j int) bool {
	return a[i].Data < a[j].Data
}

//伴随数组解法
func find1(arr []int, a int, b int, flag int) int {
	i := 0
	p := []Node{}

	for k, v := range arr {
		node := Node{Data: v, Num: k}
		p = append(p, node)
	}

	sort.Sort(SortNodeByData(p))

	for i, _ = range p {
		if p[i].Num >= a && p[i].Num <= b {
			flag--
		}
		if flag == 0 {
			break
		}
	}

	return p[i].Data
}

func main() {

	arr := []int{5, 7, 1, 2, 9, 4, 6, 3, 80}
	a := 2
	b := 6
	flag := 4

	fmt.Println("原数组", arr)
	fmt.Printf("查找%v-%v第%v小的数\n", a, b, flag)

	fmt.Println(find1(arr, a, b, flag))
}
