class Solution {
public:
    struct compare{
        bool operator()( pair<int, int> a, pair<int, int> b ){
            if( a.first == b.first ){
                return a.second<b.second;
            }
            return a.first > b.first;
        }
    };
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size(), i;
        for( i = 0; i < n; i++ ){
            freq[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> minh;
        for( auto x:freq ){
            minh.push({ x.second, x.first });
        }
        vector<int> ans;
        while( minh.size() > 0 ){
            i = minh.top().first;
            while( i-- ){
                ans.push_back( minh.top().second );
            }
            minh.pop();
        }
        return ans;
    }
};
