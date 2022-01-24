class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size(), i, sum = 0, sum1 = 30001, sum2 = 30002;
        for( i = 0; i < n; i++ ){
            sum+=nums[i];
            if(nums[i]%3==1){
                sum2=min(sum2,nums[i]+sum1);
                sum1=min(sum1,nums[i]);
                
            }
            else if(nums[i]%3==2){
                sum1=min(sum1,sum2+nums[i]);
                sum2=min(sum2,nums[i]);
            }
        }
        if( sum%3 == 0 )return sum;
        if( sum%3 == 1 )return sum - sum1;
        return sum - sum2;
    }
};
