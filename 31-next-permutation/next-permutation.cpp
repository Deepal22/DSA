class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot=0;
        int index=-1;
        for (int i=0;i<nums.size()-1;i++)
        {
            if (nums[i]<nums[i+1])
            {
                pivot=nums[i];
                index=i;
            }
        }
        int indexswap;
        for (int i=index+1;i<nums.size();i++)
        {
            if (nums[i]>pivot)
            {
                indexswap=i;
            }
        }
        if (index!=-1)
        {
        swap(nums[index], nums[indexswap]);
        reverse(nums.begin()+index+1, nums.end());
        }
        else
            reverse(nums.begin(),nums.end());
    }
};