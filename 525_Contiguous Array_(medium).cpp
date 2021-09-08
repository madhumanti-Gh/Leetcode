class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int max_len = 0, start = 0, i, j,size = nums.size();
    	int presum[size];
    	map<int, pair<int, int> > mp;
	    for( i = 0; i < size; i++ ){
            if( i == 0 ){
                if( nums[i] == 0 )presum[0] = -1;
                else presum[0] = 1;
                continue;
            }
            if( nums[i] == 0 )presum[i] = presum[i-1] -1;
            else presum[i] = presum[i-1] +1;
    		mp[presum[i]].first = -1;
	    	mp[presum[i]].second = -1;
		    if( presum[i] == 0 ){
			    max_len = i+1;
    		}
	    }
    	for( i = 0; i < size; i++ ){
	    	if( mp[presum[i]].first == -1 ){
		    	mp[presum[i]].first = i;
		    }
		    else if( mp[presum[i]].first != -1 ){
			    mp[presum[i]].second = i;
		    }
	    }
	    for( i = 0; i < size; i++ ){
		    if( mp[presum[i]].first != -1 && mp[presum[i]].second != -1 && mp[presum[i]].second - mp[presum[i]].first + 1 > max_len ){
			    max_len = mp[presum[i]].second - mp[presum[i]].first;
			    start = mp[presum[i]].first;
    		}
	    }
        return max_len;
    }
};

// Another soln
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int max_len = 0, start = 0, i, j,size = nums.size();
    	int presum = 0;
    	map<int, int > mp;
	    for( i = 0; i < size; i++ ){
            if( nums[i] == 0 )presum--;
            else presum++;
            if( presum == 0 && i+1 > max_len ){
                max_len = i+1;
                start = 0;
                continue;
            }
            if( mp[presum] == 0 ){
                mp[presum] = i+1;
            }
            else{
                if( max_len < i+1-mp[presum] ){
                    start = mp[presum];     // 1-based index
                    max_len = i+1-mp[presum];
                }
            }
        }
        return max_len;
    }
};
