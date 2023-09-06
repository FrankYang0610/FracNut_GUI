#include <iostream>

inline void getHelp()
{
    std::cout << "Please directly enter the mathematical expression." << std::endl;
    std::cout << "Using [a/b] for representing the fraction a/b (no need to simplify)" << std::endl;
    std::cout << "The program will return for a fraction value (simplified)" << std::endl;

    std::cout << std::endl;

    std::cout << "Using lastResult() for reviewing the last result, copy() for copying. copy(lastResult()) is allowed for copying the last result." << std::endl;
    std::cout << "Using remove() for remove the storage. remove(clipboard()) or remove(lastResult()) are all allowed." << std::endl;

    std::cout << std::endl;

    return;
}
