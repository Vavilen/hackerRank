package main

import (
	"fmt"
)

const MAX_INT = ^0 >> 1

// https://www.hackerrank.com/challenges/dijkstrashortreach

type Node struct {
	id     int
	weight int
	edges  map[int]map[int]*Edge
}

func (n *Node) checkNodeOrInit() {
	if n.edges == nil {
		n.edges = make(map[int]map[int]*Edge, 0)
		n.weight = 0
	}
}

func (n *Node) addEdge(start int, stop int, distance int) {
	if _, ok := n.edges[start]; !ok {
		n.edges[start] = make(map[int]*Edge, 0)
	}
	if _, ok := n.edges[start][stop]; !ok {
		n.edges[start][stop] = &Edge{
			distances: []int{distance},
		}
		return
	}
	n.edges[start][stop].distances = append(n.edges[start][stop].distances, distance)
}

type Edge struct {
	start     int
	stop      int
	distances []int
}

func main() {
	var t int // tests count
	fmt.Scanf("%d", &t)

	for i := 0; i < t; i++ {
		process()
	}
}

func process() {
	var n int // nodes count
	var m int // edges count

	var x int // edge start node
	var y int // edge stop node
	var r int // x-y distance

	var s int // start node

	fmt.Scanf("%d %d", &n, &m)
	var nodes = make([]*Node, n+1)
	for i := 0; i < m; i++ {
		fmt.Scanf("%d %d %d", &x, &y, &r)
		if nodes[x] == nil {
			nodes[x] = &Node{
				id:     x,
				edges:  make(map[int]map[int]*Edge, 0),
				weight: MAX_INT,
			}
		}
		nodes[x].addEdge(x, y, r)
		fmt.Printf("node %d = %s\n", x, nodes[x])
	}
	fmt.Scanf("%d", &s)
	nodes[s].weight = 0


}