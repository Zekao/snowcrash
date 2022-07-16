#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <sstream>

int incr = 0;

int main(int argc, char **argv)
{
    int i = 0;
    char val;
	std::ifstream	test(argv[1]);
    std::string str;
    std::string token;
    if (!(getline(test, token)))
        return (0);
    const char    *str2 = token.c_str();
    while(str2[i])
    {
        val = str2[i] - incr;
        str += val;
        i++;
        incr++;
    }
    std::cout << "Token: " << str << std::endl;
}
