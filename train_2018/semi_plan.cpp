#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
int* memory;
int search(int* connect,int start){
	int ret = 0;
	if(start == N-1){
		return ret;
	}
	for(int i = start+1; i < N; i++){
		int temp = 0;
		if(start == -1 || connect[start] < connect[i]){
			if(memory[i] == -1){
				temp++; // next connect found
				temp += search(connect,i); 
				memory[i] = temp;
			}else{
				temp = memory[i];
			}
			if(ret < temp){
				ret = temp;
			}
		}
	}
	return ret;

}

int main(){
	N = 0;
	cin >> N;
	int* connect = new int[N];
	memory = new int[N];
	for(int i = 0; i < N; i++){
		memory[i] = -1;
		cin >> connect[i];
	}
	int ret = 0;
	ret = search(connect,-1);
	cout << ret << endl;

	return 0;
}