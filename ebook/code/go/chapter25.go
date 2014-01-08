// http://play.golang.org/p/zN5jE8nsiO

package main

import (
	"fmt"
)

func main() {
	var data []int = []int{1, 3, 4, 5, 8, 20}
	fmt.Printf("result is %d \n", binarySearch(data, 3))
	fmt.Printf("result is %d \n", binarySearch(data, 2))
	fmt.Printf("result is %d \n", binarySearch(data, 20))

}

func binarySearch(data []int, value int) int {
	var left int = 0
	var right int = len(data) - 1
	var middle int

	for left <= right {
		middle = left + (right-left)/2

		if data[middle] > value {
			right = middle - 1
		}

		if data[middle] < value {
			left = middle + 1
		}

		if data[middle] == value {
			return middle
		}
	}
	return -1
}
