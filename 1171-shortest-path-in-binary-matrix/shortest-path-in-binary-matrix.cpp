class Solution {
public:
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n  = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({2+n-1,{0,0}});
        grid[0][0] = 2;
        
        vector<int> dx = {-1,-1,-1, 0, 1, 1, 1, 0};
        vector<int> dy = {-1, 0, 1, 1, 1, 0,-1,-1};
        while(!pq.empty()){
            pair<int,pair<int,int>> curr = pq.top();
            pq.pop();

            int curr_i = curr.second.first;
            int curr_j = curr.second.second;
            int curr_val = curr.first;

            if(curr_i == n-1 && curr_j == n-1) return curr_val-1;
            if(curr_val > grid[curr_i][curr_j] + max(n-1-curr_i,n-1-curr_j)) continue;

            for(int i = 0; i < 8;i++){
                int next_i = dx[i] + curr_i;
                int next_j = dy[i] + curr_j;

                if(next_i < 0 || next_i >= n || next_j < 0 || next_j >= n) continue;
                if(grid[next_i][next_j] == 1) continue;


                int next_val = grid[curr_i][curr_j]+1 + max(n-1-next_i,n-1-next_j);
                if(grid[next_i][next_j] == 0 || grid[curr_i][curr_j]+1 < grid[next_i][next_j]){
                    pq.push({next_val,{next_i,next_j}});
                    grid[next_i][next_j] = grid[curr_i][curr_j]+1;
                }
            }
        }
        return grid[n-1][n-1] > 1 ? grid[n-1][n-1] : -1;
    }
};