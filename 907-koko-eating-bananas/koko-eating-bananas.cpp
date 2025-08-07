class Solution {
public:
bool check(int mid,vector<int>& piles, int h){
    int count=0;
    int n=piles.size();
    for(int i=0;i<n;i++){
    if(count>h) return false;
    if(piles[i]<=mid) count++;
    else if(piles[i]%mid ==0) count+=piles[i]/mid;
     else count+=piles[i]/mid +1;
    }          
    if(count>h) return false;
    else return true;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=INT_MIN;
        int ans=-1;
        
        for(int i=0;i<n;i++){
            if(high<piles[i]) high=piles[i];
        }
        while(low<=high){
            int mid=low+(high-low)/2;
        if(check( mid,piles, h)){
            ans=mid;
            high=mid-1;

        }
        else{
            low=mid+1;
        }
        }
        return ans;
    }
};