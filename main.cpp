#include <iostream>
#include "Executor.h"

using namespace std;



int main(int argc, char *argv[]) {

    string inputFile = argv[1];     string outputFile = argv[2];

    Executor::execute(inputFile,outputFile);// read and execute

}
