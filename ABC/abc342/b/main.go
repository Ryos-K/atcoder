package main

import (
	"fmt"
)

func main() {
	var n int
	var positionOf map[int]int
	var q int
	var a, b int
	fmt.Scan(&n)
	positionOf = make(map[int]int, n)
	for i := 0; i < n; i++ {
		var tmp int
		fmt.Scan(&tmp)
		positionOf[tmp] = i
	}
	fmt.Scan(&q)
	for i := 0; i < q; i++ {
		fmt.Scan(&a, &b)
		if positionOf[a] < positionOf[b] {
			fmt.Println(a)
		} else {
			fmt.Println(b)
		}
	}
}
