#include <iostream>
#include <vector>
#include <ctime>
#include <boost/algorithm/string.hpp>

std::vector<int> computePrefixFunction(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> pi(m);
    int k = 0;
    for (int i = 1; i < m; i++) {
        while (k > 0 && pattern[k] != pattern[i]) {
            k = pi[k - 1];
        }
        if (pattern[k] == pattern[i]) {
            k++;
        }
        pi[i] = k;
    }
    return pi;
}

std::vector<int> KMP(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();
    std::vector<int> pi = computePrefixFunction(pattern);
    std::vector<int> matches;
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k > 0 && pattern[k] != text[i]) {
            k = pi[k - 1];
        }
        if (pattern[k] == text[i]) {
            k++;
        }
        if (k == m) {
            matches.push_back(i - m + 1);
            k = pi[k - 1];
        }
    }
    return matches;
}

int main() {
    std::string stringForKMP;
    std::cout << "Insert source string:" << std::endl;
    std::cin >> stringForKMP;
    std::cout << "Insert pattern for search:" << std::endl;
    std::string pattern;
    std::cin >> pattern;
    std::clock_t start = clock();
    std::vector<int> matches = KMP(stringForKMP, pattern);
    std::cout << "Duration KMP find in ms - " << clock() - start << std::endl;
    int index{};
    start = clock();
    while ((index = stringForKMP.find(pattern, index)) != std::string::npos) {
        index += pattern.length();
    }
    std::cout << "Duration std::find in ms - " << clock() - start << std::endl;
    std::vector<boost::iterator_range<std::string::const_iterator>> matches2;
    start = clock();
    boost::find_all(matches2, stringForKMP, pattern);
    std::cout << "Duration boost::find_all in ms - " << clock() - start << std::endl;
    return 0;
}
