class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for( int& it : nums )freq[it]++;
        
        int ans = 0;
        for( auto& x : freq ){
            x.second--;
            if( freq.find( x.first + k ) != freq.end() && freq[x.first+k] > 0 )ans++;
            x.second++;
        }
        return ans;
    }
};
