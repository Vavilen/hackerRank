package main

import "fmt"
import "container/heap"

// https://www.hackerrank.com/challenges/even-tree


type Node struct {
	parent int
	childrenCount int
}


func main() {
	var count int = 0
	var n int // nodes number
	var m int // edges number
	fmt.Scanf("%d %d", &n, &m)
	var nodes = make([]Node, n + 1)
	var child, parent int
	for i := 0; i < m; i++ {
		fmt.Scanf("%d %d", &child, &parent)
		nodes[child].parent = parent
		nodes[parent].childrenCount++
	}
	for i := n; i > 1; i-- {
		if nodes[i].childrenCount % 2 != 0 {
			count++
			nodes[nodes[i].parent].childrenCount--
		}
	}
	fmt.Printf("%d\n", count)

}
