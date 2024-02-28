package main

import "fmt"

func main() {
	var n int
	var s []byte
	var q int
	var c, d []byte

	fmt.Scan(&n)
	fmt.Scan(&s)
	fmt.Scan(&q)
	fmt.Println(n, string(s), q)
	c = make([]byte, q)
	d = make([]byte, q)
	for i := 0; i < q; i++ {
		fmt.Scan(&c[i], &d[i])
		fmt.Println(c[i], d[i])
	}

	var replaceMap map[byte]byte
	replaceMap = make(map[byte]byte, 26)

	for i := 0; i < q; i++ {
		for j := 0; j < 26; j++ {
			if replaceMap['a'+byte(j)] == c[i] {
				replaceMap['a'+byte(j)] = d[i]
			}
		}
	}

	for i := 0; i < n; i++ {
		s[i] = replaceMap[s[i]]
	}

	fmt.Println(string(s))
}
