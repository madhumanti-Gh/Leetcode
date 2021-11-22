class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0, k = 0, ele = 0;
        double sum = 0;
        while( i < n && j < m ){
            if( nums1[i] <= nums2[j] ){
                ele = nums1[i];i++;
            }
            else{
                ele = nums2[j];j++;
            }
            if( k == ( n+m-1 )/2 ){
                sum = sum + (double)ele;
            }
            if( k == ( n+m )/2 ){
                sum = sum + (double)ele;
                i = n;j = m;
            }
            k++;
        }
        while( i < n ){
            ele = nums1[i];i++;
            if( k == ( n+m-1 )/2 ){
                sum  = sum + (double)ele;
            }
            if( k == ( n+m )/2 ){
                sum  = sum + (double)ele;
                i = n;
            }
            k++;
        }
        while( j < m ){
            ele = nums2[j];j++;
            if( k == ( n+m-1 )/2 ){
                sum  = sum + (double)ele;
            }
            if( k == ( n+m )/2 ){
                sum  = sum + (double)ele;
                j = m;
            }
            k++;
        }
        return (sum/2);
    }
};
