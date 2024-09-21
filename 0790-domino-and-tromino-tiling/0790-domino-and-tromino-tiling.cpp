class Solution {
public:
    int numTilings(int n) {
        if (n <= 2) return n;

        const long MOD = 10e8 + 7;

        vector<long> full(n+1, 0);
        vector<long> partial(n+1, 0);

        // full(i) =  full(i-1) + full(i-2) + partial(i-1) * 2
        // partial(i) = full(i-2) + partial(i-1)

        full[1] = 1;
        full[2] = 2;
        partial[2] = 1;

        for (int i=3; i<=n; ++i) {
            full[i] = (full[i-1] + full[i-2] + 2 * partial[i-1]) % MOD;
            partial[i] = (full[i-2] + partial[i-1]) % MOD;
        }

        return static_cast<int>(full.back());
    }
};