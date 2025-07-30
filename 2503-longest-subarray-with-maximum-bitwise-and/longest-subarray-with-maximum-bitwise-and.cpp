class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int n = nums.size();
       int maxi = *max_element(begin(nums),end(nums));
       int i = 0, j = 0;
       int maxLen = INT_MIN;
       while(j<n){
        if(nums[j] == maxi){
            maxLen = max(maxLen, j - i + 1);
            j++;
        } else {
            j++;
            i = j;
        }
       }
       return maxLen;
    }
};