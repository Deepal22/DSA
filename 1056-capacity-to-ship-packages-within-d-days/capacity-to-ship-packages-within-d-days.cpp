class Solution {

    int cntDays(vector<int> &weights, int mid) {

        int cntDays = 0;
        int weightSum = 0;

        for(auto weight: weights) {

            if(weightSum + weight > mid) {
                cntDays++;
                weightSum = 0;
            } 

            weightSum += weight;
        }

        if(weightSum <= mid) cntDays++;

        return cntDays;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = 1;
        int high = 0;
        
        for(auto weight: weights) {
            high += weight;
            low = max(low, weight);
        }

        int ans = -1;
        while(low <= high) {

            int mid = low + (high - low)/2;

            if(cntDays(weights, mid) <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low =  mid + 1;
            }
        }

        return ans;
    }
};