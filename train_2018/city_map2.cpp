#include <iostream>
#define MAX 987654321
using namespace std;
int N;
int** map;
int* visit;
int main(){
	cin >> N;
	map = new int*[N];
	visit = new int[N];
	for(int i = 0 ; i < N; i++){
		map[i] = new int[N];
		visit[i] = false;
		for(int j = 0 ; j < N; j++){
			cin >> map[i][j];
		}
	}

	return 0;
}