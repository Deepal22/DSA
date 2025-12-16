class Solution {
public:
    int trap(vector<int>& height) {
       int n = height.size(); 
       int lMax = 0, rMax = 0, total = 0;
       int l = 0, r = n - 1;

       while(l <= r){
        if(height[l] <= height[r]){
            if(lMax <= height[l]){
                lMax = height[l];    
            } else {
                total += lMax - height[l];
            }
            l++;
        } else {
            if(rMax <= height[r]){
                rMax = height[r];
                
            } else {
                total += rMax - height[r];
            }
            r--;
        }
       } 
       return total;
    }
};