#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int r = 0;
    int c = 0;
    cin>>r>>c;
    vector<vector<int>> vec(r, vector<int>(c, 0));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            int x = 0;
            cin>>x;
            vec[i][j] = x;
        }
    }
    vector<vector<int>> path(r, vector<int>(c, 1));
    int qq = sqrt(r*c)+1;
    for(int times = 0; times < qq; times++){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            int maxnum = 1;
            if(i-1>=0 && i-1 <= r-1){
                if(vec[i-1][j] < vec[i][j]){
                    maxnum = max(maxnum, path[i-1][j]+1);
                }
            }
            if(j-1>=0 && j-1 <= c-1){
                if(vec[i][j-1] < vec[i][j]){
                    maxnum = max(maxnum, path[i][j-1]+1);
                }
            }
            if(j+1>=0 && j+1 <= c-1){
                if(vec[i][j+1] < vec[i][j]){
                    maxnum = max(maxnum, path[i][j+1]+1);
                }
            }
            if(i+1 >= 0 && i+1 <= r-1){
                if(vec[i+1][j] < vec[i][j]){
                    maxnum = max(maxnum, path[i+1][j]+1);
                }
            }
            path[i][j] = maxnum;
        }
    }
    }


    int answer = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
           // cout<<path[i][j]<<" ";
            answer = max(answer, path[i][j]);
        }
        cout<<endl;
    }
    cout<<answer<<endl;
    return 0;
}