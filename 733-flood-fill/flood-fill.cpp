class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        int m = image.size();
        int n = image[0].size();

        if (color == originalColor) {
            return image;
        }

        queue<pair<int, int>> q;
        q.push({sr, sc});
        while (q.size() > 0) {
            auto [row, col] = q.front();
            q.pop();

            for (auto [dx, dy] : dirs) {
                int newRow = row + dx;
                int newCol = col + dy;
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && image[newRow][newCol] == originalColor) {
                    q.push({newRow, newCol});
                }
            }
            image[row][col] = color;
        }

        return image;
    }
};