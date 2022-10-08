#ifndef PARSER_H
#define PARSER_H 
#include "../Lexer/Lexer.h"

class Parser
{
	
public:
	Parser();
	~Parser();
	
private:
    Token current_Token() noexcept;
    Token get_Next_Token() noexcept;
    Token get_Precedence() noexcept;
    Token install_BinOP_Precedence() noexcept;
    Token parse_Num_Literals() noexcept;


    char peek() const noexcept
    {
        return *m_beg;
    }
    char get() noexcept
    {
        return *m_beg++;
    }

    const char* m_beg = nullptr;
};




#endif