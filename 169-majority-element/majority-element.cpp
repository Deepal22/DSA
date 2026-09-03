class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int element;
        for(int i = 0; i < n; i++){
            if(cnt == 0) element = nums[i];
            if(nums[i] == element) cnt++;
            else cnt--;
        }
        return element;
    }
};