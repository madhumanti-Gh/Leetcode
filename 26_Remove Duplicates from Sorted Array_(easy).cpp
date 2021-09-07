class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if( nums.size() == 0 )return 0;
        int p=nums[0], n = 1;
        vector<int>:: iterator it1;
        it1 = nums.begin();it1++;
        while( it1 != nums.end() ){
            if( *it1 == p ){
                nums.erase( it1 );
                it1--;
            }
            else{
                p = *it1;
            }
            it1++;
        }
        cout<<nums.size()<<"\n";
        return nums.size();
    }
};
