class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int row = grid.size();
        int col = grid[0].size();

        // Directions for up, down, left, right
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // BFS queue, store the position and remaining health
        queue<pair<pair<int, int>, int>> q;

        // DP table to store the maximum health remaining at each cell
        vector<vector<int>> dp(row, vector<int>(col, -1));

        // Start from the top-left corner with the initial health
        q.push({{0, 0}, health - grid[0][0]});
        dp[0][0] = health - grid[0][0];

        while (!q.empty()) {
            auto [pos, currentHealth] = q.front();
            q.pop();
            int x = pos.first;
            int y = pos.second;

            // If we reached the bottom-right corner and still have health left
            if (x == row - 1 && y == col - 1 && currentHealth > 0) {
                return true;
            }

            // Explore all four directions
            for (auto [dx, dy] : directions) {
                int newX = x + dx;
                int newY = y + dy;

                // Check if new position is within bounds
                if (newX >= 0 && newX < row && newY >= 0 && newY < col) {
                    int newHealth = currentHealth - grid[newX][newY];

                    // Only explore if we still have health left and this path is better than previously explored paths
                    if (newHealth > 0 && newHealth > dp[newX][newY]) {
                        dp[newX][newY] = newHealth;
                        q.push({{newX, newY}, newHealth});
                    }
                }
            }
        }
        // If we exhaust the queue without reaching the bottom-right corner with positive health, return false
        return false;
    }
};