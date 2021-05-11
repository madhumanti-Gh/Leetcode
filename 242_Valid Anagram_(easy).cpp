class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.size() != t.size() ){
            return false;
        }
        map<char, int> fr;
        for(int i=0; i<s.size(); i++){
            fr[s[i]]++;
            fr[t[i]]--;
        }
        for(auto x:fr){
            if( x.second != 0 ){
                return false;
            }
        }
        return true;
    }
};
