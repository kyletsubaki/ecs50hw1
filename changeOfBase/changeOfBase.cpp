#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <exception>


int char_to_digit(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    if (c >= 'A' && c <= 'Z') return 10 + (c - 'A');
    throw std::invalid_argument("Invalid character");
}

char digit_to_char(int value) {
    if (value < 10) return static_cast<char>('0' + value);
    if (value >= 10 && value < 36) return static_cast<char>('A' + (value - 10));
    throw std::invalid_argument("Digit out of range");
}

long long convert_to_base_10(std::vector<int>& init_num, int init_base) {
    long long sum = 0;
    for (auto digit : init_num) {
        sum = sum * init_base + digit;  
    }
    return sum;
}

std::string convert_to_new_base(long long base_10_num, int new_base) {
    std::vector<int> new_num;
    while (base_10_num > 0) {
        new_num.push_back(base_10_num % new_base);
        base_10_num /= new_base;
    }
    std::reverse(new_num.begin(), new_num.end());
    std::string final_new_num;
    for (auto digit : new_num) {
        char c = digit_to_char(digit);
        final_new_num.push_back(c);
    }
    return final_new_num;
}

int main(void) {
    int init_base;
    int new_base;
    std::string init_num_str;
    std::vector<int> init_num;

    std::cout << "Please enter the number's base: ";
    std::cin >> init_base;
    std::cout << "Please enter the number: ";
    std::cin >> init_num_str;
    std::cout << "Please enter the new base: ";
    std::cin >> new_base;
    
    for (auto init_num_char : init_num_str) {
        init_num.push_back(char_to_digit(init_num_char));
    }
    long long new_num = convert_to_base_10(init_num, init_base);
    std::string final_new_num = convert_to_new_base(new_num, new_base);
    std::cout << init_num_str << " base " << init_base << " is " << final_new_num << " base " << new_base << std::endl;
}