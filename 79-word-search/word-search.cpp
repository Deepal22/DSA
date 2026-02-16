#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        
        vector<int> count(128, 0);
        for (auto& row : board)
            for (char c : row)
                count[c]++;
        
        for (char c : word)
            if (--count[c] < 0)
                return false;
        
        if (count[word[0]] > count[word.back()])
            reverse(word.begin(), word.end());
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, word, i, j, 0))
                    return true;
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        if (k == word.size())
            return true;
        
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[k])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '#';
        
        bool found = dfs(board, word, i + 1, j, k + 1) ||
                     dfs(board, word, i - 1, j, k + 1) ||
                     dfs(board, word, i, j + 1, k + 1) ||
                     dfs(board, word, i, j - 1, k + 1);
        
        board[i][j] = temp;
        return found;
    }
};