class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.size(), i, j = 0, first = 0, sz = 0;
        
        for( i = 0; i <= n; i++ ){
            if( i == n || title[i] == ' ' ){
                if( sz > 2 )title[first] -= 32;
                sz = 0;
                first = i+1;
            }
            else if( title[i] >= 65 && title[i] <= 90 ){
                title[i] += 32;
                sz++;
            }
            else sz++;
        }
        return title;
    }
};
