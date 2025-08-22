class Solution {
public:
    int maxEle(vector<vector<int>>&mat , int mid){
        int maxvalue = -1;
        int index = -1;
        int n = mat.size();
        for(int i=0;i<n;i++){
            if(mat[i][mid]>maxvalue){
                maxvalue = mat[i][mid];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low =0;
        int high = mat[0].size();
        while(low<=high){
            int mid = low + (high-low)/2;
            int row = maxEle(mat,mid);
            int left = mid-1 >=0 ? mat[row][mid-1] : -1;
            int right = mid+1 < mat[0].size() ? mat[row][mid+1] : -1;
            if(mat[row][mid]>left && mat[row][mid]>right ){
                return {row,mid};
            }
            else if(mat[row][mid]<left){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return {-1,-1};
    }
};