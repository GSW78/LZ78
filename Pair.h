#ifndef Pair
class Pair{
    private:
        int node;
        char edge;

    public:
        Pair(int node, char edge);
        int getNode();
        char getEdge();
        void setNode(int node);
        void setEdge(char edge);
};
#endif