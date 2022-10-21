#include<iostream>
#include<cmath>
//Leetcode 416 plus（416是正序求两个dp）
//倒序求dp
//不知道为什么不能过case1
using namespace std;
int main(){
    int weight = 0;
    int n = 0;
    cin>>weight>>n;
    int * dp = new int[weight+1];
    int * weights = new int[n];
    int * values = new int[n];
    for(int i = 0; i < n; i++){
        int w = 0, v = 0;
        cin>>w>>v;
        weights[i] = w;
        values[i] = v;
    }
    for(int i = 1; i <= n; i++){
        int w = weights[i-1], v = values[i-1];
        for(int j = weight; j >=1; j--){
            if(j>=w){
                dp[j] = max(dp[j], dp[j-w]+v);
                //dp[j] 表示dp[i][j]和dp[i-1][j]
            }
        }
    }
    cout<<dp[weight]<<endl;

    delete[] dp;
    delete[] weights;
    delete[] values;
    return 0;
}