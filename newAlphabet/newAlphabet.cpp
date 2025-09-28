#include <iostream>
#include <string>

char translate(unsigned int num) {
    int pos;
    for (auto i = 0; i < 26; i++) {
        if (num & (1 << i)) {
            pos = i;
            break;
        }
    }

    char initial;
    int is_upper = (num >> 26) & 1;
    if (is_upper == 1) {
        initial = 'A';
    } else if (is_upper == 0) {
        initial = 'a';
    }
    return (initial + pos);
}

int main(int argc, char *argv[]) {
    std::string word;
    for (auto i = 1; i < argc; i++) {
        unsigned int num = std::stoul(argv[i]);
        word += translate(num);
    }
    std::cout << "You entered the word: " << word << std::endl;
}