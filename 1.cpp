#include <iostream>
int stringLength(char str[]) 
{
    int i=0;
    while (str[i]!='\0') 
    {
        i++;
    }
    return i;
}
int main() 
{
    char str[20];
    std::cout << "enter a string: \n";
    std::cin.getline(str, 20);
    int len = stringLength(str);
    std::cout << "length: \n" << len << "\n";
    return 0;
}