#pragma once

#include <string>
#include <vector>


enum TokenType {
    _exit,
    _semi,
    _int_lit,
};

struct Token {
    TokenType type;
    std::optional<std::string> value {};
};

class Tokenizer {

public:
    inline explicit Tokenizer(std::string src)
        : m_src(std::move(src))
    {
    }

    std::vector<Token> tokenize() {
        std::string buffer;
        std::vector<Token> tokens;

        while (peak().has_value()) {
            if (std::isalpha(peak().value())) {
                buffer.push_back(consume());
                while (peak().has_value() && std::isalpha(peak().value())) {
                    buffer.push_back(consume());
                }
                if (buffer == "exit") {
                    tokens.push_back(Token { .type = TokenType::_exit });
                    buffer.clear();
                    continue;
                }
            } else if (std::isdigit(peak().value())) {
                buffer.push_back(consume());
                while(peak().has_value() && std::isdigit(peak().value())){
                    buffer.push_back(consume());
                }
                tokens.push_back(Token { .type = TokenType::_int_lit, .value = buffer });
                buffer.clear();
                continue;
            } else if (peak().value() == ';') {
                consume();
                tokens.push_back(Token {.type = TokenType::_semi});
                continue;
            } else if (std::isspace(peak().value())) {
                consume();
                continue;
            }
        }
        m_index = 0;

        return tokens;
    }

private:
    const std::string m_src;
    size_t m_index = 0;

    [[nodiscard]] std::optional<char> peak(int offset = 1) const {
        if (m_index + offset > m_src.length()) {
            return {};
        } else {
            return m_src[m_index];
        }
    }

    char consume() {
        return m_src[m_index++];
    }

};