#include <iostream>
#define MAX 987654321
using namespace std;
int N;
int** map;
int main(){
	cin >> N;
	map = new int*[N];
	for(int i = 0 ; i < N; i++){
		map[i] = new int[N];
		for(int j = 0 ; j < N; j++){
			cin >> map[i][j];
		}
	}

	bool not_other_path = true;
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < N; j++){
			for(int k = 0 ; k < N; k++){
				if(i == j || j == k || k == i)continue;
				if(map[j][k] == map[j][i] + map[i][k]){
					not_other_path = false;
					//cout << j << " -> " << k << " ["  << map[j][k] << "]" <<endl;
					//cout << j << " -> " << i << " -> " << k << " [" << map[j][i] << " + " << map[i][k] << "]"<< endl;
					map[j][k] = MAX;
				}
			}
		}
	}
	int sum = 0;
	for(int i = 0 ; i < N; i++){
		for(int j = i+1 ; j < N; j++){
			if(map[i][j] == MAX){
				//cout <<  -1 << " ";
			}
			else{
				sum += map[i][j];
				//cout << map[i][j] << " ";
			}
		}//cout << endl;
	}
	/*if(not_other_path)cout << -1 << endl;
	else */
	cout << sum << endl;
	//else cout << sum/2 << endl;
	//cout << cnt << endl;
	//cout << sum - cnt << endl;
	//cout << cnt << endl;

	return 0;
}