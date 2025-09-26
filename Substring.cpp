#include <iostream>
#include <vector>
#include <string>
using namespace std;

// function to find longest common substring (lcs)
void findLCS(const string& str1, const string& str2) {
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> lcsTable(n + 1, vector<int>(m + 1, 0));
    int longestLength = 0;
    int endIndex = 0;

    // filling the table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                lcsTable[i][j] = lcsTable[i - 1][j - 1] + 1;
                if (lcsTable[i][j] > longestLength) {
                    longestLength = lcsTable[i][j];
                    endIndex = i;
                }
            }
        }
    }

    // print table
    cout << "\nLCS Table:\n   ";
    for (char c : str2) cout << c << " ";
    cout << "\n";
    for (int i = 0; i <= n; i++) {
        if (i > 0) cout << str1[i - 1] << " ";
        else cout << "  ";
        for (int j = 0; j <= m; j++) {
            cout << lcsTable[i][j] << " ";
        }
        cout << "\n";
    }

    // result
    if (longestLength > 0) {
        string lcs = str1.substr(endIndex - longestLength, longestLength);
        cout << "\nLongest Substring is: " << lcs << "\n";
        cout << "Length is: " << longestLength << "\n";
    } else {
        cout << "\nNo common substring founded.\n"; // mistake
    }
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    findLCS(s1, s2);
    return 0;
}
