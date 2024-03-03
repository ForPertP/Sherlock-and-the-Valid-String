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
    return s;
}


string isValid_ByVector(string s)
{
    if (s.size() == 1) return "YES";

    vector<int> charCounts(26);
    for (char c : s)
    {
        charCounts[c - 'a']++;
    }

    sort(charCounts.begin(), charCounts.end());

    int firstNonzero = 0;
    while (firstNonzero < 26 && charCounts[firstNonzero] == 0)
    {
        firstNonzero++;
    }
    
    if (firstNonzero >= 25) return "NO";

    int minCount = charCounts[firstNonzero];
    int maxCount = charCounts[25];

    if (minCount == maxCount) return "YES";

    if ((maxCount - minCount == 1 && maxCount > charCounts[24]) ||
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
