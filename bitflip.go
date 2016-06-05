package main

import (
	"fmt"
	"bytes"
)

func main() {
	var count int
	var item uint32
	var buffer bytes.Buffer
	fmt.Scan(&count)
	if count > 100 {
		count = 100
	}
	for i := 0; i < count; i++ {
		fmt.Scan(&item)
		buffer.WriteString(fmt.Sprintln(^item))
	}

	fmt.Println(buffer.String())
}
