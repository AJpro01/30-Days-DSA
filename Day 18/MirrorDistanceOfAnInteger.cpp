class Solution {
public:
    int reverse(int n){
        int result = 0;
        while(n){
            int rem = n%10;
            result = (result*10) + rem;
            n= n/10;
        }
        return result;
    }
    int mirrorDistance(int n) {
        return(abs(n - reverse(n)));
    }
};