#include "Lexer.h"

bool is_space(char c) noexcept
{
    switch (c) {
    case ' ':
    case '\t':
    case '\r':
    case '\n':
        return true;
    default:
        return false;
    }
}

bool is_digit(char c) noexcept
{
    switch (c) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return true;
    default:
        return false;
    }
}


bool is_Decimal(char c) noexcept
{
    switch (c) {
    case '.':
        return true;
    default:
        return false;
    }
}

bool is_identifier_char(char c) noexcept
{
    switch (c) {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'I':
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'O':
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '_':
        return true;
    default:
        return false;
    }
}

Token Lexer::tok(Token::Kind kind) noexcept 
{ 
    return Token(kind, m_beg++, 1);
}

Token Lexer::next() noexcept {
    while (is_space(peek())) get();

    switch (peek()) {
    case '\0':
        return Token(Token::Kind::End, m_beg, 1);
    default:
        return tok(Token::Kind::Unexpected);
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'I':
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'O':
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
        return identify_Identifier();
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return identify_Number();
    case '(':
        return tok(Token::Kind::LeftParen);
    case ')':
        return tok(Token::Kind::RightParen);
    case '[':
        return tok(Token::Kind::LeftSquare);
    case ']':
        return tok(Token::Kind::RightSquare);
    case '{':
        return tok(Token::Kind::LeftCurly);
    case '}':
        return tok(Token::Kind::RightCurly);
    case '<':
        return tok(Token::Kind::LessThan);
    case '>':
        return tok(Token::Kind::GreaterThan);
    case '=':
        return tok(Token::Kind::Equal);
    case '+':
        return tok(Token::Kind::Plus);
    case '-':
        return tok(Token::Kind::Minus);
    case '*':
        return tok(Token::Kind::Asterisk);
    case '/':
        return identify_Slash_Or_Comment();
    case '#':
        return tok(Token::Kind::Hash);
    case '.':
        return tok(Token::Kind::Dot);
    case ',':
        return tok(Token::Kind::Comma);
    case ':':
        return tok(Token::Kind::Colon);
    case ';':
        return tok(Token::Kind::Semicolon);
    case '\'':
        return tok(Token::Kind::SingleQuote);
    case '"':
        return tok(Token::Kind::DoubleQuote);
    case '|':
        return tok(Token::Kind::Pipe);
    case '!':
        return tok(Token::Kind::Not);
    }
}

Token Lexer::identify_Identifier() noexcept
{
    const char* start = m_beg;
    get();
    while (is_identifier_char(peek())) get();
    return Token(Token::Kind::Identifier, start, m_beg);
}

Token Lexer::identify_Number() noexcept
{
    const char* start = m_beg;
    get();
    while (is_digit(peek()) || is_Decimal(peek())) get();
    return Token(Token::Kind::Number, start, m_beg);
}


Token Lexer::identify_Slash_Or_Comment() noexcept 
{
    const char* start = m_beg;
    get();
    if (peek() == '/') {
        get();
        start = m_beg;
        while (peek() != '\0') 
        {
            if (get() == '\n') 
            {
                return Token(Token::Kind::Comment, start,
                    std::distance(start, m_beg) - 1);
            }
        }
        return Token(Token::Kind::Unexpected, m_beg, 1);
    }
    else {
        return Token(Token::Kind::Slash, start, 1);
    }
}