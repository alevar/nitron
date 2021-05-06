#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <fstream>
#include <map>

#include "common.hpp"
#include "arg_parse.hpp"

int nitron_train(int argc, char **argv){
    enum Opt_TRAIN { REFERENCE   = 'x'};

    ArgParse args_train("train");

    args_train.add_string(Opt_TRAIN::REFERENCE, "reference", "", "path to the reference sequence in FASTA format", true);
    args_train.parse_args(argc, argv);

    // load reference
    std::ifstream ref_source;
    ref_source.open(args_train.get_string(Opt_TRAIN::REFERENCE));
    if (!ref_source)
    {
        std::cerr << "Can't open the reference fasta file!\n";
        exit(2);
    }

    return 0;
}
