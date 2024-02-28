#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {

}

string isValid(string s)
{
    if (s.size() == 1)
        return "YES";

    vector<int> count_arr(26);
    for (size_t i = 0; i < s.size(); ++i)
    {
        count_arr[s[i] - 'a']++;
    }

    std::sort(count_arr.begin(), count_arr.end());

    bool b_check = true;
    int check = 0;
    int check2 = 0;
    int check_count = 0;
    int check2_count = 0;

    for (size_t i = 0; i < count_arr.size(); ++i)
    {
        if (count_arr[i] == 0)
            continue;
        
        if (check == 0)
        {
            check = count_arr[i];
            check_count++;
        }
        else
        {
            if (check != count_arr[i])
            {
                if (check2 == 0)
                {
                    check2 = count_arr[i];
                    check2_count++;
                }
                else
                {
                    if (check2 != count_arr[i])
                    {
                        b_check = false;
                        break;
                    }
                    else
                    {
                        check2_count++;
                    }
                }
            }
            else
            {
                check_count++;
            }
        }
    }

    if (false == b_check)
        return "NO";

    if( check_count > 1 && check2_count > 1)
        return "NO";

    if (check2_count == 1)
    {
        if (check2 - check > 1)
        {
            return "NO";
        }
    }

    return "YES";
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
