class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i, temp;
        if( n == 1 )return;
        i = n-2;
        while( i >= 0 ){
            if( nums[i] < nums[i+1] ){
                temp = n-1;
                while( temp > i ){
                    if( nums[temp] > nums[i] ){
                        swap( nums[temp], nums[i] );
                        break;
                    }
                    temp--;
                }
                i = i+1;temp = n-1;
                while( i < temp ){
                    swap( nums[temp], nums[i] );
                    i++;temp--;
                }
                return;
            }
            i--;
        }
        i = 0;
        while( i < n/2 ){
            swap( nums[n-1-i], nums[i] );
            i++;
        }
    }
};
