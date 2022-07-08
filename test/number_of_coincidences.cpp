#include <algorithm>
#include <iterator>
#include <iostream>
#include <set>
#include <string>
#include <vector>

const std::string key = "damn";

std::string ReadLine() {
    std::string input;
    getline(std::cin, input);
    return input;
}

std::set<char> ConvertStringToSetChar(const std::string& word) {
    std::set<char> exhaust;
    for (char c : word) {
        exhaust.insert(c);
    }
    return exhaust;
}

int NumbersOfCoincidences(const std::set<char>& skey, const std::set<char>& suser) {
    std::vector<int> intersection;

    std::set_intersection(std::cbegin(skey), std::cend(skey),
                          std::cbegin(suser), std::cend(suser),
                          std::back_inserter(intersection));
    
    return intersection.size();
}

void OutputSet(const std::set<char>& lots_of) {
    for (char c : lots_of) {
        std::cout << c;
    }
    std::cout << std::endl;
}

int main() {
    std::string user = ReadLine();
    const std::set<char> skey = ConvertStringToSetChar(key);
    const std::set<char> suser = ConvertStringToSetChar(user);

    OutputSet(skey);
    OutputSet(suser);
    std::cout << NumbersOfCoincidences(skey, suser) << std::endl;
}
