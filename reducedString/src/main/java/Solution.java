import java.util.Scanner;
//https://www.hackerrank.com/challenges/reduced-string

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String raw = in.next();
        StringBuilder builder = new StringBuilder().append(raw);
        for (int i = 1; i < builder.length(); i++) {
            if (builder.charAt(i - 1) == builder.charAt(i)) {
                builder.delete(i - 1, i + 1);
                i = 0;
            }
        }
        if (builder.length() > 0) {
            System.out.println(builder.toString());
        } else {
            System.out.println("Empty String");
        }
    }
}
