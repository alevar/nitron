#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <fstream>
#include <map>

#include "common.hpp"
#include "arg_parse.hpp"

int nitron_select(int argc, char **argv){
    enum Opt_SELECT { REFERENCE   = 'x'};

    ArgParse args_select("select");

    args_select.add_string(Opt_SELECT::REFERENCE, "reference", "", "path to the reference sequence in FASTA format", true);
    args_select.parse_args(argc, argv);

    // load reference
    std::ifstream ref_source;
    ref_source.open(args_select.get_string(Opt_SELECT::REFERENCE));
    if (!ref_source)
    {
        std::cerr << "Can't open the reference fasta file!\n";
        exit(2);
    }

    return 0;
}
