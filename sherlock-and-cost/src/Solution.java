import java.util.Scanner;

//https://www.hackerrank.com/challenges/sherlock-and-cost

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testsCount = in.nextInt();
        for (int i = 0; i < testsCount; i++) {
            int numCount = in.nextInt();
            int[] b = new int[numCount];
            for (int j = 0; j < numCount; j++) {
                b[j] = in.nextInt();
            }
            int currentAsCurrent = 0;
            int currentAsOne = 0;
            int newCurrentAsCurrent;
            int newCurrentAsOne;
            for (int j = 1; j < numCount; j++) {
                newCurrentAsCurrent = Math.max(currentAsCurrent + Math.abs(b[j] - b[j - 1]), currentAsOne + Math.abs(b[j] - 1));
                newCurrentAsOne = Math.max(currentAsCurrent + Math.abs(b[j - 1] - 1), currentAsOne);
                currentAsCurrent = newCurrentAsCurrent;
                currentAsOne = newCurrentAsOne;
            }
            System.out.println(Math.max(currentAsCurrent, currentAsOne));
        }
    }
}
