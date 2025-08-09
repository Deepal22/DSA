class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
    int n=nums.size();
    int maxi=nums[0];

    for (int i=0;i<n;i++) {
        if (nums[i]>maxi) {
            maxi=nums[i];
        }
    }
    int low=1;
    int high=maxi;
    int ans=INT_MAX;
    while (low<=high) {
        int mid=low+(high-low)/2;
        int sum=0;
        for (int i=0;i<n;i++) {
            sum+=ceil((double)nums[i]/mid);
        }
        if (sum<=threshold) {
            ans=min(ans,mid);
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    return ans;
    }
};