class Solution {
public:
    int countAtMostK(vector<int> &arr, int k) {
        
        int n = arr.size();
        unordered_map<int, int> mp;
        int count = 0;
        int low = 0;
        
        for(int i = 0; i < n; i++){
            
            mp[arr[i]]++;
                
            while(mp.size() > k){
                
                mp[arr[low]]--;
                if(mp[arr[low]] == 0)
                    mp.erase(arr[low]);
                
                low++;
            }
                
            count += (i - low + 1);
        }
        
        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return countAtMostK(nums, k) - countAtMostK(nums, k - 1);
    }
};