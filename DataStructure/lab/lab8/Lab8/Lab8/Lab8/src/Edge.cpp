class Edge {
private:
    int id;         // Edge id
    int start;      // Start node id
    int end;        // End node id
    int weight;     // Edge weight, e.g activity time

public:
    Edge() = default;

    Edge(int id, int start, int end, int weight) {
        this->id = id;
        this->start = start;
        this->end = end;
        this->weight = weight;
    }

    int getId() const {
        return id;
    }

    int getStart() const {
        return start;
    }

    int getEnd() const {
        return end;
    }

    int getWeight() const {
        return weight;
    }

};
