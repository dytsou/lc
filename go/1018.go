func prefixesDivBy5(nums []int) []bool {
	curr := 0
	n := len(nums)
	result := make([]bool, n)
	for i, num := range nums {
		curr = (curr*2 + num) % 5
		if curr == 0 {
			result[i] = true
		}
	}
	return result
}
