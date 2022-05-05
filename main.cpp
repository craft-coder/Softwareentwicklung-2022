#include <iostream>
#include <string>
#include <vector>

std::vector<int> checkArguments(int argc, char** argv) {
    if (argc < 2) {
        return std::vector<int> {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    }

    auto inputNumber = std::atoi(argv[1]);

    std::vector<int> result = {};
    for (auto i=0; i<inputNumber; i++) {
        result.push_back(i);
    }

    return result;
}

int main(int argc, char** argv) {
    
    auto numbers = checkArguments(argc, argv);

    for (auto number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}
