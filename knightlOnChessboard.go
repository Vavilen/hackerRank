package main

import "fmt"

//https://www.hackerrank.com/challenges/knightl-on-chessboard

func main() {
	var n int
	fmt.Scanf("%d", &n)
	for i:=1; i < n; i++ {
		for j:=1; j < n; j++ {
			fmt.Printf("%d ", bfs(n, i, j))
		}
		fmt.Print("\n")
	}
}

type Queue struct {
	queue [][]int
}

func (q *Queue) enqueue(a int, b int, level int) {
	q.queue = append(q.queue, []int{a, b, level})
}

func (q *Queue) dequeue() []int {
	if len(q.queue) == 0 {
		return nil
	}
	var item []int = q.queue[0]
	q.queue = q.queue[1:]
	return item
}

func (q *Queue) size() int {
	return len(q.queue)
}

type Seen struct {
	seen map[int]map[int]bool
}

func (s *Seen) setSeen(x int, y int) {
	if _, ok := s.seen[x]; !ok {
		s.seen[x] = make(map[int]bool, 0)
	}
	s.seen[x][y] = true
}

func (s *Seen) hasSeen(x int, y int) bool {
	if _, ok := s.seen[x]; ok {
		if _, okk := s.seen[x][y]; okk {
			return true
		}
	}
	return false
}

func bfs(n int, x int, y int) int {
	var cnt int = 0
	var found = false
	queue := &Queue {
		queue: make([][]int, 0),
	}
	seen :=  &Seen{
		seen: make(map[int]map[int]bool, 0),
	}
	queue.enqueue(0, 0, 0)
	LOOP:
	for queue.size() > 0 && !found {
		var item []int = queue.dequeue()
		for _, pair := range [][]int{{x, y}, {y, x}}{
			a := pair[0]
			b := pair[1]
			if item[0] - a >= 0 && item[1] - b >= 0 && !seen.hasSeen(item[0] - a, item[1] - b) {
				if isGoal(n, item[0] - a, item[1] - b) {
					found = true
					cnt = item[2] + 1
					break LOOP
				}
				seen.setSeen(item[0] - a, item[1] - b)
				queue.enqueue(item[0] - a, item[1] - b, item[2] + 1)
			}

			if item[0] + a <= n - 1 && item[1] - b >= 0 && !seen.hasSeen(item[0] + a, item[1] - b) {
				if isGoal(n, item[0] + a, item[1] - b) {
					found = true
					cnt = item[2] + 1
					break LOOP
				}
				seen.setSeen(item[0] + a, item[1] - b)
				queue.enqueue(item[0] + a, item[1] - b, item[2] + 1)
			}

			if item[0] - a >= 0 && item[1] + b <= n - 1 && !seen.hasSeen(item[0] - a, item[1] + b) {
				if isGoal(n, item[0] - a, item[1] + b) {
					found = true
					cnt = item[2] + 1
					break LOOP
				}
				seen.setSeen(item[0] - a, item[1] + b)
				queue.enqueue(item[0] - a, item[1] + b, item[2] + 1)
			}

			if item[0] + a <= n - 1  && item[1] + b <= n - 1 && !seen.hasSeen(item[0] + a, item[1] + b) {
				if isGoal(n, item[0] + a, item[1] + b) {
					found = true
					cnt = item[2] + 1
					break LOOP
				}
				seen.setSeen(item[0] + a, item[1] + b)
				queue.enqueue(item[0] + a, item[1] + b, item[2] + 1)
			}
		}


	}
	if !found {
		return -1
	}
	return cnt
}

func isGoal(n int, x int, y int) bool {
	if x == n - 1 && y == n - 1 {
		return true
	}
	return false
}
