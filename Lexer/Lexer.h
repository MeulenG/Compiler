#ifndef LEXER_H
#define LEXER_H

#include <iomanip>
#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <filesystem>
#include <fstream>
#include <string>
#include <regex>
#include <algorithm>

class Token {
public:
    enum class Kind {
        Decimal_Number,
        Number,
        Identifier,
        Keyword,
        LeftParen,
        RightParen,
        LeftSquare,
        RightSquare,
        LeftCurly,
        RightCurly,
        LessThan,
        GreaterThan,
        Equal,
        Plus,
        Minus,
        Asterisk,
        Slash,
        Hash,
        Dot,
        Not,
        And,
        Comma,
        Pipe,
        Colon,
        Semicolon,
        SingleQuote,
        DoubleQuote,
        Comment,
        End,
        Unexpected,
    };

    Token(Kind kind) noexcept : m_kind{ kind } {}

    Token(Kind kind, const char* beg, std::size_t len) noexcept : m_kind{ kind }, m_lexeme(beg, len) {}

    Token(Kind kind, const char* beg, const char* end) noexcept : m_kind{ kind }, m_lexeme(beg, std::distance(beg, end)) {}

    Kind kind() const noexcept 
    {
        return m_kind;
    }

    void kind(Kind kind) noexcept 
    { 
        m_kind = kind;
    }

    bool is(Kind kind) const noexcept
    {
        return m_kind == kind;
    }

    bool is_not(Kind kind) const noexcept 
    { 
        return m_kind != kind;
    }

    bool is_one_of(Kind k1, Kind k2) const noexcept
    { 
        return is(k1) || is(k2);
    }

    template <typename... Ts>
    bool is_one_of(Kind k1, Kind k2, Ts... ks) const noexcept
    {
        return is(k1) || is_one_of(k2, ks...);
    }

    std::string_view lexeme() const noexcept
    { 
        return m_lexeme;
    }

    void lexeme(std::string_view lexeme) noexcept
    {
        m_lexeme = std::move(lexeme);
    }
    std::list<Token::Kind> token_List = {};

private:
    Kind             m_kind{};
    std::string_view m_lexeme{};
};

class Lexer {
public:
    std::string recognize_Keyword;
    std::list<Token::Kind> token_List = {};
    Lexer(const char* beg) noexcept : m_beg{ beg } {}

    Token next() noexcept;

private:
    Token identify_Identifier() noexcept;
    Token identify_Number() noexcept;
    Token identify_Slash_Or_Comment() noexcept;
    Token identify_Keyword() noexcept;
    Token tok(Token::Kind) noexcept;

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