class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int hash[256]; 

        for (int i = 0; i < 256; ++i) {
            hash[i] = -1;
        }

        int l = 0;
        int r = 0;
        int maxLen = 0;
        int n = s.size();

        while(r < n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }
            }

            int len = r - l + 1;
            maxLen = max(maxLen, len);

            hash[s[r]] = r;
            r++;
        }
        return maxLen; 
    }
};