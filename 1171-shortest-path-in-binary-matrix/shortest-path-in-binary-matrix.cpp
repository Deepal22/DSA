class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        // Start or destination is blocked
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        // 8 possible directions
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        queue<pair<int, int>> q;

        // Start BFS from (0, 0)
        q.push({0, 0});

        // Use grid itself as visited + distance
        // Starting cell has distance 1
        grid[0][0] = 1;

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            int distance = grid[r][c];

            // Reached destination
            if (r == n - 1 && c == n - 1)
                return distance;

            // Explore all 8 directions
            for (int d = 0; d < 8; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                // Check boundaries and whether the cell is clear/unvisited
                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 0) {

                    // Store distance and mark as visited
                    grid[nr][nc] = distance + 1;

                    q.push({nr, nc});
                }
            }
        }

        // No clear path exists
        return -1;
    }
};