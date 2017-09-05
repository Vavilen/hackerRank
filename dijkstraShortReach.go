package main

import (
	"fmt"
)



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
			distance: distance,
		}
		return
	}
	if n.edges[start][stop].distance > distance {
		n.edges[start][stop].distance = distance
	}
}

type Edge struct {
	start    int
	stop     int
	distance int
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
				weight: -1,
			}
		}
		if nodes[y] == nil {
			nodes[y] = &Node{
				id:     y,
				edges:  make(map[int]map[int]*Edge, 0),
				weight: -1,
			}
		}
		nodes[x].addEdge(x, y, r)
		nodes[x].addEdge(y, x, r)
		fmt.Printf("node %d = %s\n", x, nodes[x])
	}
	fmt.Scanf("%d", &s)
	nodes[s].weight = 0
	for i := 1; i < n; i++ {
		//if i == s {
		//	continue
		//}
		for _, edgesMap := range nodes[s].edges {
			for stop, edge := range edgesMap {
				fmt.Printf("for: %d, nodes[%d]: %d\n", i, stop, nodes[stop])
				if nodes[stop].weight < 0 || nodes[stop].weight > nodes[i].weight + edge.distance {
					nodes[stop].weight = nodes[i].weight + edge.distance
				}
			}
		}
	}
	for i := 1; i <= n; i++ {
		if i == s {
			continue
		}
		fmt.Printf("node: %d, weight: %d\n", i, nodes[i].weight)
	}
}
