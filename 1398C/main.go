package main

import (
	"bufio"
	"fmt"
	"os"
)

func I(c byte) int {
	return int(c - '0')
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		var n int
		var s string

		fmt.Fscan(in, &n)
		fmt.Fscan(in, &s)

		mp := make(map[int]int)
		mp[0] = 1

		prefix := 0

		for i := 0; i < n; i++ {
			prefix += I(s[i])
			mp[prefix-i-1]++
		}

		var ans int64

		for _, v := range mp {
			v := int64(v)
			ans += v * (v - 1) / 2
		}

		fmt.Fprintln(out, ans)
	}
}
