package main

import (
	"fmt"
)

// https://www.hackerrank.com/challenges/dijkstrashortreach

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

func main() {
	var t int // tests count
	fmt.Scanf("%d", &t)

	for i := 0; i < t; i++ {
		process()
	}
}

type Queue struct {
	exists map[int]bool
	queue  []int
}

func (q *Queue) enqueue(node int) {
	if _, ok := q.exists[node]; !ok {
		q.queue = append(q.queue, node)
		q.exists[node] = true
	}
}

func (q *Queue) dequeue() int {
	var node = q.queue[0]
	q.queue = q.queue[1:]
	delete(q.exists, node)
	return node
}

func (q *Queue) isEmpty() bool {
	return len(q.queue) == 0
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
				weight:    -1,
				processed: false,
			}
		}
		if nodes[y] == nil {
			nodes[y] = &Node{
				id:        y,
				edges:     make(map[int]int, 0),
				weight:    -1,
				processed: false,
			}
		}

		nodes[x].addEdge(y, r)
		nodes[y].addEdge(x, r)
		//fmt.Printf("node %d = %s\n", x, nodes[x])
	}
	fmt.Scanf("%d", &s)
	nodes[s].weight = 0
	var queue = Queue{
		queue:  make([]int, 0),
		exists: make(map[int]bool, 0),
	}
	queue.enqueue(s)
	//nodes[s].processed = true
	for !queue.isEmpty() {
		var current = queue.dequeue()
		//var minDistance = 0
		//var minDistanceIdx = 0
		//fmt.Printf("after dequeued: %s=\n", queue)
		fmt.Printf("current: %d, weight: %d, processed: %s\n", current, nodes[current].weight, nodes[current].processed)
		if nodes[current].processed {
			continue
		}
		nodes[current].processed = true
		for stop, distance := range nodes[current].edges {
			if stop == 7 {
				fmt.Printf("for: %d, nodes[%d]: %d\n", current, stop, nodes[stop])
			}
			if nodes[stop].weight < 0 || nodes[stop].weight > nodes[current].weight+distance {
				fmt.Printf("WILL set for nodeId: %d with weight: %d => ", stop, nodes[stop].weight)
				nodes[stop].weight = nodes[current].weight + distance
				fmt.Printf("current: %d with weight: %d, setted nodeId: %d with distance: %d, weight: %d\n",
					current, nodes[current].weight, stop, distance, nodes[stop].weight)
				//if (minDistance == 0 || minDistance > nodes[stop].weight) && !nodes[stop].processed {
				//	minDistance = nodes[stop].weight
				//	minDistanceIdx = stop
				//}
			}
			if !nodes[stop].processed {
				queue.enqueue(stop)
			}
		}
		//fmt.Printf("new current: %d\n", minDistanceIdx)
		//if minDistanceIdx != 0 {
		//	queue.enqueue(minDistanceIdx)
		//}
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
