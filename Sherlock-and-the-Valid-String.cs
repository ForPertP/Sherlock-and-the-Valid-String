using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'isValid' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    private static string IsValid_ByMap(string s)
    {
        if (s.Length == 1) return "YES";

        Dictionary<char, int> charCounts = new Dictionary<char, int>();
        foreach (char c in s)
        {
            if (charCounts.ContainsKey(c))
                charCounts[c]++;
            else
                charCounts[c] = 1;
        }

        int minCount = int.MaxValue;
        int maxCount = int.MinValue;
        foreach (var entry in charCounts)
        {
            minCount = Math.Min(minCount, entry.Value);
            maxCount = Math.Max(maxCount, entry.Value);
        }

        if (minCount == maxCount) return "YES";

        int minCountFreq = 0;
        int maxCountFreq = 0;
        foreach (var entry in charCounts)
        {
            if (entry.Value == minCount) minCountFreq++;
            if (entry.Value == maxCount) maxCountFreq++;
        }

        if ((maxCount - minCount == 1 && maxCountFreq == 1) ||
            (minCount == 1 && minCountFreq == 1 && maxCountFreq == charCounts.Count - 1))
            return "YES";

        return "NO";
    }

    private static string IsValid_ByVector(string s)
    {
        if (s.Length == 1) return "YES";

        int[] charCounts = new int[26];
        foreach (char c in s)
        {
            charCounts[c - 'a']++;
        }

        Array.Sort(charCounts);

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

    public static string isValid(string s)
    {
        if (s.Length > 100)
        {
            return IsValid_ByMap(s);
        }
        else
        {
            return IsValid_ByVector(s);
        }
    }
}

class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        string s = Console.ReadLine();

        string result = Result.isValid(s);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
