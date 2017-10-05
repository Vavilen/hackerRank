import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;

// https://www.hackerrank.com/challenges/the-story-of-a-tree

public class Solution {
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static ArrayList<HashSet<Integer>> guessedGraph = new ArrayList<>();
    static int minimumScoreToWin;
    public static void main(String[] args) throws IOException {

        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String line;
        line = bi.readLine();
        int casesCount = Integer.parseInt(line);
        for (int i = 0; i < casesCount; i++) {
            graph.clear();
            guessedGraph.clear();

            line = bi.readLine();
            int verticesCount = Integer.parseInt(line);

            for (int ii = 0; ii <= verticesCount; ii++) {
                graph.add(new ArrayList<>());
                guessedGraph.add(new HashSet<Integer>());
            }
            for (int j = 0; j < verticesCount - 1; j++) {
                line = bi.readLine();
                String[] numStr = line.split("\\s");
                int u = Integer.parseInt(numStr[0]) - 1;
                int v = Integer.parseInt(numStr[1]) - 1;
                graph.get(u).add(v);
                graph.get(v).add(u);
            }


            line = bi.readLine();
            String[] numStr = line.split("\\s");
            int guessesCount = Integer.parseInt(numStr[0]);
            minimumScoreToWin = Integer.parseInt(numStr[1]);


            for (int j = 0; j < guessesCount; j++) {
                line = bi.readLine();
                numStr = line.split("\\s");
                int u = Integer.parseInt(numStr[0]) - 1;
                int v = Integer.parseInt(numStr[1]) - 1;
                guessedGraph.get(v).add(u);
            }
            Found counter = new Found();
            dfs(0, -1, counter);
            int totalWon = dfs2(0, -1, counter.getFound());
            int D = gcd(totalWon, verticesCount);

            if (totalWon == 0)
                System.out.println(totalWon / D + "/" + 1);
            else
                System.out.println(totalWon / D + "/" + verticesCount / D);
        }
    }

    static int gcd(int p, int q) {
        if (q == 0) {
            return p;
        }
        return gcd(q, p % q);
    }

    static void dfs(int u, int p, Found counter) {
        // если предположение верно
        if (guessedGraph.get(u).contains(p)) {
            // увеличим общий счетчик
            counter.increment();
        }
        // пройдемся по детям
        for (int v : graph.get(u)) {
            // пропустим значение, которое уже видели в качестве родителя
            if (v == p)
                continue;
            // сходим вглубь
            dfs(v, u, counter);
        }
    }

    static int dfs2(int u, int p, int currentCounter) {
        if (p != -1) {
            if (guessedGraph.get(p).contains(u))
                currentCounter++;
            // если верно обратное, т.е. u является родителем у p
            if (guessedGraph.get(u).contains(p))
                // убавим счетчик
                currentCounter--;
        }
        int result = 0;
        // достаточно набрали для выигрыша в игре
        if (currentCounter >= minimumScoreToWin)
            // прибавим счетчик выигранных игр
            result++;

        for (int v : graph.get(u))
            if (v != p)
                result += dfs2(v, u, currentCounter);
        return result;
    }

    static class Found {
        private int found;

        Found() {
            this.found = 0;
        }

        int getFound() {
            return found;
        }

        void increment() {
            this.found++;
        }

        void decrement() {
            this.found--;
        }
    }


}

