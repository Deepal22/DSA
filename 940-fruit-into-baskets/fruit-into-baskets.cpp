class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        unordered_map<int, int>mpp;

        int i = 0;
        int j = 0;

        int count = 0;

        while(j < n){
            mpp[fruits[j]]++;

            if(mpp.size() <= 2){
                count = max(count, j-i+1);
            } else {
                mpp[fruits[i]]--;
                if(mpp[fruits[i]]  == 0){
                    mpp.erase(fruits[i]);
                }
                i++;
            }

            j++;
        }
        return count;
    }
};