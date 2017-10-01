import java.util.ArrayList;

public class Vertex {
    private ArrayList<Edge> neighborhood;
    private int idx;

    public Vertex(int idx) {
        this.idx = idx;
        neighborhood = new ArrayList<>();
    }

    public void addNeighbor(Edge neighbor) {
        neighborhood.add(neighbor);
    }

    public int getIdx() {
        return idx;
    }

    public ArrayList<Edge> getNeighborhood() {
        return neighborhood;
    }

    public boolean equals(Vertex current) {
        if (current.idx == this.idx) {
            return true;
        }
        return false;
    }

}


