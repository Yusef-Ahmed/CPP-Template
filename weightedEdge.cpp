struct Edge {
    int u, v;
    double weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};