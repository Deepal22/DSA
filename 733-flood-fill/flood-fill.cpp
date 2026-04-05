class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int color2replace = image[sr][sc];

        auto dfs = [&](auto&& self, int i, int j) -> void {
            visited[i][j] = true;
            image[i][j] = color;

            for (auto& [dx, dy] : dir) {
                int x = i + dx;
                int y = j + dy;

                if (x < 0 || x >= n || y < 0 || y >= m ||
                    image[x][y] != color2replace || visited[x][y]) {
                    continue;
                }

                self(self, x, y);
            }
        };

        dfs(dfs, sr, sc);
        return image;
    }
};