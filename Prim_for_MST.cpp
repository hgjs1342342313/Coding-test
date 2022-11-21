#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n = 0, m = 0;
vector<vector<int>> vertices(1005, vector<int>(1005, 0x3f3f3f3f));
vector<int> mst(1005, 1);
vector<int> length(100005, 0x3f3f3f3f);// store the length from one vertex to current spanning tree

int prim(){
    for(int i = 0; i < n; i++){
        length[i] = vertices[0][i];
    }

    int minnumber = 0, u = 0, sum = 0;
    for(int j = 1; j < n; j++){
        minnumber = 0x3f3f3f3f;
        for(int i = 1; i < n; i++){
            if(length[i]!=0 && minnumber>length[i]){
                minnumber = length[i];
                u = i;
            }
        }
        sum += minnumber;
        length[u] = 0;

        for(int i = 1; i < n; i++){
            if(length[i]> vertices[u][i]){
                length[i] = vertices[u][i];
                mst[i] = u;
            }
        }
        //cout<<endl;
        //for(int i = 0; i <= n; i++){
        //    cout<<mst[i]<<" ";
        //}
    }
    return sum;
}

int main(){
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        vertices[a][b] = c;
        vertices[b][a] = vertices[a][b];
    }
    for(int i = 0; i < n; i++){
        //for(int j = 0; j < n; j++){
         //   cout<<vertices[i][j]<<" ";
        //}
        //cout<<endl;
    }
    int answer = prim();
    cout<<answer<<endl;
    return 0;
}