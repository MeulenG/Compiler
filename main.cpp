// Preprocess Directives
#include "Ast/Ast.h"
#include "CodeGen/CodeGen.h"
#include "Compiler/Compiler.h"
#include "Lexer/Lexer.h"
#include "Lexer/Syntax.h"
#include "Parser/Parser.h"
#include "TypeChecker/TypeChecker.h"
#include <llvm/ADT/APFloat.h>
#include <llvm/IR/IRBuilder.h>
#include <filesystem>

using namespace std;


int main(int argc, char* argv[])
{
    string filename = argv[1]; // argv[0] is the program name
    ifstream input; // input from the file

	// get filename from path
	filesystem::path path(filename);
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

    // Convert program to tokens

    // TypeCheck first?

    // Parse tokens

    // Generate IR

    // Convert to Machine Code

    // Spit out the binary

	return 0;
}