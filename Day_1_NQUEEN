#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define inp(arr, n) for (int i = 0; i < n; i++) cin >> arr[i]
#define prr(v) for (const auto& elem : (v)) cout << elem << " "; cout << endl

int n, k;
vector<int> queens; 

bool check(int row, int col) {
    for (int i = 0; i < row; i++) {
        int prev_row = i;
        int prev_col = queens[i];
        if (prev_col == col || abs(col - prev_col) == abs(row - prev_row)) {
            return false;
        }
    }
    return true;
}

int rec(int level) {
    if (level == n) {
        return 1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (check(level, i)) {
            queens[level] = i;
            ans += rec(level + 1);
            queens[level] = -1; 
        }
    }
    return ans;
}

void idhar_question_ki_Gnd_todunga() {
    cin >> n;
    queens.resize(n, -1); 
    cout << rec(0) << endl; 
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int __runtTime_terror;
    // cin >> __runtTime_terror;
    // while (__runtTime_terror--) {
    //     idhar_question_ki_Gnd_todunga();
    // }
    
    idhar_question_ki_Gnd_todunga();

    return 0;
}
