
#include <iostream>

#define LOG(x) std::cout << x << std::endl

#include <string>
#include <vector>

class LongestConsec
{
public:
    static std::string longestConsec(const std::vector<std::string> &strarr, int k);
};

std::string LongestConsec::longestConsec(const std::vector<std::string> &strarr, int k)
{
    if (k <= 0 || strarr.size() < k)
    {
        return "";
    }

    std::string tempString;
    std::string maxString;
    int maxStringLengh = 0;

    int maxElm = strarr.size() - k + 1;
    for (int ptr = 0; ptr < maxElm; ptr++)
    {
        for (int strPtr = 0; strPtr < k; strPtr++)
        {
            tempString += strarr.at(strPtr + ptr);
        }
        if (tempString.size() > maxStringLengh)
        {
            maxStringLengh = tempString.size();
            maxString = tempString;
        }
        tempString.clear();
    }

    return maxString;
}

int main(int argc, char *argv[])
{
    std::vector<std::string> arr = {"ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx", "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh"};
    LOG(LongestConsec::longestConsec(arr, 1));
}