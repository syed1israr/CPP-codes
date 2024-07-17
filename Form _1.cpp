#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

const int MAXN = 1001;
int n, k;
vector<int> time(MAXN), skill(MAXN);
vector<vector<vector<int>>> dp(MAXN, vector<vector<int>>(MAXN, vector<int>(MAXN, -1)));

int rec(int level, int time_taken, int item_taken, int x) {
    // Base case
    if (level == n) {
        return 0;
    }
    // Cache check
    if (dp[level][time_taken][item_taken] != -1) {
        return dp[level][time_taken][item_taken];
    }
    // Compute
    int ans = rec(level + 1, time_taken, item_taken, x);
    if (time_taken + time[level] <= x && item_taken + 1 <= k) {
        ans = max(ans, skill[level] + rec(level + 1, time_taken + time[level], item_taken + 1, x));
    }
    // Return and cache the result
    return dp[level][time_taken][item_taken] = ans;
}

void idhar_question_ki_Gnd_todunga() {
    cin >> n;
    time.resize(n);
    skill.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> time[i] >> skill[i];
    }
    int x;
    cin >> x >> k;
    // Printing answer
    cout << rec(0, 0, 0, x) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int __runtTime_terror;
    cin >> __runtTime_terror;
    while (__runtTime_terror--) {
        idhar_question_ki_Gnd_todunga();
    }

    return 0;
}
