import java.util.HashMap;

public class Graph {
    HashMap<Integer, Vertex> vertices;
    HashMap<Integer, Edge> edges;

    Graph() {
        this.edges = new HashMap<>();
        this.vertices = new HashMap<>();
    }

    boolean addEdge(Vertex one, Vertex two) {
        return addEdge(one, two, true);
    }

    boolean addEdge(Vertex one, Vertex two, boolean isBedirectional) {
        if (one.equals(two)) {
            return false;
        }
        Edge edge = new Edge(one, two);
        if (edges.containsKey(edge.hashCode())) {
            return false;
        }
        edges.put(edge.hashCode(), edge);
        one.addNeighbor(edge);
        if (isBedirectional) {
            two.addNeighbor(edge);
        }
        return true;
    }

    Edge getEdge(Edge edge) {
         if (edges.containsKey(edge.hashCode())) {
             return edges.get(edge.hashCode());
         }
         return null;
    }

    boolean addVertex(Vertex vertex) {
        if (this.vertices.containsKey(vertex.getIdx())) {
            return false;
        }
        this.vertices.put(vertex.getIdx(), vertex);
        return true;
    }

    Vertex getVertex( int idx ) {
        if (vertices.containsKey(idx)) {
            return vertices.get(idx);
        }
        return null;
    }


}
