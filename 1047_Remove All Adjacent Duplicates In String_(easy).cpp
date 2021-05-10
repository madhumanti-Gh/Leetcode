class Solution {
public:
    string removeDuplicates(string S) {
        deque<char> dq;
        int i = 0;
        for(int i=0;i<S.size();i++){
            if(dq.empty() ){
                dq.push_back( S[i] );
            }
            else{
                if( S[i] == dq.back() ){
                    dq.pop_back();
                }
                else{
                    dq.push_back(S[i]);
                }
            }
        }
        string p = "";
        while( !dq.empty() ){
            p.push_back( dq.front() );
            dq.pop_front();
        }
        return p;
    }
};
