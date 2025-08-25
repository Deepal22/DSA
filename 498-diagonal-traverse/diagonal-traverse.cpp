class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        int r, c;
        vector<int> res;
        for (int diagonal = 0; diagonal < row + col - 1; diagonal++) {
            if (diagonal % 2 == 0) {
                // for upward right traverse
                r = min(diagonal, row - 1), c = diagonal - r;
                while (r >= 0 and c < col) {
                    res.push_back(mat[r][c]);
                    r--;
                    c++;
                }
            } else {
                // for downward left traverse
                c = min(diagonal, col - 1), r = diagonal - c;
                while (r < row and c >= 0) {
                    res.push_back(mat[r][c]);
                    r++;
                    c--;
                }
            }
        }
        return res;
    }
};