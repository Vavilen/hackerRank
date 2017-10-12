import java.math.BigInteger;
import java.util.Scanner;

//https://www.hackerrank.com/challenges/fibonacci-modified
public class Solution {
    public static void main(String args[]) throws Exception {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        Scanner in = new Scanner(System.in);
        BigInteger previous = in.nextBigInteger();
        BigInteger current = in.nextBigInteger();
        int n = in.nextInt();
        BigInteger next = current;
        int currentIdx = 2;
        while (currentIdx < n) {
            currentIdx++;
            next = current.multiply(current).add(previous);
            previous = current;
            current = next;
        }
        System.out.println(next);
    }
}

