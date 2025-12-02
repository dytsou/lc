func countTrapezoids(points [][]int) int {
	const mod = 1e9 + 7
	yCounts := make(map[int]int, len(points))
	for _, point := range points {
		yCounts[point[1]]++
	}

	sum, sumSquares := int64(0), int64(0)
	for _, count := range yCounts {
		if count <= 1 {
			continue
		}
		c := int64(count)
		pairs := c * (c - 1) / 2
		sum += pairs
		sumSquares += pairs * pairs
	}

	// Use formula: Σ_{i<j} a_i * a_j = ((Σ a_i)² - Σ a_i²) / 2
	result := (sum*sum - sumSquares) / 2 % mod
	return int(result)
}