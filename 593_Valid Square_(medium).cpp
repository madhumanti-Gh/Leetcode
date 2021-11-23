class Solution {
public:
    int distance( vector<int>& p1, vector<int>& p2 ){
        return (p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> dist;
        dist.push_back( distance( p1, p2 ) );
        dist.push_back( distance( p1, p3 ) );
        dist.push_back( distance( p1, p4 ) );
        dist.push_back( distance( p2, p3 ) );
        dist.push_back( distance( p2, p4 ) );
        dist.push_back( distance( p3, p4 ) );
        map<int, int> mp;
        int side = -1, diag = -1;
        for( auto a: dist ){
            mp[a]++;
        }
        for( auto a: dist ){
            if( (mp[a] != 4 ) && (mp[a] != 2 ) )return false;
            else if( mp[a] == 4 )side = a;
            else if( mp[a] == 2 )diag = a;
        }
        if( ((2* side) == diag ) && (mp[side] == 4) && (mp[diag] == 2) )return true;
        return false;
    }
};
