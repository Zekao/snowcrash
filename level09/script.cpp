#include <iostream>
#include <string.h>
#include <fstream>

int incr = 0;

int main(int argc, char **argv)
{
	std::ifstream	test(argv[1]);
    int i = 0;
    char val;
    std::string str;
    std::string token;
    while (getline(test, token))
        ;
    const char    *str2 = token.c_str();
    std::cout << "content of token: " << token << std::endl;
    // convert argv[1] to hex   and store in val
    std::cout << "Converted string: " << val << std::endl;
    i = 0;
    while(str2[i])
    {
        val = str2[i] + incr;
        str += val;
        i++;
        incr++;
    }
    std::cout << "Token: " << str << std::endl;
}
