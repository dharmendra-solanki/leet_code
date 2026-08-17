class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        int size = n / 2;
        std::vector<bool> isPrime(size, true);

        isPrime[0] = false;

        for (int i = 1; 2 * i * i + 2 * i < size; i++) {
            if (isPrime[i]) {
                int prime = 2 * i + 1;
                for (int j = 2 * i * i + 2 * i; j < size; j += prime) {
                    isPrime[j] = false;
                }
            }
        }

        int count = 1;
        for (int i = 1; i < size; i++) {
            if (isPrime[i])
                count++;
        }

        return count;
    }
};