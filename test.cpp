#include<iostream>
#include<vector>
using namespace std;
//边
typedef struct ArcNode{//邻接顶点
    int adjvex;//该点下标
    struct ArcNode *nextarc;//下一个点
    int info;//权
}ArcNode;
//顶点
typedef struct VNode{
    int data;
    ArcNode * firstarc;//指向第一个邻接点
}VNode, AdjList[10005];

typedef struct{//邻接表
    AdjList vertices;
    int vexnum, arcnum;
}ALGraph;

int locatevex(ALGraph G, int x){
    for(int i = 0; i < G.vexnum; i++){
        if(x==G.vertices[i].data){
            return i;
        }
    }
    return -1;
}

void insertedge(ALGraph &G, int i, int j, int w){
    ArcNode *s;
    s = new ArcNode;
    s->adjvex=j;
    s->nextarc = G.vertices[i].firstarc;
    s->info = w;
    G.vertices[i].firstarc = s;
}

void CreateAlGraph(ALGraph &G){
    int u, v;
    int weight;
    cin>>G.vexnum>>G.arcnum;
    for(int i = 0; i < G.vexnum; i++){
        G.vertices[i].data = i;
        G.vertices[i].firstarc=nullptr;
    }
    for(int _ = 0; _ < G.arcnum; _++){
        cin>>u>>v>>weight;
        insertedge(G, u, v, weight);
    }
}

int prim(ALGraph &G){
    int n = G.vexnum;
    vector<int> length(n);
    for(int i = 0; i < n; i++){
        length[i] = G.vertices[i].firstarc != nullptr? G.vertices[i].firstarc->info: 0x3f3f3f3f;
    }

    int minnumber = 0, u = 0, maxtank = 0;
    //只用了length数组，不用改
    for(int j = 1; j < n; j++){
        minnumber = 0x3f3f3f3f;
        for(int i = 1; i < n; i++){
            if(length[i]!=0 && minnumber>length[i]){
                minnumber = length[i];
                u = i;
            }
        }
        maxtank = max(maxtank, minnumber);
        length[u] = 0;
        G.vertices[u].firstarc = G.vertices[u].firstarc != nullptr ? G.vertices[u].firstarc->nextarc :nullptr;
    //更新length，用改
        for(int i = 1; i < n; i++){
            int tmp = 0;
            if(G.vertices[i].firstarc != nullptr){
                tmp = G.vertices[i].firstarc->info;
            }
            if(length[i] > tmp){
                length[i] = tmp;
            }
        }
    }
    return maxtank;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ALGraph G;
    CreateAlGraph(G);
    cout<<prim(G);
    return 0;
}