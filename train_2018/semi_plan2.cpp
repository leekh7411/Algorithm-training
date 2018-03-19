#include <iostream>
#include <vector>
using namespace std;
vector<int> list;
vector<int> mem;
int N;

void print_list(){
	for(int i = 0 ; i < list.size() ; i++){
		cout << list[i] << " ";
	}cout << endl;
}

void print_mem(){
	for(int i = 0 ; i < mem.size() ; i++){
		cout << mem[i] << " ";
	}cout << endl;
}

int search_bin(int start,int end,int val){
	if(end == start)return end;
	if(end-start == 1){
		if(mem[start] >= val)return start;
		else return end;
	}
	int mid = (start + end)/2;
	if(mem[mid] < val){
		return search_bin(mid,end,val);
	}else if(mem[mid] == val){
		return mid;
	}else{ // mem[mid] > val
		return search_bin(start,mid,val);
	}
}
int main(){
	cin >> N;
	for(int i = 0 ; i < N; i++){
		int temp;
		cin >> temp;
		list.push_back(temp);
		//print_list();
		if(mem.size() == 0){
			mem.push_back(list[i]);
			//cout << "push_back " << list[i] << endl;
			//print_mem();
		}else if(mem[mem.size()-1] < list[i]){
			//cout << "mem push_back " << list[i] << endl;
			mem.push_back(list[i]);
			//print_mem();
		}else{
			//cout << "search_bin 0 ~ " << mem.size()-1 << " where " << list[i];
			int idx = search_bin(0,mem.size()-1,list[i]);
			//cout << " set to index " << idx << endl;
			mem[idx] = list[i];
			//print_mem();
		}
	}
	cout << mem.size() << endl;

	return 0;
}