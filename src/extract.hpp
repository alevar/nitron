#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <fstream>
#include <map>

#include "common.hpp"
#include "arg_parse.hpp"

int nitron_extract(int argc, char **argv){
    enum Opt_EXTRACT { REFERENCE   = 'x'};

    ArgParse args_extract("extract");

    args_extract.add_string(Opt_EXTRACT::REFERENCE, "reference", "", "path to the reference sequence in FASTA format", true);
    args_extract.parse_args(argc, argv);

    // load reference
    std::ifstream ref_source;
    ref_source.open(args_extract.get_string(Opt_EXTRACT::REFERENCE));
    if (!ref_source)
    {
        std::cerr << "Can't open the reference fasta file!\n";
        exit(2);
    }

    return 0;
}
