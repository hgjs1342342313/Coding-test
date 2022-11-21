#include<iostream>
#include<vector>

using namespace std;


vector<vector<int>> vertices(1005, vector<int>(1005, 0x3f3f3f3f));
vector<int> curlen(1005, 0x3f3f3f3f);//结点i距离初始节点的距离
vector<int> isShortest(1005, false);//结点i距离起点最小距离是否确定
int n = 0, m = 0;

int dijkstra(int s, int t){
    curlen[s] = 0;

    for(int i = 0; i < n; i++){
        int t = -1;//当前访问的点
        for(int j = 0; j < n; j++){
            if(!isShortest[j] && (t ==-1 || curlen[j]< curlen[t])){
                t = j;
            }
        }
        isShortest[t] = true;

        for(int j = 0; j < n; j++){
            curlen[j] = min(curlen[j], curlen[t]+vertices[t][j]);
        }
    }
    for(int i = 0; i < n; i++){
        cout<<"curlen is "<< curlen[i]<<endl;
    }
    return curlen[t];
}

int main(){
    cin>>n>>m;
    int s = 0; int t = 0;
    cin>>s>>t;
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        vertices[a][b] = c;
        vertices[b][a] = c;
    }
    cout<<dijkstra(s, t);
    return 0;
}
