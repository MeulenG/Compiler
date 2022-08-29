#include "Compiler/Compiler.h"
#include <llvm/ADT/APFloat.h>
#include <llvm/IR/IRBuilder.h>
#include <filesystem>

using namespace std;


int main(int argc, char* argv[])
{
    string filename = argv[1];
    ifstream input;

	// get filename from path
	std::filesystem::path path(filename);
    path.filename();

    input.open(filename);
    // Check input parameters
    if (argc == 1) {
        printf("Warning: invalid number of arguments\n");
        return -1;
    }
    else if (!input.is_open()) {
        cout << "Unable to open file";
        return -1;
    }
    else {
        while (input)
        {
            string line;
            getline(input, line);
            cout << line << '\n';
        }
}
    input.close();

	return 0;
}