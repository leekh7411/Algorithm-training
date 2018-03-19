#include <iostream>
#include <cmath>
using namespace std;
int N;
int M;
int main(){
	cin >> N;
	for(int n = 0 ; n < N; n++){
		cin >> M;
		double ret = 0;
		for(int i = 1 ; i <= M ; i++){
			ret += log10(i);
		}
		int ret_n = ceil(ret);

		if (M == 1)cout << 1 << endl;
		else cout << ret_n << endl;
	}
	return 0;
}