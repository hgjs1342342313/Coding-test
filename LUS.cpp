#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n = 0;
    cin>>n;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int tmp = 0;
        cin>>tmp;
        nums.push_back(tmp);
    }
    vector<int> dp(1001, 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[i]>nums[j]){
                dp[i] = max(dp[j]+1, dp[i]);
            }
           // cout<<"dp"<<j<<" is "<<dp[j]<<endl;
        }
    }

    //cout<<endl;
    vector<int> dp2(1001, 1);
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j > i; j--){
            if(nums[j]<nums[i]){
                dp2[i] = max(dp2[j]+1, dp2[i]);
            }
        }
    }
    int mnum2 = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        //cout<<dp[i]<<" "<<dp2[i]<<endl;
        ans = max(ans, dp[i]+dp2[i]);
    }
    cout<<ans-1;
    return 0;
}