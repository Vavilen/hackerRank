import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

import com.sun.jmx.remote.internal.ArrayQueue;

public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String line;
        line = bi.readLine();
        int casesCount = Integer.parseInt(line);
        for (int i = 0; i < casesCount; i++) {
            line = bi.readLine();
            int verticesCount = Integer.parseInt(line);
            ArrayList<HashMap<Integer, Boolean>> graph = new ArrayList<>(verticesCount + 1);
            ArrayList<HashMap<Integer, Boolean>> guessedGraph = new ArrayList<>(verticesCount + 1);

            for (int iii = 0; iii <= verticesCount; iii++)
                graph.add(new HashMap<>());

            for (int j = 0; j < verticesCount - 1; j++) {
                line = bi.readLine();
                String[] numStr = line.split("\\s");
                int u = Integer.parseInt(numStr[0]);
                int v = Integer.parseInt(numStr[1]);
                graph.get(u).put(v, true);
                graph.get(v).put(u, true);
            }


            line = bi.readLine();
            String[] numStr = line.split("\\s");
            int guessesCount = Integer.parseInt(numStr[0]);
            int minimumScoreToWin = Integer.parseInt(numStr[1]);


            for (int iii = 0; iii <= verticesCount; iii++)
                guessedGraph.add(new HashMap<>());
            for (int j = 0; j < guessesCount; j++) {
                line = bi.readLine();
                numStr = line.split("\\s");
                int u = Integer.parseInt(numStr[0]);
                int v = Integer.parseInt(numStr[1]);
                guessedGraph.get(v).put(u, true);
            }
            int totalWon = 0;
            for (int currentRoot = 1; currentRoot <= verticesCount; currentRoot++) {
                Found guessesAreTrueCount = new Found();
                HashMap<Integer, Boolean> visited = new HashMap<>();
                process(minimumScoreToWin, guessesAreTrueCount, visited, currentRoot, graph, guessedGraph);
                if (guessesAreTrueCount.getFound() >= minimumScoreToWin) {
                    totalWon++;
                }
            }
            int D = gcd(totalWon, verticesCount);

            if (totalWon == 0)
                System.out.println(totalWon / D + "/" + 1);
            else
                System.out.println(totalWon / D + "/" + verticesCount / D);
        }
    }

    public static int gcd(int p, int q) {
        if (q == 0) {
            return p;
        }
        return gcd(q, p % q);
    }

    static void process(int minimumScoreToWin, Found found, HashMap<Integer, Boolean> visited, int current, ArrayList<HashMap<Integer, Boolean>> graph, ArrayList<HashMap<Integer, Boolean>> guessedGraph) {
        ArrayDeque<Integer> queue = new ArrayDeque<>(graph.size());
        queue.add(current);
        while (!queue.isEmpty() && found.getFound() < minimumScoreToWin) {
            current = queue.pop();
            visited.put(current, true);
            HashMap<Integer, Boolean> edges = graph.get(current);
            for (Integer edge :
                    edges.keySet()) {
                if (!visited.containsKey(edge)) {
                    if (guessedGraph.get(edge) != null) {
                        queue.add(edge);
                        if (guessedGraph.get(edge).containsKey(current)) {
                            found.increment();
                        }
                    }
                }
            }
        }
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
    }


}

