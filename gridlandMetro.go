package main

import (
	"fmt"
	"sort"
)

//https://www.hackerrank.com/challenges/gridland-metro/problem

type Interval struct {
	start int64
	stop  int64
}

type stack struct {
	capacity int64
	s        []Interval
}

func (s *stack) Len() int {
	return len(s.s)
}

func (s *stack) Swap(i, j int) {
	s.s[i], s.s[j] = s.s[j], s.s[i]
}

func (s *stack) Less(i, j int) bool {
	return s.s[i].start < s.s[j].start
}

func (s *stack) Push(interval Interval) {
	s.s = append(s.s[:len(s.s)], interval)
}

func (s *stack) Pop() (Interval) {
	l := len(s.s)
	res := (s.s)[l-1]
	s.s = (s.s)[0:l-2]
	return res
}

func (s *stack) PrintGapsCount() {
	var cnt int64 = s.capacity
	for i := 0; i < len(s.s); i++ {
		cnt -= s.s[i].stop + 1 - s.s[i].start
	}
	fmt.Printf("%d\n", cnt)
}

func main() {
	var rowCount int64
	var columnCount int64
	var trainTracksCount int
	fmt.Scanf("%d %d %d\n", &rowCount, &columnCount, &trainTracksCount)
	s := &stack{
		capacity: rowCount * columnCount,
		s:        make([]Interval, 0),
	}
	for i := 0; i < trainTracksCount; i++ {
		var rowNumber int64
		var startColumnNumber int64
		var stopColumnNumber int64
		fmt.Scanf("%d %d %d\n", &rowNumber, &startColumnNumber, &stopColumnNumber)
		var interval = Interval{
			start: (rowNumber-1)*columnCount + startColumnNumber,
			stop:  (rowNumber-1)*columnCount + stopColumnNumber,
		}
		s.Push(interval)
	}
	sort.Sort(s)
	ss := mergeIntervals(s)
	ss.PrintGapsCount()
}

func mergeIntervals(s *stack) (*stack) {
	ss := &stack{
		capacity: s.capacity,
		s:        make([]Interval, 0),
	}
	for i := 0; i < len(s.s); i++ {
		ssLen := len(ss.s)
		if ssLen > 0 {
			var merged bool = false
			if s.s[i].start - (ss.s)[ssLen - 1].stop <= 1 {
				if s.s[i].stop > (ss.s)[ssLen - 1].stop {
					(ss.s)[ssLen - 1].stop = s.s[i].stop
				}
				merged = true
			}

			if !merged {
				ss.Push(s.s[i])
			}
		} else {
			ss.Push(s.s[i])
		}
	}
	return ss
}
