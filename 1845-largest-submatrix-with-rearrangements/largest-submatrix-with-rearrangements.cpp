class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int j = 0; j < m; j++){
            int sum = 0;
            for(int i = 0 ; i < n ; i++){
                if(matrix[i][j] == 0 ) sum=0;
                else{
                    sum++;
                    matrix[i][j] = sum;
                } 
            }
        }
        int res = 0;
        for(int i = 0 ; i < n; i++){
            sort(matrix[i].begin(), matrix[i].end(), greater<>());
            int minv=INT_MAX;
            for(int j = 0 ; j < m; j++){
                minv = min(minv, matrix[i][j]);
                res = max(res, (j+1)*minv);
            }
        }
        return res;
    }
};