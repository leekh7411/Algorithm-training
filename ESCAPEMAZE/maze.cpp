/*
* https://www.acmicpc.net/problem/2178
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <utility>
#include <cstdio>
using namespace std;
#define INF 987654321
int N, M;
int cnt;
char maze[102][102]; // init NULL
bool visited[102][102]; // init all false 0
int mdistance[102][102]; // init all 0
bool updated[102][102];
queue<pair<int,int> >nextSearchQ;

int search(int x,int y){
	// x,y check 4 side
	//cout << "Search in " << x << " and " << y << endl;
	if(maze[x][y]== '0')return -1;
	// get current minimum distance
	int dist = INF;

	if( (visited[x-1][y])	       && // 1. if already visited.. then get minimum distance
		(mdistance[x-1][y] != INF) && // 2. out of index check
		(maze[x-1][y] == '1') 		  // 3. have to load '1' (not wall '0')
		){
		int minDistance = mdistance[x-1][y];
		dist = min(dist,minDistance);
		//cout << "> x-1 and y > " << dist << endl; 
	}

	if( (visited[x+1][y])	       && // 1. if already visited.. then get minimum distance
		(mdistance[x+1][y] != INF) && // 2. out of index check
		(maze[x+1][y] == '1') 		  // 3. have to load '1' (not wall '0')
		){
		int minDistance = mdistance[x+1][y];
		dist = min(dist,minDistance);
		//cout << "> x-1 and y > " << dist << endl; 
	}

	if( (visited[x][y-1])	       && // 1. if already visited.. then get minimum distance
		(mdistance[x][y-1] != INF) && // 2. out of index check
		(maze[x][y-1] == '1') 		  // 3. have to load '1' (not wall '0')
		){
		int minDistance = mdistance[x][y-1];
		dist = min(dist,minDistance);
		//cout << "> x and y-1 > " << dist << endl; 
	}

	if( (visited[x][y+1])	       && // 1. if already visited.. then get minimum distance
		(mdistance[x][y+1] != INF) && // 2. out of index check
		(maze[x][y+1] == '1') 		  // 3. have to load '1' (not wall '0')
		){
		int minDistance = mdistance[x][y+1];
		dist = min(dist,minDistance);
		//cout << "> x and y+1 > " << dist << endl; 
	}

	if(dist == INF)dist = 0;
	mdistance[x][y] = dist+1;
	visited[x][y] = true;
	

	/*for (int i = 1; i <= N; ++i){
		for (int j = 1; j <= M; ++j){
			if(mdistance[i][j]==INF)cout << "X ";
			else cout << mdistance[i][j] << " ";
		}cout << endl;
	}*/

	
	if(x==N && y==M) return 0;

	
	if( (!visited[x-1][y])	      && // 1. if NOT visited.. then search start
		(mdistance[x-1][y] == INF) && // 2. out of index check
		(maze[x-1][y] == '1') 		 // 3. have to load '1' (not wall '0')
		){
		//search(x-1,y);
		if(updated[x-1][y] == false){
			nextSearchQ.push(pair<int,int>(x-1,y));
			//cout << ">> Queue Update : (" << x-1 << " , " << y << ")" << endl;
			updated[x-1][y] = true;
		}
		
		
	}

	if( (!visited[x+1][y])	      && // 1. if NOT visited.. then search start
		(mdistance[x+1][y] == INF) && // 2. out of index check
		(maze[x+1][y] == '1') 		 // 3. have to load '1' (not wall '0')
		){
		//search(x+1,y);
		if(updated[x+1][y] == false){
			nextSearchQ.push(pair<int,int>(x+1,y));
			//cout << ">> Queue Update : (" << x+1 << " , " << y << ")" << endl;
			updated[x+1][y] = true;
		}
	}

	if( (!visited[x][y-1])	      && // 1. if NOT visited.. then search start
		(mdistance[x][y-1] == INF) && // 2. out of index check
		(maze[x][y-1] == '1') 		 // 3. have to load '1' (not wall '0')
		){
		//search(x,y-1);
		if(updated[x][y-1] == false){
			nextSearchQ.push(pair<int,int>(x,y-1));
			//cout << ">> Queue Update : (" << x << " , " << y-1 << ")" << endl;
			updated[x][y-1] = true;
		}
	}

	if( (!visited[x][y+1])	      && // 1. if NOT visited.. then search start
		(mdistance[x][y+1] == INF) && // 2. out of index check
		(maze[x][y+1] == '1') 		 // 3. have to load '1' (not wall '0')
		){
		//search(x,y+1);
		if(updated[x][y+1] == false){
			nextSearchQ.push(pair<int,int>(x,y+1));
			//cout << ">> Queue Update : (" << x << " , " << y+1 << ")" << endl;
			updated[x][y+1] = true;
		}
	}
}

int main() {
	cnt = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i){
		for (int j = 1; j <= M; ++j){
			cin >> maze[i][j];	
			mdistance[i][j] = INF;
		} 
	}
		
	search(1,1);
	pair<int,int> next;
	while(!nextSearchQ.empty()){
		next = nextSearchQ.front();
		search(next.first,next.second);
		nextSearchQ.pop();
	}
	
	cout << mdistance[N][M] << endl;
	return 0;
}
