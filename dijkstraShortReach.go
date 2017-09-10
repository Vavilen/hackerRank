package main

import (
	"fmt"
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
	} else {
		fmt.Printf("node %d exists. skip\n", node)
	}
}

func (q *Queue) existsNode(node int) bool {
	if _, ok := q.exists[node]; ok {
		return true
	}
	return false
}

func (q *Queue) dequeue() int {
	var node = q.queue[0]
	q.queue = q.queue[1:]
	delete(q.exists, node)
	return node
}

func (q *Queue) pop() int {
	var n = len(q.queue)
	var value = q.queue[n-1]
	q.queue = q.queue[:n-1]
	delete(q.exists, value)
	return value
}

func (q *Queue) isEmpty() bool {
	return len(q.queue) == 0
}

func qsort(list [][]int) [][]int {
	if len(list) < 2 {
		return list
	}
	var left int = 0
	var pivot int = len(list) - 1
	var right int = len(list) - 1
	for i := 0; i < right; i++ {
		if list[i][1] < list[pivot][1] {
			list[i], list[left] = list[left], list[i]
			left++
		}
	}
	list[left], list[pivot] = list[pivot], list[left]
	qsort(list[:left])
	qsort(list[left+1:])
	return list
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
		//fmt.Printf("current: %d, weight: %d, processed: %s\n", current, nodes[current].weight, nodes[current].processed)

		var tmpList = make([][]int, 0)
		if nodes[current].processed {
			continue
		}
		nodes[current].processed = true
		for stop, distance := range nodes[current].edges {
			//if stop == 7 {
			//	fmt.Printf("for: %d, nodes[%d]: %d\n", current, stop, nodes[stop])
			//}
			if !nodes[stop].processed && (nodes[stop].weight == DEFAULT_WEIGHT || nodes[stop].weight > nodes[current].weight+distance) {
				nodes[stop].weight = nodes[current].weight + distance
				//fmt.Printf("current: %d, setted nodeId: %d, weight: %d\n", current, stop, nodes[stop].weight)
				tmpList = append(tmpList, []int{stop, nodes[stop].weight})
			}
		}

		fmt.Printf("unsorted: %s\n\n\n", tmpList)
		tmpList = qsort(tmpList)
		fmt.Printf("sorted: %s\n\n\n", tmpList)
		for _, item := range tmpList {
			if !nodes[item[0]].processed {
				queue.enqueue(item[0])
			}
		}
		fmt.Printf("queue after enqueue: %s\n", queue.queue)

		//fmt.Printf("new current: %d\n", minDistanceIdx)
		//if minDistanceIdx != 0 {
		//	queue.enqueue(minDistanceIdx)
		//}
	}
	for i := 1; i <= n; i++ {
		if i == s {
			continue
		}
		fmt.Printf("%d => %s\n", i, nodes[i].processed)
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
