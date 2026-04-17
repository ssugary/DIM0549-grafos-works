#ifndef PARSER_HPP
#define PARSER_HPP
#pragma once

#include "../grafos.hpp"

namespace psr {

    enum class ParserType {
                TXT=0,
                INI,
                XML
            };

    enum GraphOption{
        GRAPH=0,
        DIGRAPH    
    };

    template <typename Type>
    class Parser {
        public:
            Parser() = default;
            virtual ~Parser() = default;
            virtual Graph<Type> parse(const std::string& filePath, GraphOption graphOption) = 0;

    };
}
#endif