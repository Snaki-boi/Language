#pragma once

#include <map>
#include <string>

/// @brief The token type will be able to hold special token types, but if the token is just a char, it will hold its aski number
enum class tokenType {
    // Data types
    _int = -1,
    _float = -2,
    _bool = -3,

    // Errors
    _invalid_key_word = -10,

    // Keywords
    _return = -50,
    _var = -51,
    _func = -52,
};
template <typename Enumeration>
auto as_int(Enumeration const value)
    -> typename std::underlying_type<Enumeration>::type
{
    return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}



std::map<std::string, tokenType> keywords {
    {"return", tokenType::_return},
    {"var", tokenType::_var},
    {"func", tokenType::_func}
};
