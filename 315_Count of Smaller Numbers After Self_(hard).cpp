class Solution {
public:
    void merge( vector<int>& count, vector< pair<int, int> >& arr, vector< pair<int, int> >& temp, int left, int mid, int right ){
        int i = left, j = mid, k = left;
        while( ( i <= mid-1 ) && ( j <= right ) ){
            if( arr[i].first <= arr[j].first ){
                temp[k] = arr[j];
                k++;j++;
            }
            else{
                temp[k] = arr[i];
                count[arr[i].second] += (right - j +1);
                k++;i++;
            }
        }
        while( i <= mid-1 ){
            temp[k] = arr[i];
            k++;i++;
        }
        while( j <= right ){
            temp[k] = arr[j];
            k++;j++;
        }
        for( i = left; i <= right; i++ ){
            arr[i] = temp[i];
        }
    }
    void MergeSort( vector<int>& count, vector< pair<int, int> >& arr, vector< pair<int, int> >& temp, int left, int right ){
        int mid;
        if( left < right ){
            mid = left + ((right - left)/2 );
            MergeSort( count, arr, temp, left, mid );
            MergeSort( count, arr, temp, mid+1, right );
            merge( count, arr, temp, left, mid+1, right );
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector< pair<int, int> > arr(n), temp(n);
        vector<int> count(n);
        for( int i = 0; i < n; i++ ){
            pair<int, int> p;
            p.first = nums[i];
            p.second = i;
            arr[i] = p;
            count[i] = 0;
            temp[i] = {0,0};
        }
        MergeSort( count, arr, temp, 0, n-1 );
        return count;
    }
};
