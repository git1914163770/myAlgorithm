#include <cstdio>
using namespace std;
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int arr[40], index = 0;
	do{
        arr[index++] = a % b;
        a /= b;
    }while(a != 0);
	int flag = 0;
	for(int i = 0; i < index / 2; i++) {
		if(arr[i] != arr[index-i-1]) {
			printf("No\n");
			flag = 1;
			break;
		}
	}
	if(!flag) printf("Yes\n");
	for(int i = index - 1; i >= 0; i--) {
		printf("%d", arr[i]);
		if(i != 0) printf(" ");
	}
	return 0;
}