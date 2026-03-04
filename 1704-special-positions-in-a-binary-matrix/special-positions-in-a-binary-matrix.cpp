class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rowCount(m+1, 0);
        vector<int> colCount(n+1, 0);
        // pre compute the count of 1
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    rowCount[i] +=1;
                    colCount[j] +=1;
                }
            }
        }
        // now traversing once again
        int total = 0;
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(mat[row][col] == 1 && rowCount[row] <= 1 && colCount[col] <= 1){
                    total++;
                    
                }
            }
        }
        return total;
    }
};