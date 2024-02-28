package main

import (
	"fmt"
)

func main() {
	var s []byte
	fmt.Scan(&s)

	alphabetCount := make(map[byte]int)
	firstIndex := make(map[byte]int)
	for i, c := range s {
		if alphabetCount[c] == 0 {
			firstIndex[c] = i
		}
		alphabetCount[c]++
	}

	// search alphabet which appears 1 time
	for k, v := range alphabetCount {
		if v == 1 {
			fmt.Println(firstIndex[k] + 1)
			break
		}
	}
}
