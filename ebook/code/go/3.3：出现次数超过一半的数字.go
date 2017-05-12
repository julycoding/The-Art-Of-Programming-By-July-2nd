package main

import (
	"fmt"

//	"math"
)

func findNumberAppearEqualHalf(data []int) int {
	var (
		c1 = findNumberAppearMoreThanHalf(data)
		c2 = data[len(data)-1]
		n  = 0
	)
	for _, c := range data {
		if c1 == c {
			n++
		}
	}

	if n == len(data)/2 {
		return c1
	} else {
		return c2
	}
}

func findNumberAppearMoreThanHalf(data []int) int {
	var (
		candidate int
		nTimes    int = 0
	)

	for i := 0; i < len(data); i++ {
		switch {
		case nTimes == 0:
			candidate = data[i]
			nTimes = 1
		case candidate == data[i]:
			nTimes++
		default:
			nTimes--
		}
	}
	return candidate
}

func main() {
	a := []int{3, 5, 7, 5, 15, 5}
	fmt.Printf("%d\n", findNumberAppearMoreThanHalf(a))
	fmt.Printf("%d\n", findNumberAppearEqualHalf(a))
}
