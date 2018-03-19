// you can use includes, for example:
// #include <algorithm>
#include <vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
vector< vector<int> > MAP;
bool** visit;
int count;
int N,M;
void find(int x,int y,int num,int dir){
    //cout << x << ", " << y << endl;
    if(x < 0 || x >= N || y < 0 || y >= M)return;
    if(visit[x][y])return;
    if(num == MAP[x][y]){
        visit[x][y]=true;
    }else{
        return;   
    }
    if(dir!=0)find(x+1,y,num,1);
    if(dir!=1)find(x-1,y,num,0);
    if(dir!=2)find(x,y+1,num,3);
    if(dir!=3)find(x,y-1,num,2);
}
int solution(vector< vector<int> > &A) {
    // init
    MAP = A;
    N = MAP.size();
    M = MAP[0].size();
    count = 0;
    visit = new bool* [N];
    for(int i = 0 ; i < N; i++){
        visit[i] = new bool[M];
        for(int j = 0 ; j < M; j++){
            visit[i][j] = false;   
        }
    }
    
    // find
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M; j++){
            if(visit[i][j] == false){
                count++;
                find(i,j,MAP[i][j],-1);
            }
        }
    }
    
    return count;
}