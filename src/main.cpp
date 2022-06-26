#include <random>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include "data.h"

const int characters = 374 /*all symbols*/ - (21 * 4) /*words*/;

const std::set<int> numbers = {6, 19, 21, 24, 37, 40, 43, 56, 69, 71, 84, 97, 100, 113, 126, 139, 141, 154, 167, 170, 183};

std::string WordChoice(const std::vector<std::string>& words) {
    std::random_device rd;   // недетерминированный генератор
    std::mt19937 gen(rd());  // посеять мерсенн твистер
    std::uniform_int_distribution<> word(0, words.size() - 1); // распределять результаты между 0 и всеми эелемнтами вектора
    std::string say = words[word(gen)];
    return say;
}

/*std::vector<int> InsertNumbers() {
    std::vector<int> numbers = {6, 19, 21, 24, 37, 40, 43, 56, 69, 71, 84, 97, 100, 113, 126, 139, 141, 154, 167, 170, 183};
    return numbers;
}*/

std::vector<std::string> GeneratingOutput(const std::vector<std::string>& punctuation, const std::vector<std::string>& words) {
    std::vector<std::string> output;
    std::random_device rd;   // недетерминированный генератор
    std::mt19937 gen(rd());  // посеять мерсенн твистер
    std::uniform_int_distribution<> punct(0, punctuation.size() - 1); // распределять результаты между 0 и всеми эелемнтами вектора
    for (unsigned i = 0; i < characters; i++) {
        output.push_back(punctuation[punct(gen)]); // передать генератор в вектор
        if (numbers.count(i)) {
            output.push_back(WordChoice(words));
        }
    }
    return output;
}

std::vector<char> Convert(const std::vector<std::string>& output) {
    std::vector<char> converted;
    for (int i = 0; i < output.size(); i++) {
        for (char c : output[i]) {
            converted.push_back(c);
        }
    }
    return converted;
}

int main() {
    const std::vector<std::string> output = GeneratingOutput(punctuation_string, words);
    const std::vector<char> converted = Convert(output); 
    for (size_t i = 1; i <= addresses.size(); i++) {
        std::cout << addresses[i - 1] << " ";
        for (int j = 1; j <= 11; j++) {
            std::cout << converted[j * i];
        }
        if (i % 2 != 0) {
            std::cout << "    ";
            continue;
        }
        std::cout << std::endl;
    }
}