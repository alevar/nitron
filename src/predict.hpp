#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <fstream>
#include <map>

#include "common.hpp"
#include "arg_parse.hpp"

int nitron_predict(int argc, char **argv){
    enum Opt_PREDICT { REFERENCE   = 'x'};

    ArgParse args_predict("predict");

    args_predict.add_string(Opt_PREDICT::REFERENCE, "reference", "", "path to the reference sequence in FASTA format", true);
    args_predict.parse_args(argc, argv);

    // load reference
    std::ifstream ref_source;
    ref_source.open(args_predict.get_string(Opt_PREDICT::REFERENCE));
    if (!ref_source)
    {
        std::cerr << "Can't open the reference fasta file!\n";
        exit(2);
    }

    return 0;
}
