class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;

        int m = r - l + 1;

        vector<long long> needDown(m + 1, 0);
        vector<long long> needUp(m + 1, 0);

        // length = 2
        for (int v = 1; v <= m; v++) {
            needDown[v] = m - v; // last move up, next must go down
            needUp[v] = v - 1;   // last move down, next must go up
        }

        for (int len = 3; len <= n; len++) {

            vector<long long> newDown(m + 1, 0);
            vector<long long> newUp(m + 1, 0);

            long long pref = 0;

            // build needUp
            for (int v = 1; v <= m; v++) {
                newUp[v] = pref;
                pref = (pref + needDown[v]) % MOD;
            }

            long long suff = 0;

            // build needDown
            for (int v = m; v >= 1; v--) {
                newDown[v] = suff;
                suff = (suff + needUp[v]) % MOD;
            }

            needDown = move(newDown);
            needUp = move(newUp);
        }

        long long ans = 0;

        for (int v = 1; v <= m; v++) {
            ans = (ans + needDown[v] + needUp[v]) % MOD;
        }

        return (int)ans;
    }
};