package main

import (
	"fmt"
)

func findDifference(nums1 []int, nums2 []int) [][]int {
	s1 := make(map[int]bool)
	for _, n := range nums1 {
		s1[n] = true
	}
	s2 := make(map[int]bool)
	for _, n := range nums2 {
		s2[n] = true
	}

	ans := make([][]int, 2)
	for key := range s1 {
		if !s2[key] {
			ans[0] = append(ans[0], key)
		}
	}
	for key := range s2 {
		if !s1[key] {
			ans[1] = append(ans[1], key)
		}
	}
	return ans
}

func main() {
	fmt.Printf("%v\n", findDifference([]int{1, 2, 3}, []int{2, 4, 6}))
	fmt.Printf("%v\n", findDifference([]int{1, 2, 3, 3}, []int{1, 1, 2, 2}))
}