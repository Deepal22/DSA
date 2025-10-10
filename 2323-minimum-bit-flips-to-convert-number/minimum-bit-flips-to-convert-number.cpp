class Solution {
public:
    int minBitFlips(int start, int goal) {
        int num = start ^ goal;
        int ans = 0;

        while(num > 0){
            ans += num & 1;
            num >>= 1;
        }
        return ans;
    }
};