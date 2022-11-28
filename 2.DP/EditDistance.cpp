#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n1 = 0;
    int n2 = 0;
    cin >> n1 >> n2;
    vector<int> a1;
    vector<int> a2;
    for (int i = 0; i < n1; i++) {
        int tmp = 0;
        cin >> tmp;
        a1.push_back(tmp);
    }
    for (int i = 0; i < n2; i++) {
        int tmp = 0;
        cin >> tmp;
        a2.push_back(tmp);
    }
    vector<vector<int>> dp(1005, vector<int>(1005, 0));
    dp[0][0] = 0;
    for (int i = 1; i <= n1; i++) {
        dp[i][0] = a1[i - 1] + dp[i - 1][0];
    }
    for (int j = 1; j <= n2; j++) {
        dp[0][j] = a2[j - 1] + dp[0][j - 1];
    }
    for (int i = 1; i < n1 + 1; i++) {
        for (int j = 1; j < n2 + 1; j++) {
            if (a1[i-1] == a2[j-1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                int nondel = min(dp[i - 1][j] + a1[i-1], dp[i][j - 1] + a2[j-1]);
                dp[i][j] = min(nondel, dp[i - 1][j - 1] + abs(a1[i-1] - a2[j-1]));
            }
        }
    }
    cout << dp[n1][n2];
    return 0;
}