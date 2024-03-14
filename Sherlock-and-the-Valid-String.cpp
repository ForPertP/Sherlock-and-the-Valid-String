#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid_ByMap(string s)
{
    if (s.size() == 1) return "YES";

    unordered_map<char, int> charCounts;
    for (const auto& c : s) {
        charCounts[c]++;
    }

    int minCount = INT_MAX;
    int maxCount = INT_MIN;
    for (const auto& entry : charCounts) {
        minCount = min(minCount, entry.second);
        maxCount = max(maxCount, entry.second);
    }

    if (minCount == maxCount) return "YES";

    int minCountFreq = 0;
    int maxCountFreq = 0;
    for (const auto& entry : charCounts) {
        if (entry.second == minCount) minCountFreq++;
        if (entry.second == maxCount) maxCountFreq++;
    }

    if ((maxCount - minCount == 1 && maxCountFreq == 1) ||
        (minCount == 1 && minCountFreq == 1 && maxCountFreq == charCounts.size() - 1))
        return "YES";

    return "NO";
}


const int AlphabetLength = 'z' - 'a' + 1;

string isValid_ByVector(string s)
{
    if (s.size() == 1) return "YES";

    vector<int> charCounts(AlphabetLength);
    for (char c : s)
    {
        charCounts[c - 'a']++;
    }

    sort(charCounts.begin(), charCounts.end());

    int firstNonzero = 0;
    while (firstNonzero < AlphabetLength && charCounts[firstNonzero] == 0)
    {
        firstNonzero++;
    }
    
    if (firstNonzero >= AlphabetLength) return "NO";

    int minCount = charCounts[firstNonzero];
    int maxCount = charCounts[AlphabetLength - 1];

    if (minCount == maxCount) return "YES";

    if ((maxCount - minCount == 1 && maxCount > charCounts[AlphabetLength - 2]) ||
        (minCount == 1 && charCounts[firstNonzero + 1] == maxCount))
        return "YES";

    return "NO";
}


string isValid(string s)
{
    if( s.size() > 100)
    {
        return isValid_ByMap(s);
    }
    else
    {
        return isValid_ByVector(s);
    }
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
