class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++) {
            vector<bool> isPresentRow(9,false);
            vector<bool> isPresentColumn(9,false);
            for(int j=0;j<9;j++) {
                if(board[i][j] != '.') {
                    if(isPresentRow[board[i][j] - '1']) return false;
                    isPresentRow[board[i][j] - '1'] = true;
                }
                if(board[j][i] != '.') {
                    if(isPresentColumn[board[j][i] - '1']) return false;
                    isPresentColumn[board[j][i] - '1'] = true;
                }
            }
        }

        for(int i=0;i<9;i++) {
            vector<bool> isPresentBox(9,false);
            int rowShift = (i/3)*3;
            int columnShift = (i%3)*3;
            for(int j=0;j<3;j++) {
                for(int k=0;k<3;k++) {
                    if(board[rowShift+j][columnShift+k] != '.') {
                        int num = board[rowShift+j][columnShift+k] - '1';
                        if(isPresentBox[num]) return false;
                        isPresentBox[num] = true;
                    }
                }
            }
        }
        return true;
    }
};