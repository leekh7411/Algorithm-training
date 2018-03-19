#include <iostream>
using namespace std;
int N;
int T;
int* arr;
long** memory;
int* asend;
long long search(int depth,int idx){
	if(depth == T){
		return 1;
	}
	long long ret = 0;
	for(int i = 0 ; i < 10; i++){ 
		if(idx <= i){
			asend[depth] = i;
			if(memory[depth+1][i] == -1){
				long long result = 0;
				result = search(depth+1,i);
				memory[depth+1][i] = result;
				ret += result;
			}else{
				ret += memory[depth+1][i];
			}	
		}
	}
	return ret;
}
int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		T = 0;
		cin >> T;
		arr = new int[T];
		asend = new int[T];
		memory = new long*[T+1];
		for(int j = 0 ; j < T; j++){
			arr[j] = 0;
		}
		for(int j = 0 ; j < T+1; j++){
			memory[j] = new long[10];
			for(int k = 0; k < 10; k++){
				memory[j][k] = -1;	
			}
		}
		cout << search(0,0) << endl;
	}

	return 0;
}