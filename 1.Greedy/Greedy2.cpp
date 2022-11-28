#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<algorithm>
//#define int long long
using namespace std;

int replaced = 0;
int main(){
    vector<pair<int, int>> vec;
    int money = 0;
    map<int, int> findmap;
    cin>>money;
    for(int i = 0; i < 9; i++){
        int t = 0;
        cin>>t;
        vec.emplace_back(t, i+1);
        findmap.emplace(i+1, t);
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < 9; i++){
        int j = i + 1;
        while(true){
            if(j < 9 && vec[i].first == vec[j].first && vec[i].second < vec[j].second){
                auto tt = vec[i];
                vec[i] = vec[j];
                vec[j] = tt;
            }else{
                break;
            }
            j++;
        }
    }
    //取最多的数字
    vector<pair<int, int>> tmp;
    for(int i = 0; i < 8; i++){
        tmp.emplace_back(money/vec[i].first, money%vec[i].first);
    }

    int nums = tmp[0].first;
    int max[100005];
    for(int i = 0; i < nums; i++){
        max[i] = vec[0].second;
    }
    //cout<<max<<endl;
    int restmoney = money - nums*vec[0].first;

    for(int i = 0; i < 9; i++){
        int transmoney = findmap[9-i];
        int j = nums;
        while(j > 0){
        if(restmoney + vec[0].first - transmoney>= 0){
            max[replaced] = (9-i);  
            //cout<<max<<endl;
            restmoney = restmoney + vec[0].first - transmoney;
            replaced++;
        }else{
            break;
        }
        j--;
        }
        if(restmoney == 0 ){
            break;
        }
    }
    for(int i = 0; i < nums; i++){
        cout<<max[i];
    }
    return 0;
}