class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        const int n = s.size();
        const int numWords = words.size();
        const int wordSize = words[0].size();
        unordered_map<string_view, int> goal;
        ranges::for_each(words, [&](const string& word) { goal[word]++; });
        for (int i = 0; i < wordSize; i++) { // O(wordSize * )
            unordered_map<string_view, int> curr;
            int wordsFound = 0;
            int l = i;
            for (int r = l; r <= n - wordSize; r += wordSize) {
                string_view word(s.data() + r, wordSize);
                if (goal.contains(word)) {
                    curr[word]++;
                    while (curr[word] > goal[word]) {
                        string_view lstring(s.data() + l, wordSize);
                        curr[lstring]--;
                        l += wordSize;
                        wordsFound--;
                    }
                    wordsFound++;
                    if (wordsFound == numWords) {
                        result.push_back(l);
                        string_view lstring(s.data() + l, wordSize);
                        curr[lstring]--;
                        l += wordSize;
                        wordsFound--;
                    }
                } else {
                    curr.clear();
                    wordsFound = 0;
                    l = r + wordSize;
                }
            }
        }
        return result;
    }
};