package main

import "fmt"

//https://www.hackerrank.com/challenges/missing-numbers

const PIVOT_IDX = 101

func main() {
	var merged []int = make([]int, 201)
	var size int
	var temp int
	var pivot int

	fmt.Scanf("%d", &size)
	fmt.Scanf("%d", &pivot)
	merged[PIVOT_IDX]++
	for i := 1; i < size; i++ {
		fmt.Scanf("%d", &temp)
		merged[PIVOT_IDX+temp-pivot]++
	}
	fmt.Scanf("%d", &size)
	for i := 0; i < size; i++ {
		fmt.Scanf("%d", &temp)
		merged[PIVOT_IDX+temp-pivot]--
	}

	for idx := range merged {
		if merged[idx] < 0 {
			fmt.Printf("%d ", pivot+idx-PIVOT_IDX)
		}
	}
}
