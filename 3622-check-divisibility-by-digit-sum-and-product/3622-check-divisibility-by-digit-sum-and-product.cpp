class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        int num = n;
        while(num != 0){
            int digit = num % 10;
            num = num / 10;
            sum = sum + digit;
            prod = prod * digit;
        }
        return n % (sum + prod) == 0;
    }
};