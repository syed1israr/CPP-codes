#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define inp(arr, n) for(int i = 1; i <= n; i++) cin >> arr[i]
#define prr(v) for (const auto& elem : (v)) cout << elem << " "; cout << endl



/* Q. there are  N items mainly x1,x2,x3... 
find if a subset of items exist that sums 
up to target T 

aise constraints indicator hote hai DP k 
constraints : - N <=100 xi<=10^4

{ 1,2,5,9} T = 3 , T = 4, T = 16

FORM ; -1
subset -> form1 
restriction 1 -> sum has to be <=t (just like time taken was <x)

// total sm = s
    dp(level,s) -> boolean answers chahiye 
    if subset  exist of sum T , in level-n-1 with S already taken 
    in 1 to level-1
    
    dp(level,S) -> take dp(level+1,s+xlevel)
                -> not take dp(level+1,s) 
    TimeComplexity :- dp(index, sum_taken)
    index -> 1 to n , and sum will be xi and it can upto 10^4
     so in total  (n*max(xi)*n) -> (n^2*max)
     
*/


// some used  variable 
int n, t;
vector<int> arr(101);
vector<vector<int>> dp(105, vector<int>(10001, -1));
 

int rec(int level, int sum_taken) {
    // Base case
    if (level == n + 1) {
        if (sum_taken == t) {
            return 1;
        } else {
            return 0;
        }
    }
    
    // Cache check
    if (dp[level][sum_taken] != -1) {
        return dp[level][sum_taken];
    }
    
    // Computation
    int ans = 0;
    ans = rec(level + 1, sum_taken); // Not taking current item
    
    if (sum_taken + arr[level] <= t) {
        ans = ans || rec(level + 1, sum_taken + arr[level]); // Taking current item
    }
    
    // Save and return
    return dp[level][sum_taken] = ans;
}
   
void idhar_question_ki_Gnd_todunga(){
   cin >> n;
    arr.resize(n + 1);
    inp(arr, n);
    cin >> t;
    cout << (rec(1, 0) ? "YES" : "NO") << endl;
}




signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // int __runtTime_terror;
    // cin >> __runtTime_terror;
    // while(__runtTime_terror--) {
    //     idhar_question_ki_Gnd_todunga();
    // }
    
     idhar_question_ki_Gnd_todunga();

    return 0;
}
