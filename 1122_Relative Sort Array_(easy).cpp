class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        map<int, int> freq;
        int n = arr2.size(), i;
        for( auto i : arr1 )freq[i]++;
        for( auto i : arr2 ){
            while( freq[i]-- ){
                ans.push_back( i );
            }
        }
        for( auto i : freq ){
            while( i.second > 0 ){
                ans.push_back( i.first );
                i.second--;
            }
        }
        return ans;
    }
};
