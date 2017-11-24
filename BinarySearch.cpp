#include <iostream>

using namespace std;
int searchBinary(int* arr,int start,int end,int target){
	if(start == end){
		if(arr[start]==target)return start;
		else return -1;
	}
	int target_index = int((start+end)/2);
	if(arr[target_index] == target)return target_index;
	else if(arr[target_index] < target){
		return searchBinary(arr,target_index+1,end,target);
	}else{
		return searchBinary(arr,start,target_index-1,target);
	}
}
int main(){
	int arr[6] = {3,14,54,112,654,4432};
	int target = 6154;
	int target_idx = searchBinary(arr,0,5,target);
	cout << "TARGET INDEX: " << target_idx << endl;
	return 0;
}