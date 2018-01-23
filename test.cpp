#include <cstdio>
#include <iostream>
using namespace std;
int FUNC() {
    int cnt = 0;
    for (int i = 0; i <= 1024; ++i) {
        if ((i & (i - 1)) == 0) {
            ++cnt;
        }
    }
    return cnt;
}

int main(){

	//int ret = FUNC();
	int ret = 1 & 0;
    cout << "RET : " << ret << endl;
	return 0;
}

