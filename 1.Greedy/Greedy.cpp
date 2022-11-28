#要求投票，找最小拉票人数。给定一个数组x，x为各个部门的人数。 只要部门i的人数超过一半被拉票，这个部门就算1票。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int totalanswer = 0;
int main(){
    vector<int> vec;
    int n = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        int m = 0;
        cin>>m;
        vec.push_back(m);
    }
    sort(vec.begin(), vec.end());
    int times = vec.size()/2+vec.size()%2;

    for(int i = 0; i < times; i++){
        totalanswer += vec[i]/2+vec[i]%2;
    }
    cout<<totalanswer<<endl;
    return 0;
}
