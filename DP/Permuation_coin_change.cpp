#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> coin(n);

    for (int i = 0; i < n; i++) cin >> coin[i];

    vector<long long> dp(target + 1, 0);

    dp[0] = 1;

    for (int sum = 1; sum <= target; sum++) {
        for (int i = 0; i < n; i++) {
            if (sum >= coin[i]) {
                dp[sum] += dp[sum - coin[i]];
            }
        }
    }

    cout << dp[target] << endl;

    return 0;
}