package main

import "fmt"

//https://www.hackerrank.com/challenges/pairs

func main() {
	var matchesCount int = 0
	var matches = make(map[int]int, 0)
	var listLength int
	var diff int
	var tmp int
	fmt.Scanf("%d %d", &listLength, &diff)
	for i := 0; i < listLength; i++ {
		fmt.Scanf("%d", &tmp)
		if _, ok := matches[tmp]; !ok {
			matches[tmp]++
		} else {
			matches[tmp]++
			if matches[tmp] == 2 {
				matchesCount++
			}
		}

		if _, ok := matches[tmp + diff]; !ok {
			matches[tmp + diff]++
		} else {
			matches[tmp + diff]++
			if matches[tmp + diff] == 2 {
				matchesCount++
			}
		}
	}
	fmt.Printf("%d\n", matchesCount)
}
