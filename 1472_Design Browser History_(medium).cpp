class BrowserHistory {
    vector<string> vec;
    int cur;
public:
    BrowserHistory(string homepage) {
        cur = 0;
        vec.push_back(homepage);
    }
    
    void visit(string url) {
        while( cur +1 < vec.size() ){
            vec.pop_back();
        }
        cur++;
        vec.push_back(url);
    }
    
    string back(int steps) {
        if( cur - steps < 0 ){
            cur = 0;
        }
        else{
            cur = cur - steps;
        }
        return vec[cur];
    }
    
    string forward(int steps) {
        if( cur + steps >= vec.size() ){
            cur = vec.size() -1;
        }
        else{
            cur = cur + steps;
        }
        return vec[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
