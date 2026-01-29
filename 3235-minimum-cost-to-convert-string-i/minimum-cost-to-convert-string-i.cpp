// struct Node,Edge. Use make_heap over static array
struct Node {
    int d, u;
    bool operator>(const Node& other) const { return d > other.d; }
};

struct Edge { int to, w, nxt; };

// Global storage
Edge E[25*26];// 2 times for the number of edges
int adjList[26];
int eIdx;
static int D[26][26];

static inline void insert(int u, int v, int w) {
    E[eIdx]={v, w, adjList[u]};
    adjList[u]=eIdx++;
}

static Node heap[25*26]; 
int hz=0;

class Solution {
public:
    static void Dijkstra(int x) {
        int* dist=D[x];
        hz=0;
        // add (w, v) for each adjacent vertex of x to heap
        for (int i=adjList[x]; i!=-1; i=E[i].nxt) 
            heap[hz++]={E[i].w, E[i].to};
        
        make_heap(heap, heap+hz, greater<Node>());
        while (hz>0) {
            pop_heap(heap, heap+hz, greater<Node>());
            Node top=heap[--hz];
            
            auto [d, u]=top;
            if (d>dist[u]) continue;

            for (int i=adjList[u]; i!=-1; i= E[i].nxt) {
                int v=E[i].to, w=E[i].w;
                int d2=d+w;
                if (d2 < dist[v]) {
                    dist[v]=d2;
                    heap[hz++]={dist[v], v};
                    push_heap(heap, heap+hz, greater<Node>());
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // Reset globals
        eIdx=0;
        memset(adjList, -1, sizeof(adjList));
        fill(&D[0][0], &D[0][0]+26*26, INT_MAX);
        for (int i=0; i<26; i++) D[i][i]=0;

        const int sz=original.size();
        for (int i= 0; i< sz; i++) {
            int u=original[i]-'a';
            int v=changed[i]-'a';
            if (cost[i]<D[u][v]) D[u][v] = cost[i];
        }


        for (int i=0; i <26; i++) {
            for (int j=0; j <26; j++) {
                if (i != j && D[i][j] != INT_MAX) {
                    insert(i, j, D[i][j]);
                }
            }
        }
        
        for (int i=0; i < 26; i++) 
            Dijkstra(i);
        

        const int n = source.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int row = source[i] - 'a';
            int col = target[i] - 'a';
            if (D[row][col] == INT_MAX) return -1;
            ans += D[row][col];
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}(); 