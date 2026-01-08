class Solution {
public:
    int subArrays(vector<int>& nums, int k) {
        int left = 0, res = 0;

        // Traverse through the array
        for (int right = 0; right < nums.size(); right++) {
            // If current number is odd, reduce k
            if (nums[right] % 2 != 0)
                k--;

            // Shrink the window until k is valid
            while (k < 0) {
                if (nums[left] % 2 != 0)
                    k++;
                left++;
            }

            // Add valid subarrays ending at right
            res += (right - left + 1);
        }

        // Return the count of valid subarrays
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return subArrays(nums, k) - subArrays(nums, k - 1);
    }
};