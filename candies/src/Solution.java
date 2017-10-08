import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static long candies(int n, int[] arr) {
        // Complete this function
        long result = 0;
        int[] candies = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            if (i == 0) {
                if (arr[i] > arr[i+1]) {
                    candies[i] = 2;
                } else {
                    candies[i] = 1;
                }
                continue;
            }

            if (i == arr.length - 1) {
                if (arr[i] < arr[i - 1]) {
                    candies[i] = 1;
                    continue;
                }
            }

            if (arr[i] > arr[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            } else if (arr[i] < arr[i - 1]) {
                candies[i] = 1;
            } else {
                candies[i] = 1;
            }
        }

        for (int i = arr.length - 1; i >= 0; i--) {
            if (i > 0) {
                if (arr[i] < arr[i-1] && candies[i] >= candies[i-1]) {
                    candies[i - 1] = candies[i] + 1;
                }
            }
            result += candies[i];
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] arr = new int[n];
        for(int arr_i = 0; arr_i < n; arr_i++){
            arr[arr_i] = in.nextInt();
        }
        long result = candies(n, arr);
        System.out.println(result);
        in.close();
    }
}

