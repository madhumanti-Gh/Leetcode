class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int ,int> freq;
        int n = nums.size(), len = 0, max_len = 0, j, i;
        for( i = 0; i < n; i++ ){
            freq[nums[i]]++;
        }
        for( i = 0; i < n; i++ ){
            if( freq.find(nums[i]-1) == freq.end() ){
                j = nums[i];
                len = 0;
                while( freq.find(j) != freq.end() ){
                    len++;
                    j++;
                }
                max_len = max( max_len, len );
            }
        }
        return max_len;
    }
};

// Another (just similar)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int ,int> freq, vis;
        int n = nums.size(), max_len = 0, j, i;
        for( i = 0; i < n; i++ ){
            freq[nums[i]] = 1;
            vis[nums[i]] = 0;
        }
        for( i = 0; i < n; i++ ){
            j = nums[i] +1;
            while( freq.find(j) != freq.end() && !vis[j] ){
                freq[nums[i]]++;
                vis[j] = 1;
                j++;
            }
            j = nums[i] -1;
            while( freq.find(j) != freq.end() && !vis[j] ){
                freq[nums[i]]++;
                vis[j] = 1;
                j--;
            }
        }
        for( i = 0; i < n; i++ ){
            max_len = max( freq[nums[i]], max_len );
        }
        return max_len;
    }
};
