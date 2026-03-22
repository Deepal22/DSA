class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n * 6 < m || m * 6 < n) return -1;
        int sum1 = accumulate(nums1.begin() , nums1.end() , 0);
        int sum2 = accumulate(nums2.begin() , nums2.end() , 0);
        if(sum1 == sum2) return 0;
        if(sum1 > sum2){
            swap(nums1 , nums2);
            swap(n , m);
        }
        int cnt[6] = {0};
        for(int i = 0; i < n; ++i) ++cnt[6 - nums1[i]];
        for(int i = 0; i < m; ++i) ++cnt[nums2[i] - 1];
        int diff = abs(sum1 - sum2), res = 0;
        for(int i = 5; i && diff > 0; --i){
            int take = min(cnt[i] , (diff - 1) / i + 1);
            diff -= take * i;
            res += take;
        }
        return res;
    }
};