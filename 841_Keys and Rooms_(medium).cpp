class Solution {
public:
    void dfs( vector<vector<int>>& rooms, vector<bool>& vis, int idx, int& k ){
        int n = rooms.size(), i, sz = rooms[idx].size();
        if( k == n )return;
        for( i = 0; i < sz; i++ ){
            if( rooms[idx][i] == idx )continue;
            if( !vis[rooms[idx][i]] ){
                vis[rooms[idx][i]] = true;
                k += 1;
                dfs( rooms, vis, rooms[idx][i], k );
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), i, j, sz, k = 1;
        vector<bool> vis(n, false );
        vis[0] = true;
        dfs( rooms, vis, 0, k );
        if( k == n )return true;
        return false;
    }
};
