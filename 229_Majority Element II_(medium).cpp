class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int Mele1 = -1, Mele2 = -1;
        int n = nums.size(), cnt1 = 0, cnt2 = 0, i = 0;
        for( int i = 0; i < n; i++ ){
            if( Mele1 == nums[i] )cnt1++;
            else if( Mele2 == nums[i] )cnt2++;
            else if( cnt1 == 0 ){
                Mele1 = nums[i];
                cnt1++;
            }
            else if( cnt2 == 0 ){
                Mele2 = nums[i];
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        cout<<Mele1<<" "<<Mele2<<endl;
        for( int i = 0; i < n; i++ ){
            if( nums[i] == Mele1 )cnt1++;
            else if( nums[i] == Mele2 )cnt2++;
            if( cnt1 > n/3 ){
                ans.push_back(Mele1);
                cnt1 = -1;
            }
            if( cnt2 > n/3 ){
                ans.push_back(Mele2);
                cnt2 = -1;
            }
        }
        return ans;
    }
};
