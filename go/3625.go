type Slope struct {
	Dy, Dx int
}

type Intercept struct {
	Num, Den int
}

type MidKey struct {
	X, Y int
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func normalizeSlope(dx, dy int) Slope {
	if dx == 0 { // Vertical line
		return Slope{1, 0}
	}
	if dy == 0 { // Horizontal line
		return Slope{0, 1}
	}
	if dx < 0 { // Negative slope
		dx, dy = -dx, -dy
	}
	g := gcd(abs(dx), abs(dy))
	dx /= g
	dy /= g
	return Slope{dy, dx}
}

func interceptKey(x, y int, slope Slope) Intercept {
	dy, dx := slope.Dy, slope.Dx
	if dx == 0 { // vertical line: x = const -> use x as "intercept"
		return Intercept{x, 1}
	}
	// y = (dy/dx)*x + b  =>  b = (y*dx - dy*x) / dx
	num := y*dx - dy*x
	den := dx
	if den < 0 { // Negative denominator
		den, num = -den, -num
	}
	g := gcd(abs(num), abs(den))
	if g != 0 { // Reduce fraction
		num /= g
		den /= g
	}
	return Intercept{num, den}
}

func countTrapezoids(points [][]int) int {
	n := len(points)
	if n < 4 {
		return 0
	}

	// slope -> list of intercepts of segments with that slope
	slopeToIntercept := make(map[Slope][]Intercept)

	// midpoint -> list of slopes of segments with that midpoint
	midToSlope := make(map[MidKey][]Slope)

	// Build all segments
	for i := 0; i < n; i++ {
		x1, y1 := points[i][0], points[i][1]
		for j := i + 1; j < n; j++ {
			x2, y2 := points[j][0], points[j][1]

			dx := x2 - x1
			dy := y2 - y1

			k := normalizeSlope(dx, dy)
			b := interceptKey(x1, y1, k)

			slopeToIntercept[k] = append(slopeToIntercept[k], b)

			mid := MidKey{x1 + x2, y1 + y2}
			midToSlope[mid] = append(midToSlope[mid], k)
		}
	}

	ans := int64(0)

	// First pass: count pairs of segments with same slope but different intercept
	for _, vec := range slopeToIntercept {
		if len(vec) < 2 {
			continue
		}

		cnt := make(map[Intercept]int)
		for _, b := range vec {
			cnt[b]++
		}

		sum := int64(0)
		for _, c := range cnt {
			ans += sum * int64(c)
			sum += int64(c)
		}
	}

	// Second pass: subtract parallelogram overcounts via midpoints
	for _, vec := range midToSlope {
		if len(vec) < 2 {
			continue
		}

		cnt := make(map[Slope]int)
		for _, k := range vec {
			cnt[k]++
		}

		sum := int64(0)
		for _, c := range cnt {
			ans -= sum * int64(c)
			sum += int64(c)
		}
	}

	return int(ans)
}

