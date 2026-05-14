class Solution {
    static inline int P[201];
    static inline int vers = 0;
public:
    bool isGood(vector<int>& nums) {
        vers++;
        int max = nums.size() - 1;
        for (auto& n : nums) {
            if (n > max || P[n] == -vers)
                return false;

            if (P[n] == vers) {
                if (n != max)
                    return false;
                P[n] = -vers;
            } else
                P[n] = vers;
        }
        
        return true;
    }
};