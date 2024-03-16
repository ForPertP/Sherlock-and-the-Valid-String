import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'isValid' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    private static String isValidByMap(String s) {
        if (s.length() == 1) return "YES";

        Map<Character, Integer> charCounts = new HashMap<>();
        for (char c : s.toCharArray()) {
            charCounts.put(c, charCounts.getOrDefault(c, 0) + 1);
        }

        int minCount = Integer.MAX_VALUE;
        int maxCount = Integer.MIN_VALUE;
        for (int count : charCounts.values()) {
            minCount = Math.min(minCount, count);
            maxCount = Math.max(maxCount, count);
        }

        if (minCount == maxCount) return "YES";

        int minCountFreq = 0;
        int maxCountFreq = 0;
        for (int count : charCounts.values()) {
            if (count == minCount) minCountFreq++;
            if (count == maxCount) maxCountFreq++;
        }

        if ((maxCount - minCount == 1 && maxCountFreq == 1) ||
                (minCount == 1 && minCountFreq == 1 && maxCountFreq == charCounts.size() - 1))
            return "YES";

        return "NO";
    }
    
    
    private static final int AlphabetLength = 'z' - 'a' + 1;

    private static String isValidByVector(String s) {
        if (s.length() == 1) return "YES";

        int[] charCounts = new int[AlphabetLength];
        for (char c : s.toCharArray()) {
            charCounts[c - 'a']++;
        }

        Arrays.sort(charCounts);

        int firstNonzero = 0;
        while (firstNonzero < AlphabetLength && charCounts[firstNonzero] == 0) {
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

    public static String isValid(String s) {
        if (s.length() > 100) {
            return isValidByMap(s);
        } else {
            return isValidByVector(s);
        }
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = bufferedReader.readLine();

        String result = Result.isValid(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
