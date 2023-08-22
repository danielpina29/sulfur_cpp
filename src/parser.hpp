#pragma once

class Parser {

public:
    inline explicit Parser(std::vector<Token> tokens)
        : m_tokens(std::move(tokens))
    {
    }

private:
    const std::vector<Token> m_tokens;
    size_t m_index = 0;

    [[nodiscard]] std::optional<Token> peak(int offset = 1) const {
        if (m_index + offset > m_tokens.size()) {
            return {};
        } else {
            return m_tokens[m_index];
        }
    }

    Token consume() {
        return m_tokens[m_index++];
    }


};

