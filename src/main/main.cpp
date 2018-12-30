/**************************************************************************
 * File       [ main.cpp ]
 * Author     [ wlkb83 ]
 * Synopsis   [ demonstration for the usage of parser.h ]
 * Usage      [ ./parser [inputfileName] ]
 * Date       [ 2014/12/28 created ]
/**************************************************************************/

#include "parser.h"
#include "../graph.hpp"

int main(int argc, char **argv)
{
    if( argc < 2 ){ cout << "Usage: ./parser [input_file_name] [output_file_name]" << endl; return 1; }

    AlgParser parser;

    // read the file in the first argument
    if( ! parser.read( argv[1] ) ) { return 1; }
    // show the information of the input
    // cout << "grid " << parser.gNumHTiles() << " " << parser.gNumVTiles() << endl;
    // cout << "capacity " << parser.gCapacity() << endl;
    // cout << "num net " << parser.gNumNets() << endl;

    Graph* graph = new Graph();
    Circuit* circuit = new Circuit(parser.gCapacity(), parser.gNumHTiles(), parser.gNumVTiles());
    graph->setCircuit(circuit);

    for (int idNet = 0; idNet < parser.gNumNets(); ++idNet){
        pair<int, int> posS = parser.gNetStart( idNet );
        pair<int, int> posE = parser.gNetEnd( idNet );
        Net* net = new Net(idNet, posS, posE);
        circuit->pushNet(net);
        // cout << idNet << " " << posS.first << " " << posS.second << " "
        //                      << posE.first << " " << posE.second << endl;
    }
    circuit->setBoundingBox();
    graph->solve();
    circuit->outfile( argv[2] );
    
	cout << "----------------------" << endl;
	cout << "-- Complete parsing --" << endl;
	cout << "----------------------" << endl;
    return 0;
}

