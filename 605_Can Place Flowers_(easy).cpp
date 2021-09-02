class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        if( n == 0 )return true;
        if( sz < 3 ){
            if( flowerbed[0] == 1 || flowerbed[sz-1] == 1 )return false;
            else if(n == 1)return true;
            else return false;
        }
        if( flowerbed[0] == 0 && flowerbed[1] == 0 ){
                 flowerbed[0] = 1;n--;
            }
        for( int i = 1; i < sz-1; i++ ){
            if( flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0 ){
                 flowerbed[i] = 1;n--;
            }
        }
        if( flowerbed[sz-1] == 0 && flowerbed[sz-2] == 0 ){
             flowerbed[sz-1] = 1;n--;
        }
        if( n > 0 ){
            return false;
        }
        return true;
    }
};

//Another method
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        int count = 0, i = 0;
        while( i < sz ){
            if( flowerbed[i] == 0 && ( i == 0 || flowerbed[i - 1] == 0 ) && ( i == sz-1 || flowerbed[i+1] == 0 ) ){
                flowerbed[i] = 1;count++;
            }
            i++;
        }
        return count >= n;
    }
};
