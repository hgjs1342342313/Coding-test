#include<iostream>
#include<algorithm>
using namespace std;
int map[1001][1001] = {0};
int r = 0, c = 0;
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1},{0, 1}};//direction is used to enumerate each position that could be went
int maxRoute[1001][1001] = {0};//maxRoute is used to store the longest path this point could go.

int ski(int X, int Y){
    if(maxRoute[X][Y]>0){
        return maxRoute[X][Y];
    }

    int path = 1;                   
    
        for(int t = 0; t < 4; t++){
            int curX = X+direction[t][0];
            int curY = Y+direction[t][1];
            if(curX>=0&&curX<r&&curY>=0&&curY<c&&map[curX][curY]<map[X][Y])
            path = max(path, ski(curX, curY)+1);

        }
    maxRoute[X][Y] = path;
    return path;
}


int main(){
    cin>>r>>c;
    int maxPath = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            int tmp = 0;
            cin>>tmp;
            map[i][j] = tmp;
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            maxRoute[i][j] = ski(i, j);
            maxPath = max(maxRoute[i][j], maxPath);
        }
    }
    cout<<maxPath;
    return 0;
}