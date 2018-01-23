#include <iostream>
#include <vector>
using namespace std;
int T;
int N;
vector<int> A;
vector<int> cache;
int lis(int j){
	int MAX = 0;
	//cout << "A[" << j-1 << "] : " << A[j] << endl;
	for(int i = j+1 ; i < N+1; i++){
		if(A[j] < A[i]){
			if(cache[i] == -1){
				cache[i] = lis(i);
			}
			int ret = cache[i];
			MAX = max(ret,MAX);
		}
	}
	if(MAX == 0){
		return 1;
	}
	else{
		return MAX + 1;	
	} 
}
int main(){
	cin >> T;
	for(int test_case = 0; test_case < T; test_case++){
		cin >> N;
		A.push_back(-1);
		cache.push_back(-1);
		for(int i = 0 ; i < N; i++){
			int temp = 0;
			cin >> temp;
			A.push_back(temp);
			cache.push_back(-1);
		}
		
		int ret = lis(0);
		cout << ret-1 << endl;
		//cout << "Case #" << test_case+1 << ": " << ret << endl;
		A.clear();
		cache.clear();
	}
	
	return 0;
}