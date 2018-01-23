#include <iostream>
#include <limits>
#include <vector>
#define FA 0
#define FB 1
using namespace std;
const long long NEGINF = numeric_limits<long long>::min();
int NA,NB;
vector<int> A;
vector<int> B;
int cache[101][101][2];
void initCache(){
	for(int i = 0; i < 100;i++){
		for(int j = 0 ; j < 100; j++){
			cache[i][j][0] = -1;
			cache[i][j][1] = -1;
		}
	}
}
int jlis(int a,int b,int flag){
	int MAX = 0;
	//if(flag==FA)cout << "A[" << a <<"]: " << A[a] << endl;
	//if(flag==FB)cout << "B[" << b <<"]: " << B[b] << endl;

	int i = 0;
	if(flag == FA)i = a+1;
	else i = a;

	for(i; i <= NA; i++){
		long long temp1;
		long long temp2;
		if(flag == FA){
			//if(a==0)cout << "A To A, start search from " << A[i] << endl;
			temp1 = (a == 0 ? NEGINF : A[a]);
			temp2 = (i == 0 ? NEGINF : A[i]);
			if(temp1 < temp2){
				if(cache[i][b][FA] == -1){
					cache[i][b][FA] = jlis(i,b,FA);
				}
				MAX = max(MAX,cache[i][b][FA]);		
			}
		}else if(flag == FB && i <= NB){
			//if(b==0)cout << "B To A, start search from " << B[i] << endl;
			temp1 = (b == 0 ? NEGINF : B[b]);
			temp2 = (i == 0 ? NEGINF : A[i]);	
			if(temp1 < temp2){
				if(cache[i][b][FA] == -1){
					cache[i][b][FA] = jlis(i,b+1,FA);
				}
				MAX = max(MAX,cache[i][b][FA]);		
			}
		}
		
	}

	i = 0;
	if(flag == FA)i = b;
	else i = b+1;

	for(i; i <= NB; i++){
		long long temp1;
		long long temp2;
		if(flag == FA && i <= NA){
			//if(a==0)cout << "A To B, start search from " << A[i] << endl;
			temp1 = (a == 0 ? NEGINF : A[a]);
			temp2 = (i == 0 ? NEGINF : B[i]);
			if(temp1 < temp2){
				if(cache[a][i][FB] == -1){
					cache[a][i][FB] = jlis(a+1,i,FB); 
				}
				MAX = max(MAX,cache[a][i][FB]);	
			}
		}else if(flag == FB){
			//if(b==0)cout << "B To B, start search from " << B[i] << endl;
			temp1 = (b == 0 ? NEGINF : B[b]);
			temp2 = (i == 0 ? NEGINF : B[i]);
			if(temp1 < temp2){
				if(cache[a][i][FB] == -1){
					cache[a][i][FB] = jlis(a,i,FB); 
				}
				MAX = max(MAX,cache[a][i][FB]);	
			}
		}
		
	}
	if(MAX == 0){
		//cout << ">> RET: 1" << endl;
		return 1;
	}
	else{
		//cout << ">> MAX: " << MAX << endl; 
		return MAX+1;
	}
}

int main(){
	int T = 0;
	cin >> T;
	for (int test_case = 0; test_case < T ; test_case++){
		cin >> NA >> NB;
		
		A.push_back(-1);
		B.push_back(-1);

		for(int i = 0 ; i < NA ; i++){
			int t = 0;
			cin >> t;
			A.push_back(t);
		}
		for(int i = 0 ; i < NB ; i++){
			int t = 0;
			cin >> t;
			B.push_back(t);
		}
		int ret = 0;
		initCache();
		ret = max(ret,jlis(0,0,FA));
		ret = max(ret,jlis(0,0,FB));

		NA = 0;
		NB = 0;
		A.clear();
		B.clear();
		if(ret == 0){
			cout << ret << endl;
		}else{
			cout << ret -1 << endl;	
		}
		
	}	
	return 0;
}