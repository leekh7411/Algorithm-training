#include <iostream>
#include <vector>
#include <string>
using namespace std;
int C;
int fn,mn;
void add(vector<int>&A,vector<int>&B,int k){
	cout << "ADD > A: " << A.size() << " , B: " << B.size() << ", K: " << k << endl;	
	int N = 0;
	if(A.size()==0||B.size()==0)return;
	if(A.size() < B.size())N = A.size();
	else N = B.size();
	int i;
	for(i = 0 ; i < N; i++){
		A[i] = (A[i] | B[i]);
	}
	for(i = 0 ; i < )


}
void sub(vector<int>&A,vector<int>&B){
	cout << "SUB > A: " << A.size() << " , B: " << B.size() << ", K: " << k << endl;	
	int N = 0;
	if(A.size()==0||B.size()==0)return;
	if(A.size() < B.size())N = A.size();
	else N = B.size();	
}
void printVec(vector<int>& vec,string tag){
	cout << tag << ": ";
	for(int i = 0 ; i < vec.size(); i++){
		cout << vec[i];
	}cout << endl;
}
vector<int> multiple(vector<int>&A,vector<int>&B){
	int An = A.size();
	int Bn = B.size();
	cout << "LEN A: " << An << " ,B: " << Bn << endl;
	if(An < Bn)return multiple(B,A);
	if(An == 0 || Bn == 0){
		cout << "return empty vector" << endl;
		return vector<int>();
	}
	if(An == 1 || Bn == 1){
		cout << "return one vector" << endl;
		vector<int>ret;
		ret.push_back(A[0]|B[0]);
		return ret;
	}
	int half = An/2;
	// A is longger than B
	cout << "half : " << half << endl;  
	// divide A half
	vector<int> a0(A.begin(),A.begin()+half);
	vector<int> a1(A.begin()+half,A.end());
	printVec(a0,"a0");
	printVec(a1,"a1");
	// devide B 
	vector<int> b0(B.begin(),B.begin()+min<int>(half,B.size()));
	vector<int> b1(B.begin()+min<int>(half,B.size()),B.end());
	printVec(b0,"b0");
	printVec(b1,"b1");

	// multiple
	vector<int> z0 = multiple(a1,b1);
	vector<int> z2 = multiple(a0,b0);
	add(a0,a1,0);
	add(b0,b1,0);
	vector<int> z1 = multiple(a0,b0);
	sub(z1,z0);
	sub(z1,z2);
	vector<int>ret;
	add(ret,z0,0);
	add(ret,z1,half);
	add(ret,z2,half+half);
	return ret;
}
void initVec(vector<int>& Fan,vector<int>& Mem,string& mem,string& fan){
	fn = fan.size();
	mn = mem.size();
	for(int i = 0; i < fn; i++){
		Fan.push_back(int(fan[i]=='M'));
	}
	for(int i = 0; i < mn; i++){
		Mem.push_back(int(mem[i]=='M'));
	}
}
int main(){
	cin >> C;
	for(int c = 0; c < C; c++){
		string member,fan;
		vector<int> Fan;
		vector<int> Mem;
		cin >> member >> fan;
		initVec(Fan,Mem,member,fan);
		vector<int> ret = multiple(Fan,Mem);
		int hug = 0;
		for(int i = 0 ; i < ret.size(); i++){
			if(ret[i] == 0){
				hug++;
			}
			cout << ret[i];
		}cout << endl;
		cout << "HUG : " << hug << endl;
	}
	return 0;
}