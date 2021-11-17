class Solution {
public:
    int merge( int arr[], int temp[], int left, int mid, int right ){
        int i = left, j = mid, k = left;
        int rev_cnt = 0;
        for( int m = left; m < mid; m++ ){
            while( j <= right && arr[m] > 2LL* arr[j] ){
                j++;
            }
            rev_cnt += (j-mid);
        }
        i = left, j = mid;
        while( ( i <= mid-1 ) && ( j <= right ) ){
            if( arr[i] <= arr[j] ){
                temp[k] = arr[i];
                k++;i++;
            }
            else{
                temp[k] = arr[j];
                k++;j++;
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
        for( int i = left; i <= right; i++ ){
            arr[i] = temp[i];
        }
        return rev_cnt;
    }
    int MergeSort( int arr[], int temp[], int left, int right ){
        int A = 0, B = 0, rev_cnt = 0, mid = 0;
        if( left < right ){
            mid = ( left + right) /2;
            rev_cnt += MergeSort( arr, temp, left, mid );
            rev_cnt += MergeSort( arr, temp, mid+1, right );
            rev_cnt += merge( arr, temp, left, mid+1, right );
        }
        return rev_cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int temp[n], arr[n];
        for( int i = 0; i < n; i++ ){
            arr[i] = nums[i];
            temp[i] = 0;
        }
        return MergeSort( arr, temp, 0, n-1 );
    }
};
