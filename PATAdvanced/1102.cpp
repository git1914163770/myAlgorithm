//           3
//      2                7
//   0    NULL      4          6
// 1 NULL       NULL  NULL   5   NULL

#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

int N;
int main(){
    scanf("%d",&N);
    getchar();
    char l,r;
    int arr[N];
    int left[N] , right[N];
    fill(arr,arr+N,0);
    fill(left,left+N,-1);
    fill(right,right+N,-1);
    for(int i = 0;i < N;i++){
        scanf("%c %c\n",&l,&r); 
        // getchar();
        if(l != '-'){
            left[i] = l - '0';
            arr[l - '0'] = 1;
        }
        if(r != '-') {
            right[i] = r - '0';
            arr[r - '0'] = 1;
        }
    }
    int root;
    for(int i = 0;i < N;i++){
        if(arr[i] == 0){
            root = i;
            // cout << root << endl;
            break;
        }
    }

    queue<int> q;
    q.push(root);
    int flag = 1;
    while(!q.empty()){
        if(!flag) printf(" ");
        else flag = 0;
        int node = q.front();
        printf("%d",node);
        q.pop();
        if(right[node] != -1) q.push(right[node]);
        if(left[node] != -1) q.push(left[node]);
    }
    printf("\n");
    stack<int> st;
    int cur = root;
    flag = 1;
    while(cur != -1 || !st.empty()){
        while (cur != -1) {
            st.push(cur);
            cur = right[cur];
        }
        cur = st.top();
        st.pop();
        if(!flag) printf(" ");
        else flag = 0;
        printf("%d",cur);
        cur = left[cur];
    }
    return 0;
}