package go

func countPartitions(nums []int) int {
	total := 0
	for _, num := range nums {
		total += num
	}
	if total % 2 == 0 {
		return len(nums) - 1
	}
	return 0
}