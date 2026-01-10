class Solution {
private:
    void buildSPF(vector<int> &spf, int N) {
        for (int i = 1; i <= N; i++)
            spf[i] = i;

        for (int i = 2; i * i <= N; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= N; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
    }

public:
    // 👇 REQUIRED by driver (do nothing)
    void sieve() {
        // Driver expects this, so keep it
    }

    vector<int> findPrimeFactors(int N) {
        vector<int> spf(N + 1);
        buildSPF(spf, N);

        vector<int> ans;
        while (N != 1) {
            ans.push_back(spf[N]);
            N /= spf[N];
        }
        return ans;
    }
};
