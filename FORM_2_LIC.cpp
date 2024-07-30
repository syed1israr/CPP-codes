#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define inp(arr, n) for (int i = 0; i < n; i++) cin >> arr[i]
#define prr(v) for (const auto& elem : (v)) cout << elem << " "; cout << endl

// Function declarations
int rev(int level);
void FORM_TWO();
vector<int> sieve(int max_n);

// Global variables
int n;
vector<int> arr;
int dp[10100];

int rev(int level) {
    // Base case: if level is negative
    if (level < 0) return 0;
    
    // Check if result is already computed
    if (dp[level] != -1) return dp[level];
    
    // Compute the longest increasing subsequence ending at 'level'
    int ans = 1;
    for (int prev_taken = 0; prev_taken < level; prev_taken++) {
        if (arr[prev_taken] < arr[level]) {
            ans = max(ans, 1 + rev(prev_taken));  
        }
    }
    
    // Save and return the result
    return dp[level] = ans;
}

void FORM_TWO() {
    cin >> n;
    arr.resize(n);
    inp(arr, n);
    memset(dp, -1, sizeof(dp));
    
    int best = 0;
    for (int i = 0; i < n; i++) {
        best = max(best, rev(i));
    }
    
    cout << best << endl; 
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int __runtTime_terror;
    cin >> __runtTime_terror;
    while (__runtTime_terror--) {
        FORM_TWO();
    }

    return 0;
}

// Function to generate primes using sieve of Eratosthenes
vector<int> sieve(int max_n) {
    vector<bool> is_prime(max_n + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= max_n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= max_n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}
