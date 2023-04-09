#include "common_includes.h"


int main()
{
    std::string str = "";
    constexpr int rows{ 7 };
    for (int i = 0; i < rows; i++)
    {
        switch (i)
        {
        case 0:
        case 6:
            str = "   *   ";
            break;
        case 1:
        case 5:
            str = "  ***  ";
            break;
        case 2:
        case 4:
            str = " ***** ";
            break;
        default:
            str = "*******";
            break;
        }

        std::cout << str << std::endl;
    }

    return 0;
}
