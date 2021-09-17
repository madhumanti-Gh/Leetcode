class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0, k = 0, l = 0;
        string s = word1[k], t = word2[l];
        char A,B;
        int C = s.size(), D = t.size();
        while( k < word1.size() || l < word2.size() ){
            if( i < s.size() && j < t.size() ){
                A = s[i];i++;
                B = t[j];j++;
                if( A != B )return false;
            }
            else{
                if( i >= s.size() ){
                    i = 0;
                    k++;
                    if( k < word1.size() ){
                        s = word1[k];
                        C += s.size();
                    }
                }
                if( j >= t.size() ){
                    j = 0;
                    l++;
                    if( l < word2.size() ){
                        t = word2[l];
                        D += t.size();
                    }
                }
            }
        }
        if( C != D )return false;
        return true;
    }
};
