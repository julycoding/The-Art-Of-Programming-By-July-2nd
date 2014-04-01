//2.1 寻找最小的k个数
//@author leiyonglin <leiyonglin@gmail.com>
//http://play.golang.org/p/41xfLFuTYq

package main

import (
	"fmt"
)

func quicksort(seq []int) []int {
	l := len(seq)
	if l <= 1 {
		return seq
	}
	s := seq[0]
	left := []int{}
	right := []int{}

	for i := 1; i < l; i++ {
		if seq[i] <= s {
			left = append(left, seq[i])
		} else {
			right = append(right, seq[i])
		}
	}
	left = quicksort(left)
	right = quicksort(right)

	seq = append(left, s)
	seq = append(seq, right...)

	return seq
}

func max(seq []int) int {
	l := len(seq)
	if l == 0 {
		//ERROR
		return 0
	}
	if l == 1 {
		return seq[0]
	}

	m := 0
	for i := 1; i < l; i++ {
		if seq[i] > seq[m] {
			m = i
		}
	}

	return m
}

func bInsert(seq []int, k int) []int {
	l := len(seq)
	left := 0
	right := l - 1
	for left <= right {
		m := (left + right) / 2
		if seq[m] > k {
			right = m - 1
		} else {
			left = m + 1
		}
	}
	w := []int{}

	w = append(w, seq[:left]...)
	w = append(w, k)
	w = append(w, seq[left:l-1]...)

	return w
}

//解法一
func sort1(seq []int, k int) []int {
	if len(seq) <= k {
		return seq
	}
	s := quicksort(seq)
	return s[:k]
}

//解法二
func sort2(seq []int, k int) []int {
	l := len(seq)
	if l <= k {
		return seq
	}

	ks := make([]int, k)
	copy(ks, seq[:k])
	m := max(ks)

	for i := k; i < l; i++ {
		if seq[i] < ks[m] {
			ks[m] = seq[i]
			m = max(ks)
		}
	}

	return ks
}

//解法三
func sort3(seq []int, k int) []int {
	l := len(seq)
	if l <= k {
		return seq
	}

	ks := make([]int, k)
	copy(ks, seq[:k])
	ks = quicksort(ks)

	for i := k; i < l; i++ {
		if seq[i] < ks[k-1] {
			ks = bInsert(ks, seq[i])
		}
	}

	return ks
}

func main() {
	seq := []int{1, 5, 6, 3, 4, 5, 8, 4, 1, 7}
	k := 4
	fmt.Println("原字符串:", seq)

	fmt.Println("sort1:", sort1(seq, k))
	fmt.Println("sort2:", sort2(seq, k))
	fmt.Println("sort3:", sort3(seq, k))

}
