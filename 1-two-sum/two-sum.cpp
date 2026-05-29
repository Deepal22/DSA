class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mpp;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int complement = target - nums[i];
            if(mpp.count(complement)){
                return{mpp[complement], i};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};