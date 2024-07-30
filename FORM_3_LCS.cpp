#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define inp(arr, n) for(int i = 0; i < n; i++) cin >> arr[i]
#define prr(v) for (const auto& elem : (v)) cout << elem << " "; cout << endl

// Function to compute the longest common subsequence
vector<vector<vector<int>>> dp;

int rec(int i, int j, int l, const string& a, const string& b, const string& c, int n, int m, int k) {
    if (i >= n || j >= m || l >= k) {
        return 0;
    }
    if (dp[i][j][l] != -1) {
        return dp[i][j][l];
    }
    int ans = 0;
    ans = max(ans, rec(i + 1, j, l, a, b, c, n, m, k));
    ans = max(ans, rec(i, j + 1, l, a, b, c, n, m, k));
    ans = max(ans, rec(i, j, l + 1, a, b, c, n, m, k));
    if (a[i] == b[j] && b[j] == c[l]) {
        ans = max(ans, 1 + rec(i + 1, j + 1, l + 1, a, b, c, n, m, k));
    }
    return dp[i][j][l] = ans;
}

// Function to handle input and output for each test case
void HELP_ME_() {
    int n, m, k;
    string a, b, c;
    cin >> n >> m >> k;
    cin >> a >> b >> c;

    // Initialize dp array with size n, m, k
    dp.assign(n, vector<vector<int>>(m, vector<int>(k, -1)));
    
    cout << rec(0, 0, 0, a, b, c, n, m, k) << endl;
}

// Function to compute prime numbers up to max_n using the Sieve of Eratosthenes
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

// Main function
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int __runtTime_terror;
    cin >> __runtTime_terror;
    while (__runtTime_terror--) {
        HELP_ME_();
    }

    return 0;
}
