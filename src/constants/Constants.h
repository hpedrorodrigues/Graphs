#ifndef GRAPHS_CONSTANTS_H
#define GRAPHS_CONSTANTS_H


class Constants {

public:

    class Option {

    public:

        static const int INSERT_VERTEX = 1;
        static const int REMOVE_VERTEX = 2;
        static const int INSERT_EDGE = 3;
        static const int REMOVE_EDGE = 4;
        static const int SHOW_ADJACENCY_LIST = 5;
        static const int SHOW_BREADTH_FIRST_SEARCH = 6;
        static const int SHOW_DEPTH_FIRST_SEARCH = 7;
        static const int SHOW_SHORTEST_PATH = 8;
        static const int EXIT = 9;

    };
};


#endif