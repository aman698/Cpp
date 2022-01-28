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

// knapsack
//brute force   T.C => O(2^k)
#include<bits/stdc++.h>
using namespace std;

// A utility function that returns
//maximum of two numbers
int max(int a, int b){
    return (a>b)?a:b;
}
int knapSack(int W, int wt[], int val[], int n){
    // Base case
    if( n == 0 || W == 0)
    return 0;
    
    // If weight of the nth item is more
    // than knapsack capacity W, then,
    //this item cannot be included
    // in the optimal solution
    if(wt[n-1]>W)
    return knapSack(W,wt,val,n-1);
    /* Return the maximum of two cases:
    1. nth item included
    2. not included
    */
    else
        return max(
            val[n-1]
                + knapSack(W - wt[n-1],wt,val,n-1), knapSack(W,wt,val,n-1));
}

int main(){
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    int W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapSack(W,wt,val,n);
    return 0;
}

// Memomiazation
#include<bits/stdc++.h>
using namespace std;

// Returns the value of maximum profit
int knapSackRec(int W, int wt[], int val[], int i, int** dp){
    // base condition
    if(i<0)
    return 0;
    if(dp[i][W] != -1)
    return dp[i][W];

    if(wt[i] > W){
        // Store the value of function call
        //stack in table before return
        dp[i][W] = knapSackRec(W,wt,val,i-1,dp);
        return dp[i][W];
    }
    else{
        // Store value in a table brfore return
        dp[i][W] = max(val[i] + knapSackRec(W - wt[i], wt, val, i-1,dp), knapScakRec(W,wt,val,i-1,dp));
        
        // Return value of table after storing
        return dp[i][W];
    }
}

int knapSack(int W, int wt[], int val[], int n){
    int** dp;
    dp = new int*[n];

    for(int i=0;i<n;i++)
    dp[i] = new int[W+1];

    for(int i=0;i<n;i++)
    dp[i] = new int[W+1];

    for(int i=0;i<n;i++)
    for(int j=0;j<W+1;j++)
    dp[i][j] = -1;
    return knapSackRec(W, wt, val, n-1, dp);
}

// Driver Code
int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}

// USE DP means bottom up
#include<bits/stdc++.h>
using namespace std;

// A utility function that returns
//maximum of two numbers
//T.C => O(N*W)
// A.S => O(N*W) 
int max(int a, int b){
    return (a>b)?a:b;
}

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
      vector<vector<int>> K(n + 1, vector<int>(W + 1));
 
    // Build table K[][] in bottom up manner
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                                K[i - 1][w - wt[i - 1]],
                                K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main(){
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    int W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapSack(W,wt,val,n);
    return 0;
}


// best dp approach T.C = O(N*W)
#include<bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n){
    int dp[W+1];
    memset(dp,0,sizeof(dp));

    for(int i=1;i<n+1;i++){
        for(int w = W; w >= 0; w--){

            if(wt[i-1] <= w)
            // finding the maximum value
            dp[w] = max(dp[w],dp[w - wt[i-1]] + val[i-1]);
        }
    }
    return dp[W];
}

int main(){
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}










































