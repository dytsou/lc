func doesAliceWin(s string) bool {
	return strings.Contains(s, "a") || strings.Contains(s, "e") || strings.Contains(s, "i") || strings.Contains(s, "o") || strings.Contains(s, "u");
}