#include <iostream>
#include "graph.h"
#include "io.h"
#include "stack.h"
#include "performance.h"
#include "reductions.h"

int main(int argc, char* argv[]) {
    std::string graph_file = argv[1];
    //std::cout << graph_file << std::endl;

    Graph* g = readGraph(graph_file);
    Graph verifier = *g;

    g->printGraph();

    long crossing_count = g->countCrossingsMarlon();
    std::cout << "number of crossings in default g: " << crossing_count << std::endl;

    // Which reductions to use
    std::vector<general_reduction*> reductions;
    //reductions.push_back(new ZeroEdge_reduction);
    //reductions.push_back(new Complete_reduction);
    //reductions.push_back(new ZeroCrossings_reduction);
    //reductions.push_back(new Twins_reduction);
    
    std::cout << std::endl;
    auto result = BranchAndReduce(g, reductions);
    g->printGraph();
    std::cout << "Crossings BranchAndReduce: " << result.second << std::endl;
    
    if (g->verifier(verifier)) {
        std::cout << "Graph is valid"<<std::endl;
    }
    else {
        std::cout << "Graph is NOT valid" << std::endl;
    }

    //Testing on test set
    
    /*
    std::vector<int> modes;
    modes.push_back(1);
    modes.push_back(2);
    modes.push_back(3);
    modes.push_back(4);
    modes.push_back(5);

    
    for (auto mode : modes){
        calculatePerformance("../tiny_test_set", "../performance_data/" + std::to_string(mode), mode);
        std::cout << "Mode " << mode << " done." << std::endl;
    }
    */ 
}

