#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define NONE -1
#define MATCH 1
#define NOT_MATCH 0
using namespace std;
string W;
string S;
int cache[101][101];
void initCache(){
	for(int i = 0 ; i < 101; i++){
		for(int j = 0 ; j < 101; j++){
			cache[i][j] = NONE;
		}
	}
}
int match(int w,int s){
	if(w == W.size()){
		if(s == S.size())return MATCH;
		else return NOT_MATCH;
	}
	//cout << "W["<< w <<"] = " << W[w] << ", S["<< s <<"] = " << S[s] << endl;
	if(W[w] != '?' && W[w] != '*'){

		if(W[w] == S[s]){
			if(cache[w+1][s+1] == NONE){
				cache[w+1][s+1] = match(w+1,s+1);	
			}
			return cache[w+1][s+1];
		}else{
			return NOT_MATCH;
		}
	}

	if(W[w] == '?'){
		if(cache[w+1][s+1] == NONE){
			cache[w+1][s+1] = match(w+1,s+1);
		}
		return cache[w+1][s+1];
	}

	if(W[w] == '*'){
		if(cache[w+1][s] == NONE){
			cache[w+1][s] = match(w+1,s);
		}

		if(S.size() > s && cache[w][s+1] == NONE){
			cache[w][s+1] = match(w,s+1);
		}

		if(cache[w+1][s] == MATCH || (S.size() > s && cache[w][s+1] == MATCH)){
			return MATCH;
		}else{
			return NOT_MATCH;
		}
	}

}
int main(){
	int T = 0;
	cin >> T;
	for(int t = 0 ; t < T ; t++){
		cin >> W;
		int N = 0;
		cin >> N;
		vector<string> result;
		//cout << "WildCard : " << W << endl;
		for(int i = 0 ; i < N; i++){
			cin >> S;
			initCache();
			//cout << "WildCard : " << W <<" / Case : " << S << endl;
			if(match(0,0) == MATCH){
				//cout << S << endl;
				result.push_back(S);
			}
			//cout << "Pattern" << i+1 << " is " << P << endl;
		}
		sort(result.begin(),result.end());
		for(int i  = 0 ; i < result.size() ; i++){
			cout << result[i] << endl;
		}
	}

	return 0;
}