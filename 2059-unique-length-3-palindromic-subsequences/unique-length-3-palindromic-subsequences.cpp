class Solution {
public:
    int countPalindromicSubsequence(string s) {
        if (s.size() <= 2)
            return 0;
        unordered_set<char> chars(s.begin(), s.end());
        int res = 0;
        for (char c : chars){
            int left = s.find(c);
            int right = s.rfind(c);
            if (left != right){
                unordered_set<char> mid;
                for (int i = left + 1; i < right; i++){
                    mid.insert(s[i]);
                }
                res += mid.size();
            }
        }
        return res;
    }
};