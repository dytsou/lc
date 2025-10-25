func minTime(skill []int, mana []int) int64 {
    prefixSum := make([]int, len(skill))
		for i := 0; i < len(mana); i++ {
			for j := len(skill) - 1; j >= 0; j-- {
				prefixSum[j] = mana[i] + prefixSum[j]
			}
		}
}