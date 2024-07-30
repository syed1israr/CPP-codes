#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
#define endl "\n"
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define inp(arr, n) for (int i = 0; i < n; ++i) cin >> arr[i];
#define prr(v) for (const auto& elem : (v)) cout << elem << " "; cout << endl;

// Function to compute maximum sum path in a grid
int rec(int r, int c, const vector<vector<int>>& arr, vector<vector<int>>& dp, vector<vector<bool>>& done) {
    // Pruning
    if (r < 0 || c < 0) {
        return LLONG_MIN;  // Using LLONG_MIN for clarity
    }

    // Base case
    if (r == 0 && c == 0) {
        return arr[0][0];
    }

    // Save and check
    if (done[r][c]) {
        return dp[r][c];
    }

    // Compute answer
    int ans = LLONG_MIN;
    if (r > 0) {
        ans = max(ans, rec(r - 1, c, arr, dp, done) + arr[r][c]);
    }
    if (c > 0) {
        ans = max(ans, rec(r, c - 1, arr, dp, done) + arr[r][c]);
    }

    // Save and return
    done[r][c] = true;
    return dp[r][c] = ans;
}

void HELP_ME_() {
    int n, m;
    cin >> n >> m;

    // Initialize grid and auxiliary matrices
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, LLONG_MIN));
    vector<vector<bool>> done(n, vector<bool>(m, false));

    // Read grid values
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    // Compute and output result
    cout << rec(n - 1, m - 1, arr, dp, done) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int num_tests;
    cin >> num_tests;
    while (num_tests--) {
        HELP_ME_();
    }

    return 0;
}

// Sieve of Eratosthenes to find all primes up to max_n
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
