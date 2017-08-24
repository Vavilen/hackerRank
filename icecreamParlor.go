package main

import "fmt"

//https://www.hackerrank.com/challenges/icecream-parlor

func main() {
	var tripsNumber int   // t
	var moneyPool int     // m
	var flavorsNumber int // n
	fmt.Scanf("%d", &tripsNumber)
	for i := 0; i < tripsNumber; i++ {
		fmt.Scanf("%d", &moneyPool)
		fmt.Scanf("%d", &flavorsNumber)
		var flavors []int = make([]int, 0)
		var flavorsPositionMap map[int][]int = make(map[int][]int, 0)
		var currentFlavorCost int
		for j := 0; j < flavorsNumber; j++ {
			fmt.Scanf("%d", &currentFlavorCost)
			flavors = append(flavors, currentFlavorCost)
			if _, ok := flavorsPositionMap[currentFlavorCost]; !ok {
				flavorsPositionMap[currentFlavorCost] = make([]int, 0)
			}
			flavorsPositionMap[currentFlavorCost] = append(flavorsPositionMap[currentFlavorCost], j)
		}
		var currentIdx int = 0
		var currentInnerIdx int = 0
	LOOP:
		for currentIdx < len(flavors) {
			var first int = flavorsPositionMap[flavors[currentIdx]][currentInnerIdx]
			var second int = 0
			var needRest int = moneyPool - flavors[currentIdx]
			if currentInnerIdx < len(flavorsPositionMap[flavors[currentIdx]])-1 {
				currentInnerIdx++
			} else {
				delete(flavorsPositionMap, flavors[currentIdx])
			}
			if _, ok := flavorsPositionMap[needRest]; ok {
				second = flavorsPositionMap[needRest][currentInnerIdx]
				fmt.Printf("%d %d\n", first+1, second+1)
				break LOOP
			}
			currentIdx++
			currentInnerIdx = 0
		}
	}

}
