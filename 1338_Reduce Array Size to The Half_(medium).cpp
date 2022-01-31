class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        for( int& it : arr )freq[it]++;
        
        priority_queue<int> mxh;
        for( auto& it : freq )mxh.push( it.second );
        
        int ans = 1, count = mxh.top(), half = arr.size()/2;
        mxh.pop();
        while( !mxh.empty() && count < half ){
            ans++;
            count += mxh.top();
            mxh.pop();
        }
        return ans;
    }
};
