// 3.2 杨氏矩阵查找
// @author leiyonglin <leiyonglin@gmail.com>
// http://play.golang.org/p/EcFyPADISb

package main

import (
	"fmt"
)

//解法二：定位法
func find2(arr [][]int, s int) bool {
	n := len(arr)
	if n == 0 {
		return false
	}
	m := len(arr[0])
	if m == 0 {
		return false
	}

	x := m - 1
	y := 0

	for x >= 0 && y < n {
		if arr[y][x] > s {
			x--
		} else if arr[y][x] < s {
			y++
		} else {
			return true
		}

	}
	return false
}

func main() {
	arr := [][]int{
		[]int{1, 2, 8, 9},
		[]int{2, 4, 9, 12},
		[]int{4, 7, 10, 13},
		[]int{6, 8, 11, 15},
	}

	fmt.Println("数组：", arr)

	s := 10
	fmt.Printf("%d 是否在数组中: %t \n", s, find2(arr, s))

	s = 16
	fmt.Printf("%d 是否在数组中: %t \n", s, find2(arr, s))

}
