class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        int n = s.size(), i;
        for( i = 0; i < n; i++ ){
            freq[s[i]]++;
        }
        priority_queue<pair<int, char>> maxh;
        for( auto x:freq ){
            maxh.push({ x.second, x.first });
        }
        string ans = "";
        while( maxh.size() > 0 ){
            i = maxh.top().first;
            while( i-- ){
                ans.push_back( maxh.top().second );
            }
            maxh.pop();
        }
        return ans;
    }
};
