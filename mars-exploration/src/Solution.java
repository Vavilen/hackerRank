import java.util.Scanner;

//https://www.hackerrank.com/challenges/mars-exploration

public class Solution {

    static int marsExploration(String s) {
        int correctionsNumber = 0;
        int currentSosIdx = 0;
        char[] sos = {'S', 'O', 'S'};
        for (char ch : s.toCharArray()) {
            if (ch != sos[currentSosIdx]) {
                correctionsNumber++;
            }
            currentSosIdx = currentSosIdx == 2 ? 0 : currentSosIdx + 1;
        }
        return correctionsNumber;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        int result = marsExploration(s);
        System.out.println(result);
        in.close();
    }
}

