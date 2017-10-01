import java.util.*;
import javax.swing.InternalFrameFocusTraversalPolicy;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int casesCount = in.nextInt();
        for (int i = 0; i < casesCount; i++) {
            Graph graph = new Graph();
            Graph guessedGraph = new Graph();
            int verticesCount = in.nextInt();
            for (int j = 0; j < verticesCount - 1; j++) {
                int u = in.nextInt();
                int v = in.nextInt();
                Vertex one = new Vertex(u);
                Vertex two = new Vertex(v);
                graph.addVertex(one);
                graph.addVertex(two);
                graph.addEdge(one, two);
            }

            int guessesCount = in.nextInt();
            int minimumScoreToWin = in.nextInt();
            for (int a1 = 0; a1 < guessesCount; a1++) {
                int u = in.nextInt();
                int v = in.nextInt();
                Vertex one = new Vertex(u);
                Vertex two = new Vertex(v);
                guessedGraph.addVertex(one);
                guessedGraph.addVertex(two);
                guessedGraph.addEdge(one, two, false);
            }

            for (int currentRoot = 1; currentRoot < verticesCount; currentRoot++) {
                Found guessesAreTrueCount = new Found();
                HashMap<Integer, Boolean> visited = new HashMap<>();
                process(guessesAreTrueCount, visited, currentRoot, graph, guessedGraph);
                System.out.println("root: " + currentRoot + ", guessesAreTrueCount : " + guessesAreTrueCount.getFound());
            }
            System.out.println("Done");
        }
    }

    static void process(Found found, HashMap<Integer, Boolean> visited, int current, Graph graph, Graph guessedGraph) {

        visited.put(current, true);
        Vertex vertex = graph.getVertex(current);
        ArrayList<Edge> edges = vertex.getNeighborhood();
        for (Edge edge :
                edges) {
            Vertex neighbor = edge.getNeighbor(vertex);
            if (!visited.containsKey(neighbor.getIdx()) && guessedGraph.getEdge(new Edge(vertex, neighbor)) != null) {
                found.increment();
                process(found, visited, neighbor.getIdx(), graph, guessedGraph);
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

