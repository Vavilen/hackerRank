import java.util.Scanner;

//https://www.hackerrank.com/challenges/caesar-cipher-1

public class Solution {
    static int alphabetSize = 26;

    static String caesarCipher(StringBuilder s, int k) {
        char startChar;
        for (int i = 0; i < s.length(); i++) {
            if (Character.isAlphabetic(s.charAt(i))) {
                startChar = Character.isUpperCase(s.charAt(i)) ? 'A' : 'a';
                s.setCharAt(i, (char) (startChar + (s.charAt(i) - startChar + k) % alphabetSize));
            }
        }
        return s.toString();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String s = in.next();
        int k = in.nextInt();
        String result = caesarCipher(new StringBuilder(s), k);
        System.out.println(result);
        in.close();
    }
}

