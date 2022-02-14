class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        pattern_to_words = dict()
        words_int = 0
        for pattern_letter in pattern:
            if pattern_letter in pattern_to_words:
                if pattern_to_words[pattern_letter] != words[words_id]:
                    return false;
            else:
                pattern_to_words.add({pattern_letter : words[words_id]})
            words_id += 1    
            
        return true