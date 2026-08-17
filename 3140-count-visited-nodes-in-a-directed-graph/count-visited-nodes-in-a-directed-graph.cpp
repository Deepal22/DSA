class Solution {
private:
    void fillCycle(vector<int>& edges, vector<bool>& visited, vector<int>& result, int start) {
        int length = 0;
        for (int x = start; !visited[x]; x = edges[x]) {
            visited[x] = true;
            length++;
        }
        result[start] = length;
        for (int x = edges[start]; x != start; x = edges[x]) {
            result[x] = length;
        }
    }
    
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> indegree(n), result(n);
        vector<bool> visited(n);
        queue<int> q;
        stack<int> s;
        for (int e: edges) {
            indegree[e]++;
        }
        for (int i = 0; i < n; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int x = q.front(); q.pop();
            s.push(x);
            visited[x] = true;
            if (!--indegree[edges[x]]) {
                q.push(edges[x]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                fillCycle(edges, visited, result, i);
            }
        }
        while (!s.empty()) {
            int x = s.top(); s.pop();
            result[x] = result[edges[x]] + 1;
        }
        return result;
    }
};