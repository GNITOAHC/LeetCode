func maxVowels(s string, k int) int {
    isVowel := func(c byte) bool {
        if c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' {
            return true
        }
        return false
    }

    front, end, vowel_counter := 0, k, 0

    for i := 0; i < k; i++ {
        if isVowel(s[i]) { vowel_counter++ }
    }

    max := vowel_counter

    for i := 0; i < len(s); i++ {
        if end >= len(s) { break }
        if isVowel(s[front]) { vowel_counter-- }
        if isVowel(s[end]) { vowel_counter++ }
        front++
        end++
        if max < vowel_counter { max = vowel_counter }
    }

    return max
}