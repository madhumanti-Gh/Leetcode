class Solution {
public:
    struct compare{
        bool operator()( pair<int, string> a, pair<int, string> b ){
            if( a.first == b.first ){
                return a.second<b.second;
            }
            return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        int n = words.size(), i;
        for( i = 0; i < n; i++ ){
            freq[words[i]]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, compare> minh;
        for( auto x:freq ){
            minh.push({ x.second, x.first });
            if( minh.size() > k )minh.pop();
        }
        vector<string> ans;
        while( minh.size() > 0 ){
            ans.push_back( minh.top().second );
            minh.pop();
        }
        reverse( ans.begin(), ans.end() );
        return ans;
    }
};
