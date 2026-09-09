class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        long long start = 1000;
        if (n < 1000)
            return 0;
        else {
            while (start <= n) {
                totalCommas += (n - start + 1);
                start *= 1000;
            }
        }
        return totalCommas;
    }
};