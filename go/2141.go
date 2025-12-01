func maxRunTime(n int, batteries []int) int64 {
	maxTime := int64(0)
	for _, battery := range batteries {
		maxTime += int64(battery)
	}
	return binarySearch(n, batteries, maxTime)
}

func binarySearch(n int, batteries []int, maxTime int64) int64 {
	left, right := int64(0), maxTime
	for left < right {
		mid := left + (right-left+1)/2
		if canRunFor(n, batteries, mid) {
			left = mid
		} else {
			right = mid - 1
		}
	}
	return left
}

func canRunFor(n int, batteries []int, time int64) bool {
	total := int64(0)
	for _, battery := range batteries {
		if int64(battery) < time {
			total += int64(battery)
		} else {
			total += time
		}
	}
	return total >= int64(n)*time
}