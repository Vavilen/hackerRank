package main

import "fmt"

// https://www.hackerrank.com/challenges/the-quickest-way-up

func main() {
	var testsCount int
	fmt.Scanf("%d", &testsCount)
	for i := 0; i < testsCount; i++ {
		process()
	}
}

type Node struct {
	position int
	level    int
}

type Queue struct {
	nodes []*Node
}

func (q *Queue) enqueue(node *Node) {
	q.nodes = append(q.nodes, node)
}

func (q *Queue) dequeue() *Node {
	if len(q.nodes) == 0 {
		return nil
	}
	var node *Node = q.nodes[0]
	q.nodes = q.nodes[1:]
	return node
}

func (q *Queue) isEmpty() bool {
	return len(q.nodes) == 0
}

func bfs(nodes [][]int, start int, goal int) int {
	var seen = make(map[int]bool, 100)
	var level int = 0
	var queue = Queue{
		nodes: make([]*Node, 0),
	}
	queue.enqueue(
		&Node{
			position: start,
			level:    level,
		},
	)

	for !queue.isEmpty() {
		var currentNode *Node = queue.dequeue()
		for _, destination := range nodes[currentNode.position] {
			if seen[destination] {
				continue
			}
			if destination == goal {
				if len(nodes[currentNode.position]) == 1 {
					return currentNode.level
				} else {
					return currentNode.level + 1
				}
			}
			seen[destination] = true
			if len(nodes[currentNode.position]) == 1 {
				queue.enqueue(
					&Node{
						position: destination,
						level:    currentNode.level,
					},
				)
			} else {
				queue.enqueue(
					&Node{
						position: destination,
						level:    currentNode.level + 1,
					},
				)
			}
		}
	}
	return -1
}

func process() {
	var laddersNumber int
	var snakesNumber int
	var start int
	var stop int
	var nodes = make([][]int, 100)
	for i := 1; i < 100; i++ {
		nodes[i] = []int{i + 1, i + 2, i + 3, i + 4, i + 5, i + 6,}
	}
	fmt.Scanf("%d", &laddersNumber)
	for i := 0; i < laddersNumber; i++ {
		fmt.Scanf("%d %d", &start, &stop)
		nodes[start] = []int{stop}
	}
	fmt.Scanf("%d", &snakesNumber)
	for i := 0; i < snakesNumber; i++ {
		fmt.Scanf("%d %d", &start, &stop)
		nodes[start] = []int{stop}
	}

	fmt.Printf("%d\n", bfs(nodes, 1, 100))
}
