package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func swap(nums []int, i, j int) {
	nums[i], nums[j] = nums[j], nums[i]
}

func removeElement(nums []int, val int) int {
	count := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] != val {
			nums[count] = nums[i]
			count++
		}
	}
	return count
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := scanner.Text()
	numsStr := strings.Split(input, " ")
	nums := make([]int, len(numsStr))
	for i, numStr := range numsStr {
		num, _ := strconv.Atoi(numStr)
		nums[i] = num
	}
	scanner.Scan()
	valStr := scanner.Text()
	val, _ := strconv.Atoi(valStr)
	result := removeElement(nums, val)
	fmt.Println(result)
}
