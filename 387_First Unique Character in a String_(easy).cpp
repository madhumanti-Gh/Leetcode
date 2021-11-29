class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;
        int n = s.size(), i;
        for( i = 0; i < n; i++ ){
            freq[s[i]]++;
        }
        for( i = 0; i < n; i++ ){
            if( freq[s[i]] == 1 )return i;
        }
        return -1;
    }
};

// using min-heap
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;
        int n = s.size(), i;
        for( i = 0; i < n; i++ ){
            freq[s[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
        for( i = 0; i < n; i++ ){
            minh.push({ freq[s[i]], i });
        }
        int count = 0;
        if( minh.top().first == 1 ){
            return minh.top().second;
        }
        return -1;
    }
};
