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

// Min Cost Path
// Brute force
#include<bits/stdc++.h>
using namespace std;

int minCostPath(int **input, int m, int n, int i, int j){
    // Base Case
    if(i == m-1 && j == n-1){
        return input[i][j];
    }
    if(i >= m || j >= n){
        return INT_MAX;
    }
    // Recursive calls
    int x = minCostPath(input,m,n,i,j+1);
    int y = minCostPath(input,m,n,i+1,j+1);
    int z = minCostPath(input,m,n,i+1,j);

    // Small Calculation
    int ans = min(x, min(y, z)) + input[i][j];
}

int minCostPath(int **input, int m, int n){
    return minCostPath(input,m,n,0,0);
}

int main(){
    int m,n;
    cin>>m>>n;
    int **input = new int*[m];
    for(int i=0;i<m;i++){
        input[i] = new int[n];
        for(int j=0;j<n;j++){
            cin>>input[i][j];
        }
    }
    cout<<minCostPath(input,m,n)<<endl;
}
// ishi ka ha
// MINCLOSE PATH
#include<bits/stdc++.h>
using namespace std;

// Dhynamic programmming
int minCostPath_DP(int **input, int m, int n){
    int **output = new int*[m];
    for(int i=0;i<m;i++){
        output[i] = new int[n];
    }

    // Fill the last cell i.e. destination
    output[m-1][n-1] = input[m-1][n-1];

    // Fill the last row (right to left)
    for(int j = n-2; j >= 0; j--){
        output[m-1][j] = output[m-1][j+1] + input[m-1][j];
    }
    // Fill the last column (bottom to top)
    for(int i = m-2; i >= 0; i--){
        output[i][n-1] = output[i+1][n-1] + input[i][n-1];
    }
    // Fill remaining cells
    for(int i = m-2; i >= 0; i--){
        for(int j = n-2;j >= 0; j--){
            output[i][j] = min(output[i][j+1],min(output[i+1][j+1], output[i+1][j])) input[i][j];
        }
    }
    return output[0][0];
}
// MEMOIZATION
int minCostPath_Mem(int **input, int m, int n, int i, int j, int **output){
    if(i == m-1 && j == n-1){
    return input[i][j];
    }
    if(i >= m || j >= n){
        return INT_MAX;
    }

    // Check if ans already exists
    if(output[i][j] != -1){
        return output[i][j];
    }

    // Recursive calls
    int x = minCostPath_Mem(input,m,n,i,j+1,output);
    int y = minCostPath_Mem(input,m,n,i+1,j+1,output);
    int z = minCostPath_Mem(input,m,n,i+1,j,output);

    // Small Calculation
    int a = min(min, min(y,z)) + input[i][j];

    //save ker leta h
    output[i][j] = a;
    return a;
}

int minCostPath(int **input, int m, int n){
    int **output = new int*[m];
    for(int i=0;i<m;i++){
        output[i] = new int[n];
        for(int j=0;j<n;j++){
            output[i][j] = -1;
        }
    }

    return minCostPath(input,m,n,i,j,output);
}

int main(){
    int m,n;
    cin>>m>>n;
    int **input = new int*[m];
    for(int i=0;i<m;i++){
        input[i] = new int[n];
    
    for(int j=0;j<n;j++){
        cin>>input[i][j];
    }
    }
    cout<<minCostPath_Mem(input,m,n,0,0)<<endl;
    cout<<minCostPath_Mem(input,m,n)<<endl;
    cout<<minCostPath(input,m,n);
}










































