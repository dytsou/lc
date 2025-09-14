// Create a vowel mask for a word (replace vowels with '*')
func createVowelMask(word string) string {
	vowels := "aeiouAEIOU"
	result := make([]byte, len(word))
	for i, char := range word {
		if strings.Contains(vowels, string(char)) {
			result[i] = '*'
		} else {
			result[i] = byte(strings.ToLower(string(char))[0])
		}
	}
	return string(result)
}

func spellchecker(wordlist []string, queries []string) []string {
	// Create hash maps for different types of matches
	exactMatch := make(map[string]string)      // exact word -> first occurrence
	caseMatch := make(map[string]string)       // lowercase word -> first occurrence  
	vowelMatch := make(map[string]string)      // vowel mask -> first occurrence
	
	// Preprocess wordlist to create hash maps
	for _, word := range wordlist {
		// Exact match
		if _, exists := exactMatch[word]; !exists {
			exactMatch[word] = word
		}
		
		// Case-insensitive match
		lowerWord := strings.ToLower(word)
		if _, exists := caseMatch[lowerWord]; !exists {
			caseMatch[lowerWord] = word
		}
		
		// Vowel error match
		vowelMask := createVowelMask(word)
		if _, exists := vowelMatch[vowelMask]; !exists {
			vowelMatch[vowelMask] = word
		}
	}
	
	result := make([]string, len(queries))
	
	// Process each query to find the best match
	for i, query := range queries {
		// Priority 1: Exact match
		if match, exists := exactMatch[query]; exists {
			result[i] = match
			continue
		}
		
		// Priority 2: Case-insensitive match
		lowerQuery := strings.ToLower(query)
		if match, exists := caseMatch[lowerQuery]; exists {
			result[i] = match
			continue
		}
		
		// Priority 3: Vowel error match
		queryVowelMask := createVowelMask(query)
		if match, exists := vowelMatch[queryVowelMask]; exists {
			result[i] = match
			continue
		}
		
		// No match found, return empty string
		result[i] = ""
	}
	
	return result
}