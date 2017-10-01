public class Edge {
    private Vertex one, two;
    private int weight;

    public Edge(Vertex one, Vertex two) {
        this(one, two, 1);
    }

    public Edge(Vertex one, Vertex two, int weight) {
        this.one = one;
        this.two = two;
        this.weight = weight;
    }

    public Vertex getNeighbor(Vertex current) {
        if (!(current.equals(one) || current.equals(two))) {
            return null;
        }
        return (current.equals(one)) ? two : one;
    }


    public int hashCode() {
        return (Integer.toString(this.one.getIdx()) + "_" + Integer.toString(this.two.getIdx())).hashCode();
    }
}


