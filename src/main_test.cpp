#include <random>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include "data.h"

const int characters = 341 /*all symbols*/ - (21 * 4) /*words*/;
const std::set<int> numbers = {30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230};
std::set<std::string> keys_set;
std::vector<std::string> keys_vector;
std::string key;

std::string ReadLine() {
    std::string user;
    getline(std::cin, user);
    return user;
}

std::string WordChoice(const std::vector<std::string>& words) {
    std::random_device rd;   // недетерминированный генератор
    std::mt19937 gen(rd());  // посеять мерсенн твистер
    std::uniform_int_distribution<> word(0, words.size() - 1); // распределять результаты между 0 и всеми эелемнтами вектора
    std::string say = words[word(gen)];
    keys_set.insert(say);
    keys_vector.push_back(say);
    return say;
}

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

void ChoosingTheRightWord(const std::vector<std::string>& keys_vector) {
    std::random_device rd;   // недетерминированный генератор
    std::mt19937 gen(rd());  // посеять мерсенн твистер
    std::uniform_int_distribution<> k(0, keys_vector.size() - 1);
    key =  keys_vector[k(gen)];
}

/*
int RelevanceCheck(const std::string& user, const std::string& key) {

}
*/

int main() {
    const std::vector<std::string> output = GeneratingOutput(punctuation_string, words);
    const std::vector<char> converted = Convert(output);
    std::string user;
    for (int i = 0; i < 4; i++) {
        for (size_t i = 0; i < addresses.size(); i++) {
            std::cout << addresses[i] << " ";
            for (int j = 1; j <= 10; j++) {
                std::cout << converted[j + (10 * i)];
            }
            std::cout << std::endl;
        }
        user = ReadLine();
        if (user == key) {
            std::cout << "Win!" << std::endl;
            break;
        }
        std::cout << "-----------------" << std::endl;
        std::cout << "----NICE  TRY----" << std::endl;
        std::cout << "-----------------" << std::endl;
    }
/*
    std::cout << "-----------------" << std::endl;
    std::cout << "Output vector - ";

    for (std::string c : output) {
        std::cout << c;
    }
    std::cout << std::endl;
*/
}