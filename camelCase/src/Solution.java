import java.util.Scanner;
//https://www.hackerrank.com/challenges/camelcase

public class Solution {
    static int camelcase(String s) {
        int count = 1;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == Character.toUpperCase(s.charAt(i))) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        int result = camelcase(s);
        System.out.println(result);
        in.close();
    }
}
