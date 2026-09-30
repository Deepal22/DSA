class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         unordered_map<string, vector<string>> freq;
        vector<vector<string>> ans;
        
        for (int i = 0; i < strs.size(); i++) {
            string word = strs[i];
            sort(word.begin(), word.end());
            freq[word].push_back(strs[i]);
        }

        for (auto &[key, group] : freq) {
            ans.push_back(group);
        }

        return ans;
    }
};