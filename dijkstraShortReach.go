package main

import (
	"fmt"
	"sort"
)

// https://www.hackerrank.com/challenges/dijkstrashortreach

const DEFAULT_WEIGHT = -1

type Node struct {
	id        int
	weight    int
	processed bool
	edges     map[int]int
}

func (n *Node) checkNodeOrInit() {
	if n.edges == nil {
		n.edges = make(map[int]int, 0)
		n.weight = 0
	}
}

func (n *Node) addEdge(stop int, distance int) {
	if _, ok := n.edges[stop]; !ok {
		n.edges[stop] = distance
	} else if n.edges[stop] > distance {
		n.edges[stop] = distance
	}
}

type Item struct {
	value    int
	priority int
	index    int
}

type PriorityQueue []*Item

// Len - get the length of the heap
func (pq PriorityQueue) Len() int { return len(pq) }

// Less - determine which is more priority than another
func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].priority > pq[j].priority
}

// Swap - implementation of swap for the heap interface
func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}

// Push - implementation of push for the heap interface
func (pq *PriorityQueue) Push(x *Item) {
	n := len(*pq)
	item := x
	item.index = n
	*pq = append(*pq, item)
}

// Pop - implementation of pop for heap interface
func (pq *PriorityQueue) Pop() *Item {
	old := *pq
	n := len(old)
	item := old[n-1]
	item.index = -1 // for safety
	*pq = old[0: n-1]
	return item
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
				id:        x,
				edges:     make(map[int]int, 0),
				weight:    DEFAULT_WEIGHT,
				processed: false,
			}
		}
		if nodes[y] == nil {
			nodes[y] = &Node{
				id:        y,
				edges:     make(map[int]int, 0),
				weight:    DEFAULT_WEIGHT,
				processed: false,
			}
		}

		nodes[x].addEdge(y, r)
		nodes[y].addEdge(x, r)
	}
	fmt.Scanf("%d", &s)
	nodes[s].weight = 0
	var heap = PriorityQueue{}
	heap.Push(
		&Item{
			value:    s,
			priority: 0,
		},
	)
	for heap.Len() > 0 {
		var current = heap.Pop()
		if nodes[current.value].processed {
			continue
		}
		nodes[current.value].processed = true
		for stop, distance := range nodes[current.value].edges {
			if !nodes[stop].processed && (nodes[stop].weight == DEFAULT_WEIGHT || nodes[stop].weight > nodes[current.value].weight+distance) {
				nodes[stop].weight = nodes[current.value].weight + distance
				heap.Push(
					&Item{
						value:    stop,
						priority: nodes[stop].weight,
					},
				)
			}
		}
		sort.Sort(heap)
	}

	for i := 1; i <= n; i++ {
		if i == s {
			continue
		}
		fmt.Printf("%d", nodes[i].weight)
		if i < n {
			fmt.Print(" ")
		}
	}
	fmt.Print("\n")
}

func main() {
	var t int // tests count
	fmt.Scanf("%d", &t)

	for i := 0; i < t; i++ {
		process()
	}
}
