#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> coin(n), qty(n);

    for (int i = 0; i < n; i++) cin >> coin[i];

    for (int i = 0; i < n; i++) cin >> qty[i];

    vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int sum = 0; sum <= target; sum++) {
            for (int k = 0; k <= qty[i - 1]; k++) {
                int used = k * coin[i - 1];

                if (sum - used >= 0) {
                    dp[i][sum] += dp[i - 1][sum - used];
                }
            }
        }
    }

    cout << dp[n][target] << endl;

    return 0;
}