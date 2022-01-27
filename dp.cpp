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

// DHYNAMMIC PROGRAMMING
// MIN STEPS TO 1
//Brute force
#include<bits/stdc++.h>
using namespace std;

int minSteps(int n){
    // Base Case
    if(n<=1){
        return 0;
    } 
    int x = minSteps(n-1);
    int y,z;
    if(n%2 == 0){
        y = minSteps(n/2);
    }
    if(n%3 == 0){
        z = minSteps(n/3);
    }

    // Calculate final output
    int ans = min(x, min(y,z)) + 1;
}

// MINSTEP TO 1 OPTIMAIZATION   T.C => O(n)

int minStepsHelper(int n, int *ans){
    // Base Case
    if(n<=1){
        return 0;
    }

    // Check if output already exists
    if(ans[n] != -1){
        return ans[n];
    }

    // Calculate output
    int x = minStepsHelper(n-1);

    int y = INT_MAX, z = INT_MAX;
    if(n%2 == 0){
        y = minStepsHelper(n/2, ans);
    }
    if(n%3 == 0){
        z = minStepsHelper(n/3, ans);
    }
    int output = min(x,min(y,z)) + 1;
    return output;
}

int minSteps_2(int n){
    int *ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i] = -1;
    }
    return minStepsHelper(n,ans);
}
    
int main(){
    int n;
    cin>>n;
    cout<<minSteps(n)<<endl;
    return 0;
}

// No of Balanced binary trees at height h
#include<bits/stdc++.h>
using namespace std;

// h >= 0   T.C = O(2^k)  for more value n its code valid
int balancedBTs_2(int h){
    if(h <= 1)
    return 1;

    int mod = (int)(pow(10, 9)) + 7;
    int x = balancedBTs_2(h - 1);
    int y = balancedBTs_2(h - 2);

    int temp1 = (int)(((long)(x)*x)%mod);
    int temp2 = (int)((2*(long)(x)*y)%mod);
    int ans = (temp1 + temp2)%mod;
    return ans;
}
//simple recursive sol
int balancedBTs(int h){
    if(h <= 1){
        return 1;
    }
    int x = balancedBTs(h-1);
    int y = balancedBTs(h-2);

    int ans = x*x + 2*x*y;
    return ans;
}

int main(){
    int h;
    cin>>h;
    cout<<balancedBTs(h)<<endl;
    cout<<balancedBTs_2(h)<<endl;
}










































