// O(n) Time complexity, O(n) Space complexity, Using queue
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size(), i;
        if( n%2 == 1 )return {};
        sort( changed.begin(), changed.end() );
        vector<int> ans;
        queue<int> q;
        for( i = 0; i < n; i++ ){
            if( !q.empty() && q.front() == changed[i] )q.pop();
            else{
                q.push( 2* changed[i] );
                ans.push_back( changed[i] );
            }
        }
        if( q.empty() )return ans;
        return {};
    }
};

// Another approach, Using map
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if( n%2 != 0 )return {};
        int max_ele = INT_MIN;
        int freq[100001];
        memset( freq, 0, sizeof(freq) );
        for( int i = 0; i < n; i++ ){
            freq[changed[i]]++;
            max_ele = max( max_ele, changed[i] );
        }
        if( freq[0]%2 != 0 )return {};
        vector<int> ans;
        for( int i = 0; i < 100001; i++ ){
            while( freq[i] > 0 && (i*2) < 100001 && freq[2*i] > 0 ){
                freq[i]--;
                freq[2*i]--;
                ans.push_back(i);
            }
        }
        for( int i = 1; i <= max_ele; i++ ){
            if( freq[i] > 0 )return {};
        }
        return ans;
    }
};
