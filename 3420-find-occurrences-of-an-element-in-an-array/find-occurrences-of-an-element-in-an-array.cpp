class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
    vector<int> ans, index;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == x) index.push_back(i);
    }
    for(auto q: queries) ans.push_back((q-1 < index.size())?index[q-1]: -1);
    return ans;
}
};