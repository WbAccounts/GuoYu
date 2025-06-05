#include <iostream>
#include <string>
#include <vector>
#include <map>

std::map<int, std::string> m_map = {{2, "abc"},
                                    {3, "def"},
                                    {4, "ghi"},
                                    {5, "jkl"},
                                    {6, "mno"},
                                    {7, "pqrs"},
                                    {8, "tuv"},
                                    {9, "wxyz"}};

std::vector<std::string> res;
std::string path;

void back(const std::string &digits, int num) {
    if (num == digits.size()) {
        res.push_back(path);
        return;
    }

    int curr_digit = digits[num] - '0';
    for (char c : m_map[curr_digit]) {
        path.push_back(c);
        back(digits, num + 1);
        path.pop_back();
    }
}

std::vector<std::string> letterCombinations(std::string digits) {
    if (digits.empty()) return res;
    back(digits, 0);
    return res;
}

int main () {
    std::string digits = "";
    std::cout << "请输入：";
    std::cin >> digits;
    std::vector<std::string> combinations = letterCombinations(digits);
    for (const std::string &combo : combinations) {
        std::cout << combo << std::endl;
    }
    return 0;
}
