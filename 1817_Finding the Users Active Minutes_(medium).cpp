class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, set<int>> mp;
        vector<int> answer( k, 0 );
        
        int n = logs.size(), i;
        for( i = 0; i < n; i++ ){
            mp[logs[i][0]].insert( logs[i][1] );
        }
        
        for( auto& c : mp ){
            n = c.second.size();
            answer[n-1]++;
        }
        return answer;
    }
};
