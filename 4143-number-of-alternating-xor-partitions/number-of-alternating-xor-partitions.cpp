class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        int n = nums.size();
        const int mod = 1e9 + 7;
        long long ways0 = 1;
        long long ways1 = 0;
        long long ways2 = 0;
        long long ways3 = 0;
        long long ans=0;
        int curr=0;
        for(int i=0;i<n;i++){
            curr ^= nums[i];
            long long add0=0, add1=0, add2=0,add3=0;
            //cycle is 0->T1->T1^T2->T2->0
            if(curr==target1){
                add1 = ways0;
            }
            if(curr==( (target1)^(target2))){
                add2 = ways1;
            }
            if(curr == target2){
                add3 = ways2;
            }
            if(curr==0){
                add0 = ways3;
            }
            ways0 = (ways0+add0)%mod;
            ways1 = (ways1+add1)%mod;
            ways2 = (ways2+add2)%mod;
            ways3 = (ways3+add3)%mod;
            if(i==n-1){
                ans = (add0+add1+add2+add3)%mod;
            }
            
        }
        return ans;
    }
};