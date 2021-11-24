class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(), i = 0, j = -1, temp;
        map<int, int> mp;
        while( i < n ){
            if( arr[i] >= x ){
                break;
            }
            i++;
        }
        if( i == n )j = n-1;
        else if( i > 0 )j = i-1;
        while( k > 0 ){
            if( i < n && j >= 0 ){
                if( abs(arr[i] - x) < abs(arr[j] - x) ){
                    mp[arr[i]]++;
                    i++;k--;
                }
                else{
                    mp[arr[j]]++;
                    j--;k--;
                }
            }
            else if( i < n ){
                mp[arr[i]]++;
                i++;k--;
            }
            else if( j >= 0 ){
                mp[arr[j]]++;
                j--;k--;
            }
        }
        i = 0;
        vector<int> ans;
        while( i < n ){
            if( mp[arr[i]] > 0 ){
                ans.push_back( arr[i] );
                mp[arr[i]]--;
            }
            else i++;
        }
        return ans;
    }
};
