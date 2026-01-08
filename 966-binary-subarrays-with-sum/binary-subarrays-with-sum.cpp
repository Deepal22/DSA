class Solution {
public:
    int atmost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int left = 0;
        int n = nums.size();
        int k = goal;
        int ans = 0, sum = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while(sum > k){
                sum = sum - nums[left];
                left++;
            }

            ans += right - left +1;
        }
        return ans;
    }
    

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};