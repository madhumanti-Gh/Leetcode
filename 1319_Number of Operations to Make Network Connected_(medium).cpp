class Solution {
private:
    void dfs( int n, vector<int> adj[], vector<bool>& vis, int id ){
        int sz = adj[id].size(), i;
        vis[id] = true;
        for( i = 0; i < sz; i++ ){
            if( vis[adj[id][i]] == false ){
                dfs( n, adj, vis, adj[id][i] );
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<bool> vis( n, false);
        vector<int> adj[n];
        int sz = connections.size(), i, cable_required = n-1, connect = 0;
        if( cable_required > sz )return -1;
        for( i = 0; i < sz; i++ ){
            adj[connections[i][0]].push_back( connections[i][1] );
            adj[connections[i][1]].push_back( connections[i][0] );
        }
        for( i = 0; i < n; i++ ){
            if( vis[i] == false ){
                dfs( n, adj, vis, i );
                connect++;
            }
        }
        return connect-1;
    }
};
