#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(const std::string& source) {
  /* TODO: Implement this method */
  Corpus tokens;

    auto non_space_positions = find_all(source.begin(), source.end(), [](char c) { return !std::isspace(c); });

    std::for_each(non_space_positions.begin(), non_space_positions.end(), [&tokens, &source](auto begin) {
        auto end = std::find_if(begin, source.end(), [](char c) { return std::isspace(c); });

        Token token(source, begin, end);

        std::transform(token.content.begin(), token.content.end(), token.content.begin(), ::tolower);

        std::inserter(tokens, tokens.end()) = token;
    });

    std::erase_if(tokens, [](const Token& token) { return token.content.empty(); });

    return tokens;
}
  


std::set<Mispelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  std::set<Mispelling> mispellings;

    std::ranges::for_each(source, [&mispellings, &dictionary](const Token& token) {
        if (dictionary.find(token.content) == dictionary.end()) { 
            Mispelling mispelling{token, {}};

            auto suggestions = dictionary
                | std::ranges::views::filter([&token](const std::string& word) {
                    return levenshtein(token.content, word) == 1; 
                })
                | std::ranges::views::transform([](const std::string& word) {
                    return word;  
                });

            std::ranges::for_each(suggestions, [&mispelling](const std::string& suggestion) {
                mispelling.suggestions.insert(suggestion);
            });

            mispellings.insert(mispelling);
        }
    });

    return mispellings;
}

/* Helper methods */

#include "utils.cpp"