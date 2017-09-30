package main

import (
	"fmt"
	"errors"
	"bufio"
	"os"
	"sync"
	"strings"
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

type Tree struct {
	Root *TreeNode
	Min  int
}

type TreeNode struct {
	Distance int
	Idx      int
	Left     *TreeNode
	Right    *TreeNode
}

func (n *TreeNode) Insert(distance int, idx int) error {
	switch {
	case distance < n.Distance:
		if n.Left == nil {
			n.Left = &TreeNode{Distance: distance, Idx: idx}
		} else {
			n.Left.Insert(distance, idx)
		}
	case distance >= n.Distance:
		if n.Right == nil {
			n.Right = &TreeNode{Distance: distance, Idx: idx}
		} else {
			n.Right.Insert(distance, idx)
		}
	}
	return nil
}

func (n *TreeNode) ReplaceNode(parent, replacement *TreeNode) error {
	if n == nil {
		return errors.New("can`t replace nil node")
	}
	if n == parent.Left {
		parent.Left = replacement
		return nil
	}
	parent.Right = replacement
	return nil
}

func (t *Tree) Pop() *TreeNode {
	if t.Root.Left == nil && t.Root.Right == nil {
		var value *TreeNode = t.Root
		t.Root = nil
		return value
	} else if t.Root.Left == nil {
		var value *TreeNode = t.Root
		t.Root = t.Root.Right
		return value
	}
	return t.PopMin(t.Root.Left, t.Root)
}

func (t *Tree) PopMin(current *TreeNode, parent *TreeNode) *TreeNode {
	if current.Left == nil {
		var result TreeNode
		result = *current
		if current.Right != nil {
			*parent.Left = *current.Right
		} else {
			parent.Left = nil
		}
		return &result
	}
	return t.PopMin(current.Left, current)
}



func Insert(heap *Tree, distance int, idx int) error {
	if heap.Root == nil {
		heap.Root = &TreeNode{
			Distance: distance,
			Idx:      idx,
			Left:     nil,
			Right:    nil,
		}
		return nil
	}
	err := heap.Root.Insert(distance, idx)
	return err
}

func process(scanner *bufio.Scanner, nodes *[]*Node, wg *sync.WaitGroup) {
	var n int // nodes count
	var m int // edges count

	var x int // edge start node
	var y int // edge stop node
	var r int // x-y distance

	var s int // start node

	if !scanner.Scan() {
		return
	}
	fmt.Sscanf(scanner.Text(), "%d %d", &n, &m)
	nodesRaw := make([]string, m)
	for i := 0; i < m; i++ {
		scanner.Scan()
		nodesRaw[i] = scanner.Text()
	}
	if !scanner.Scan() {
		return
	}
	*nodes = make([]*Node, n + 1)
	fmt.Sscanf(scanner.Text(), "%d", &s)
	go func(nodesRaw []string, n, m, s int, wg *sync.WaitGroup) {
		defer wg.Done()
		for i := 0; i < m; i++ {
			splitted := strings.Split(nodesRaw[i], " ")
			x = toInt([]byte(splitted[0]))
			y = toInt([]byte(splitted[1]))
			r = toInt([]byte(splitted[2]))
			if (*nodes)[x] == nil {
				(*nodes)[x] = &Node{
					id:        x,
					edges:     make(map[int]int, 0),
					weight:    DEFAULT_WEIGHT,
					processed: false,
				}
			}
			if (*nodes)[y] == nil {
				(*nodes)[y] = &Node{
					id:        y,
					edges:     make(map[int]int, 0),
					weight:    DEFAULT_WEIGHT,
					processed: false,
				}
			}

			(*nodes)[x].addEdge(y, r)
			(*nodes)[y].addEdge(x, r)
		}


		(*nodes)[s].weight = 0
		var heap = &Tree{}
		heap.Root = &TreeNode{
			Distance: 0,
			Idx:      s,
			Left:     nil,
			Right:    nil,
		}
		for heap.Root != nil {
			var current = heap.Pop()
			if (*nodes)[current.Idx].processed {
				continue
			}
			(*nodes)[current.Idx].processed = true
			for stop, distance := range (*nodes)[current.Idx].edges {
				if !(*nodes)[stop].processed && ((*nodes)[stop].weight == DEFAULT_WEIGHT || (*nodes)[stop].weight > (*nodes)[current.Idx].weight+distance) {
					(*nodes)[stop].weight = (*nodes)[current.Idx].weight + distance
					Insert(heap,(*nodes)[stop].weight, stop)
				}
			}
		}
	}(nodesRaw, n, m, s, wg)
}

func main() {
	var t int // tests count
	var wg sync.WaitGroup
	scanner := bufio.NewScanner(os.Stdin)
	//buf, err := ioutil.ReadAll(reader)

	if !scanner.Scan() {
		return
	}
	fmt.Sscanf(scanner.Text(), "%d", &t)
	var nodesnodes = make([][]*Node, t)
	for i := 0; i < t; i++ {
		wg.Add(1)
		process(scanner, &nodesnodes[i], &wg)
	}
	wg.Wait()
	for ii := 0; ii < t; ii++ {
		for j := 1; j <= len(nodesnodes[ii]) - 1; j++ {
			if nodesnodes[ii][j].weight == 0 {
				continue
			}
			fmt.Printf("%d", nodesnodes[ii][j].weight)
			if j < len(nodesnodes[ii]) {
				fmt.Print(" ")
			}
		}
		fmt.Print("\n")
	}

}

func toInt(buf []byte) (n int) {
	for _, v := range buf {
		n = n*10 + int(v-'0')
	}
	return
}
