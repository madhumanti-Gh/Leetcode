class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        int idxSum = -1, i, id;
        int n = list1.size();
        int m = list2.size();
        for( i = 0; i < n; i++ )mp[ list1[i] ] = i;
        vector<string> ans;
        for( i = 0; i < m; i++ ){
            if( mp.find( list2[i] ) != mp.end() ){
                id = mp[ list2[i] ] + i;
                if( idxSum == -1 ){
                    idxSum = id;
                    ans.push_back( list2[i] );
                }
                else if( idxSum == id ){
                    ans.push_back( list2[i] );
                }
                else if( idxSum > id ){
                    ans.clear();
                    ans.push_back( list2[i] );
                    idxSum = id;
                }
            }
        }
        return ans;
    }
};
