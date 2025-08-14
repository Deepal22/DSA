class Solution {
public:
    int countArray(vector<int>& nums, int sum){
        int array = 1;
        long long sumArr = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sumArr + nums[i] <= sum){
                sumArr += nums[i];
            } else{
                array += 1;
                sumArr = nums[i];
            }
        }
        return array;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        if(k == 1) return high;
        if(k == n) return low;

        while(low <= high){
            int mid = (low+high)/2;
            int array = countArray(nums, mid);

            if(array > k){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};