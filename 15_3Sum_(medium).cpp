class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector< vector<int> > ans;
        int i,l,r,B = 0,C,n = nums.size();
        if( n < 3 )return ans;
        
    	sort( nums.begin(), nums.end() );
    	for( i = 0; i < n-2; i++ ){
            if( i == 0 || nums[i] != nums[i-1] ){
    	    	l = i+1;
	    	    r = n-1;
	        	while( l < r ){
                    int sum = nums[i] + nums[l] + nums[r];
                    if( sum == 0 ){
                        ans.push_back( { nums[i], nums[l], nums[r] } );
                        while( l < r && nums[l] == nums[l+1] )l++;
                        while( l < r && nums[r] == nums[r-1] )r--;
                        l++;r--;
                    }
                    if( sum > 0 )r--;
                    if( sum < 0 )l++;
                }
	        }
        }
	    return ans;
    }
};
