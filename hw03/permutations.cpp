#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string longest_common_substring(const string &a, const string &b) {
    int len_a = a.size(), len_b = b.size();
    vector<vector<int>> dp(len_a + 1, vector<int>(len_b + 1, 0));
    int longest_len = 0;
    string longest_substring;

    for (int i = 1; i <= len_a; ++i) {
        for (int j = 1; j <= len_b; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > longest_len) {
                    longest_len = dp[i][j];
                    longest_substring = a.substr(i - longest_len, longest_len);
                } else if (dp[i][j] == longest_len) {
                    string candidate = a.substr(i - longest_len, longest_len);
                    if (candidate < longest_substring) {
                        longest_substring = candidate;
                    }
                }
            }
        }
    }

    return longest_substring;
}

int main() {
    string a, b;

    while (getline(cin, a) && getline(cin, b)) {
        cout << longest_common_substring(a, b) << endl;
    }

    return 0;
}
