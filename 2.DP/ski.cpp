#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int r = 0, c = 0;
vector<vector<int>> map(1001, vector<int>(1001, 0));
vector<vector<int>> path(1001, vector<int>(1001, 1));
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1},{0, 1}};


int ski(int posX, int posY){
    if(path[posX][posY] > 1){
        return path[posX][posY];
    }

    int maxpath = 1;
    for(int i = 0; i < 4; i++){
        int curX = posX+direction[i][0];
        int curY = posY+direction[i][1];

        if(curX >= 0 && curY >=0 && curX < r && curY < c && map[curX][curY] < map[posX][posY]){
            maxpath = max(maxpath, ski(curX, curY)+1);
        }
    }
    path[posX][posY] = maxpath;
    return maxpath;
}
int main(){

    cin>>r>>c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            int tmp = 0;
            cin>>tmp;
            map[i][j] = tmp;
        }
    }
    int maxnumber = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            
            maxnumber = max(maxnumber, ski(i, j));
        }
    }
    cout<<maxnumber;
    return 0;
}