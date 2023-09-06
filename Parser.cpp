//
// Created by Frank Yang on 2023/8/14.
//

#include <iostream>
#include "Fraction.h"
#include "Calculation.cpp"

inline std::string removeSpace(const std::string &str)
{
    std::string temp = "";

    for (int i = 0; i <= str.size()-1; i++)
        if (str[i] != ' ')
            temp += str[i];

    return temp;
}

inline std::string parse(const std::string &input)
{
    std::string inputWithoutSpace = removeSpace(input);

    if (inputWithoutSpace.size() && (
            (inputWithoutSpace[0] >= 0x41 && inputWithoutSpace[0] <= 0x5A) ||
            (inputWithoutSpace[0] >= 0x61 && inputWithoutSpace[0] <=0x7A) ) )
        return inputWithoutSpace;

    else // expression
    {
        Fraction result = recognizingExpression(inputWithoutSpace);
        std::string resultString = result.fractionToString();
        if (resultString.size() >= 3 && resultString[resultString.size() - 2] == '/' && resultString[resultString.size() - 1] == '1')
        {
            resultString.pop_back();
            resultString.pop_back();
        }
        return resultString;
    }
}
