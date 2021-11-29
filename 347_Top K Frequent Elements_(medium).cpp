class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size(), i;
        for( i = 0; i < n; i++ ){
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
        for( auto x = mp.begin(); x != mp.end(); x++ ){
            minh.push({ x->second, x->first });
            if( minh.size() > k )minh.pop();
        }
        vector<int> ans;
        while( minh.size() > 0 ){
            ans.push_back( minh.top().second );
            minh.pop();
        }
        return ans;
    }
};
