package main

import (
	"fmt"
	"math/rand"
)

//https://www.hackerrank.com/challenges/minimum-loss

func main() {
	var yearsCount int
	//var current int

	fmt.Scanf("%d", &yearsCount)
	var list []YearPrice = make([]YearPrice, yearsCount)
	for i := 0; i < yearsCount; i++ {
		fmt.Scanf("%d", &list[i].price)
		list[i].year = i
	}
	//sortPartition(&list, 0, len(list) - 1)
	list = qsort(list)
	var min int = list[len(list)-1].price
	for i := len(list) - 1; i > 0; i-- {
		if list[i].price-list[i-1].price < min && list[i].price-list[i-1].price > 0 && list[i].year < list[i-1].year {
			min = list[i].price - list[i-1].price
		}
	}
	fmt.Println(min)
}

type YearPrice struct {
	year  int
	price int
}

func qsort(a []YearPrice) []YearPrice {
	if len(a) < 2 {
		return a
	}

	left, right := 0, len(a)-1

	// Pick a pivot
	pivotIndex := rand.Int() % len(a)

	// Move the pivot to the right
	a[pivotIndex], a[right] = a[right], a[pivotIndex]

	// Pile elements smaller than the pivot on the left
	for i := range a {
		if a[i].price < a[right].price {
			a[i], a[left] = a[left], a[i]
			left++
		}
	}

	// Place the pivot after the last smaller element
	a[left], a[right] = a[right], a[left]

	// Go down the rabbit hole
	qsort(a[:left])
	qsort(a[left+1:])

	return a
}
