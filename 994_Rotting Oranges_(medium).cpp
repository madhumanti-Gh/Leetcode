class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0){
            return 0;
        }
        queue< pair<int, int> > q;
        int fresh = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(q.empty()){
            if(fresh != 0){
                return -1;
            }
            else{
                return 0;
            }
        }
        
        int t = 0;
        while(!q.empty()){
        t++;
        int y = q.size();
        for(int k = 0;k<y;k++){
            pair<int, int> x = q.front();
            
            if( x.first < grid.size()-1 && grid[x.first+1][x.second] == 1 ){
                q.push({ x.first+1, x.second });
                grid[x.first+1][x.second] = 2;
                fresh--;
            }
            if( x.first > 0 && grid[x.first-1][x.second] == 1 ){
                q.push({ x.first-1, x.second });
                grid[x.first-1][x.second] = 2;fresh--;
            }
            if( x.second < grid[0].size()-1 && grid[x.first][x.second+1] == 1 ){
                q.push({ x.first, x.second+1 });
                grid[x.first][x.second+1] = 2;fresh--;
            }
            if( x.second > 0 && grid[x.first][x.second-1] == 1 ){
                q.push({ x.first, x.second-1 });
                grid[x.first][x.second-1] = 2;fresh--;
            }
            q.pop();
        }
        }
        if(fresh != 0){
            return -1;
        }
        else{
            return t-1;
        }
    }
};
