// Preprocess Directives
//#include "Ast/Ast.h"
//#include "CodeGen/CodeGen.h"
//#include "Compiler/Compiler.h"
#include "Lexer/Lexer.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
//#include "Lexer/Syntax.h"
//#include "Parser/Parser.h"
//#include "TypeChecker/TypeChecker.h"
//#include <llvm/ADT/APFloat.h>
//#include <llvm/IR/IRBuilder.h>
#include <filesystem>
#ifdef __TRACE
#define TRACE(...) printf(__VA_ARGS__)
#else
#define TRACE
#endif

int main(int argc, char* argv[])
{
    // Error handling
    if (argc == 1)
    {
        printf("Error: invalid number of arguments, please specify your file name\n");
        return -1;
    }
    // read the file given in the first argument
    std::ifstream f(argv[1]); //taking file as inputstream
    std::string str;
    // get filename from path
    std::filesystem::path path(argv[1]);
    path.filename();
    // Read file and save it in string variable
    if (f) {
        std::ostringstream ss;
        ss << f.rdbuf(); // reading data
        str = ss.str();
    }
    // Lexical Analysis
    // Convert string to const char*
    auto code = str.c_str();
    
    // Instansiate Lexer
    Lexer lex(code);
    // Make sure that tokens we read are not EOF else we just spit it out
    for (auto tokens = lex.next(); not tokens.is_one_of(Token::Kind::End, Token::Kind::Unexpected); tokens = lex.next())
    {
        TRACE("tokens.lexeme() = %s", tokens.lexeme());
        std::cout << static_cast<int>(tokens.kind()) << " | " << tokens.lexeme() << "\n";
    }
    return 0;

    // TypeCheck first?

    // Parse tokens

    // Generate IR

    // Convert to Machine Code

    // Spit out the binary
}