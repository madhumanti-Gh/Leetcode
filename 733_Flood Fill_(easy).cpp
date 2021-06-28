class Solution {
public:
    int n, m;
    void dfs( vector< vector<int> > &image, int sr, int sc, int newColor, int oldColor ){
        if(sr >=0 && sr < n && sc >= 0 && sc < m && image[sr][sc] == newColor )return;
        if( sr >=0 && sr < n && sc >= 0 && sc < m && image[sr][sc] == oldColor ){
            image[sr][sc] = newColor;
            dfs( image, sr , sc + 1 , newColor, oldColor );
            dfs( image, sr , sc - 1 , newColor, oldColor );
            dfs( image, sr + 1 , sc , newColor, oldColor );
            dfs( image, sr - 1 , sc , newColor, oldColor );
            
        }
        else return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        m = image[0].size();
        int oldColor = image[sr][sc];
        dfs( image, sr, sc , newColor, oldColor );
        return image;
    }
};
