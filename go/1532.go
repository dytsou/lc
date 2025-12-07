func countOdds(low int, high int) int {
	return (high - low + 1 + low&1) >> 1
}