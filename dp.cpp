// DHYNAMMIC PROGRAMMING
// FIBNOACCI RECURSION OR MEMOZIATION
#include<bits/stdc++.h>
using namespace std;

// Dhynamic Programming  (bottom-up)    T.C = O(n)
int fib_3(int n){
    int *ans = new int [n+1];

    ans[0] = 0;
    ans[1] = 1;
    for(int i=2;i<n;i++){
      ans[i] = ans[i-1] + ans[i-2];
    }
    return ans[n];
}

// Brute Force T.C = 0(2^k)
int fib(int n){
    if(n<=1)
    return n;
    int a = fib(n-1);
    int b = fib(n-2);
    return a+b;
}

// MEMOIZATION (Top down) T.C => O(n)

int fibo_helper(int n, int *ans){
    if(n<=1)
    return n;
    // check if output already exist
    if(ans[n] == -1){
        return ans[n];
    }
    int a = fibo_helper(n-1, ans);
    int b = fibo_helper(n-2, ans);

    ans[n] = a+b;
    return ans[n];
}

int fibo_2(int n){
    int *ans = new int[n+1];

    for(int i=0;i<n;i++){
        ans[i] = -1;
    }
    return fibo_helper(n,ans);
}

int main(){
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}


















