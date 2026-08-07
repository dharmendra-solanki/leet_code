class Solution {
private:
    // factors[d] = powers of {2,3,5,7}
    int f[10][4] = {
        {0,0,0,0}, // 0
        {0,0,0,0}, // 1
        {1,0,0,0}, // 2
        {0,1,0,0}, // 3
        {2,0,0,0}, // 4
        {0,0,1,0}, // 5
        {1,1,0,0}, // 6
        {0,0,0,1}, // 7
        {3,0,0,0}, // 8
        {0,2,0,0}  // 9
    };

    void use(vector<int>& need, int d) {
        for (int i = 0; i < 4; i++) {
            need[i] = max(0, need[i] - f[d][i]);
        }
    }

    // Minimum digits required for 2^a * 3^b
    int min23(int a, int b) {
        int ans = 1e9;

        for (int six = 0; six <= min(a, b); six++) {

            int x = a - six;
            int y = b - six;

            // 8 = 2^3
            int cnt8 = (x + 2) / 3;

            // 9 = 3^2
            int cnt9 = (y + 1) / 2;

            ans = min(ans, six + cnt8 + cnt9);
        }

        return ans;
    }

    int minDigits(const vector<int>& need) {
        return min23(need[0], need[1])
             + need[2]
             + need[3];
    }

    bool possible(const vector<int>& need, int slots) {
        return minDigits(need) <= slots;
    }

    string build(vector<int> need, int len) {

        string ans;
        ans.reserve(len);

        for (int i = 0; i < len; i++) {

            for (int d = 1; d <= 9; d++) {

                vector<int> nxt = need;
                use(nxt, d);

                if (possible(nxt, len - i - 1)) {
                    ans.push_back(char('0' + d));
                    need = nxt;
                    break;
                }
            }
        }

        return ans;
    }

public:
    string smallestNumber(string num, long long t) {

        // --------------------------------
        // 1. Factorize t
        // --------------------------------

        vector<int> need(4, 0);

        while (t % 2 == 0) {
            need[0]++;
            t /= 2;
        }

        while (t % 3 == 0) {
            need[1]++;
            t /= 3;
        }

        while (t % 5 == 0) {
            need[2]++;
            t /= 5;
        }

        while (t % 7 == 0) {
            need[3]++;
            t /= 7;
        }

        // Prime factor other than 2,3,5,7
        if (t != 1)
            return "-1";

        int n = num.size();

        // --------------------------------
        // 2. Check num itself
        // --------------------------------

        vector<int> cur = need;
        bool hasZero = false;

        for (char c : num) {
            int d = c - '0';

            if (d == 0) {
                hasZero = true;
                break;
            }

            use(cur, d);
        }

        if (!hasZero && minDigits(cur) == 0)
            return num;


        // --------------------------------
        // 3. Prefix factor counts
        // --------------------------------

        vector<array<int, 4>> pref(n + 1);
        pref[0] = {0, 0, 0, 0};

        // IMPORTANT:
        // first zero only
        int firstZero = n;

        for (int i = 0; i < n; i++) {

            pref[i + 1] = pref[i];

            int d = num[i] - '0';

            if (d == 0) {

                // Don't update again
                if (firstZero == n)
                    firstZero = i;

            } else {

                for (int j = 0; j < 4; j++) {
                    pref[i + 1][j] += f[d][j];
                }
            }
        }


        // --------------------------------
        // 4. Same length
        // --------------------------------

        // We cannot modify after the first zero
        // while keeping the prefix unchanged.
        int last = min(n - 1, firstZero);

        for (int i = last; i >= 0; i--) {

            vector<int> rem = need;

            // Remove factors provided by prefix
            for (int j = 0; j < 4; j++) {
                rem[j] =
                    max(0, rem[j] - pref[i][j]);
            }

            int original = num[i] - '0';

            // Make current digit strictly larger
            for (int d = original + 1; d <= 9; d++) {

                vector<int> nxt = rem;

                use(nxt, d);

                int slots = n - i - 1;

                if (!possible(nxt, slots))
                    continue;

                string ans = num.substr(0, i);

                ans.push_back(char('0' + d));

                // Fill suffix with smallest digits
                ans += build(nxt, slots);

                return ans;
            }
        }


        // --------------------------------
        // 5. Need longer number
        // --------------------------------

        int requiredLength = minDigits(need);

        int len = max(n + 1, requiredLength);

        return build(need, len);
    }
};