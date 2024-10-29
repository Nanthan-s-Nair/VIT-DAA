#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

void find_all_lcs(const string &s1, const string &s2, int m, int n, 
                  const vector<vector<int>> &dp, string lcs, set<string> &lcs_set) {
    if (m == 0 || n == 0) {
        reverse(lcs.begin(), lcs.end());
        lcs_set.insert(lcs);
        return;
    }

    if (s1[m - 1] == s2[n - 1]) {
        lcs.push_back(s1[m - 1]);
        find_all_lcs(s1, s2, m - 1, n - 1, dp, lcs, lcs_set);
    } else {
        if (dp[m - 1][n] >= dp[m][n - 1])
            find_all_lcs(s1, s2, m - 1, n, dp, lcs, lcs_set);
        if (dp[m][n - 1] >= dp[m - 1][n])
            find_all_lcs(s1, s2, m, n - 1, dp, lcs, lcs_set);
    }
}

int lcs_length(const string &s1, const string &s2, vector<vector<int>> &dp) {
    int m = s1.size();
    int n = s2.size();

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int lcs_len = lcs_length(s1, s2, dp);
    cout << lcs_len << endl;

    set<string> lcs_set;
    find_all_lcs(s1, s2, m, n, dp, "", lcs_set);

    for (const auto &lcs : lcs_set) {
        cout << lcs << endl;
    }

    return 0;
}