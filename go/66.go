package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func plusOne(digits []int) []int {
	for i := len(digits) - 1; i >= 0; i-- {
		if digits[i] < 9 {
			digits[i]++
			return digits
		}
		digits[i] = 0
	}
	digits = append([]int{1}, digits...)
	return digits
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := scanner.Text()
	digitsStr := strings.Split(input, " ")
	digits := make([]int, len(digitsStr))
	for i, digitStr := range digitsStr {
		digit, _ := strconv.Atoi(digitStr)
		digits[i] = digit
	}
	result := plusOne(digits)
	fmt.Printf("%v\n", result)
}
