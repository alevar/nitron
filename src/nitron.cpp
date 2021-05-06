#include <iostream>
#include <cstring>

#include "arg_parse.hpp"

#include "extract.hpp"
#include "train.hpp"
#include "predict.hpp"
#include "select.hpp"

void print_help()
{
    std::cerr << "nitron\n"
              << "Modes:\n"
              << "\textract\t\textract data for training\n"
              << "\ttrain\t\ttrain model on the data\n"
              << "\tpredict\t\tpredict validity of introns\n"
              << "\tselect\t\tselect transcripts based on the data\n";
}

int main(int argc, char ** argv)
{
    if (argc <= 1)
    {
        print_help();
    }
    else if (strcmp(argv[1], "extract") == 0)
    {
        std::cerr << "extracting splice junction properties\n";
        const int argc_build = argc - 1;
        char* argv_build[argc_build];
        memcpy(argv_build, argv + 1, argc_build * sizeof(char*));
        nitron_extract(argc_build, argv_build);
    }
    else if(strcmp(argv[1], "train") == 0)
    {
        std::cerr << "training a model on the junction data\n";
        const int argc_find = argc - 1;
        char* argv_find[argc_find];
        memcpy(argv_find, argv + 1, argc_find * sizeof(char*));
        nitron_train(argc_find, argv_find);
    }
    else if(strcmp(argv[1], "predict") == 0)
    {
        std::cerr << "predicting validity of junctions in the dataset\n";
        const int argc_parents = argc - 1;
        char* argv_parents[argc_parents];
        memcpy(argv_parents, argv + 1, argc_parents * sizeof(char*));
        nitron_predict(argc_parents, argv_parents);
    }
    else if(strcmp(argv[1], "select") == 0)
    {
        std::cerr << "selecting transcripts based on the data\n";
        const int argc_aln = argc - 1;
        char* argv_aln[argc_aln];
        memcpy(argv_aln, argv + 1, argc_aln * sizeof(char*));
        nitron_select(argc_aln, argv_aln);
    }
    else
    {
        std::cerr << "Unrecognized Mode: please consult the help manual\n";
        print_help();
    }

    return 0;
}
