#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;
int times = 0;
int main(){
    int n = 0;
    int i3 = 0, i2 = 0, i1 = 0;
    cin>>n;
    vector<int> vec, svec;
    for(int i = 0; i < n; i++){
        int m = 0;
        cin>>m;
        svec.push_back(m);
        vec.push_back(m);
    }
    sort(vec.begin(), vec.end());
    int pos=0, neg=0;
    for(int i = 0; i < vec.size(); i++){
        if(vec[i]-svec[i]>0){
            pos+=1;
        }else if(vec[i]-svec[i]<0){
            neg+=1;
        }
    }
    cout<<max(pos,neg)<<endl;
    return 0;
}