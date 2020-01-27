#ifndef Pair
class Pair{
    private:
        int node;
        int n_son;
        char edge;
    public:
        Pair(int node, char edge, int n_son);
        int getNode();
        int getN_son();
        char getEdge();
        void setNode(int node);
        void setEdge(char edge);
};
#endif
