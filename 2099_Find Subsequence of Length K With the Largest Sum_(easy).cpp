class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans(k,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> minh;
        int i, n = nums.size();
        for( i = 0; i < n; i++ ){
            minh.push({ nums[i], i });
            if( minh.size() > k )minh.pop();
        }
        i = 0;
        while( minh.size() > 0 ){
            ans[i] = minh.top().second;
            i++;
            minh.pop();
        }
        sort( ans.begin(), ans.end() );
        for( i = 0; i < k; i++ ){
            ans[i] = nums[ans[i]];
        }
        return ans;
    }
};
