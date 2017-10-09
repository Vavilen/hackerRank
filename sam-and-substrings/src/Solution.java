import java.util.Scanner;

//https://www.hackerrank.com/challenges/sam-and-substrings

public class Solution {
    final static long divisor = 1000000007;


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.next();
        char[] charArray = str.toCharArray();
        long total = char2long(charArray[0]);
        long tmp = total;
        for (int i = 1; i < charArray.length; ++i) {
            tmp = tmp * 10 + (long) (i + 1) * char2long(charArray[i]);
            tmp %= divisor;
            total += tmp;
        }
        System.out.println(total % divisor);
    }

    private static long char2long(char c) {
        return (long) (c - '0');
    }
}

