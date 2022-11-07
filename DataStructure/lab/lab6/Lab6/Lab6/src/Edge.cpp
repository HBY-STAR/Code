class Edge {
private:
    int v1;     // Vertex1
    int v2;     // Vertex2
    int len;    // Length of this edge

public:
    Edge(int v1, int v2, int len) {
        this->v1 = v1;
        this->v2 = v2;
        this->len = len;
    }

    int getV1() const {
        return v1;
    }

    int getV2() const {
        return v2;
    }

    int getLen() const {
        return len;
    }
};
