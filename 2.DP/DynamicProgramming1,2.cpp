#include<iostream>
#include<cmath>
#include<vector>
//Leetcode 416 plus（416是正序求两个dp）
//倒序求dp
//使用vector重构
using namespace std;
int main() {
    int weight = 0;
    int n = 0;
    int times = 0;
    cin >> weight >> n >>times;
    vector<int> dp(weight+1, 0);
    vector<int> weights(times*n, 0);
    vector<int> values(times*n, 0);
    for (int i = 0; i < times*n;) {
        
        int w = 0, v = 0;
        cin >> w >> v;
        for(int j = 0; j < times; j++){
        weights[i] = w;
        values[i++] = v;
        }
    }
    for (int i = 0; i < times*n; i++) {
        int w = weights[i], v = values[i];
        for (int j = weight; j >= w; j--) {
            if (j >= w) {
                dp[j] = max(dp[j], dp[j - w] + v);
                //dp[j] 表示dp[i][j]和dp[i-1][j].
                //从weight到w表示可以取到的w的最大
            }
        }
    }
    cout << dp[weight] << endl;
 
    return 0;
}