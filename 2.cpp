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
void stringCopy(char b[], char a[]) 
{
    int i=0;
    while (a[i]!='\0') 
    {
        b[i]=a[i];
        i++;
    }
}
int main() 
{
    char str1[20], str2[20];
    std::cout << "enter a string: \n";
    std::cin.getline(str1, 20);
    stringCopy(str2, str1);
    int len = stringLength(str1);
    std::cout << "length: \n" << len << "\n";
    std::cout << "copy: \n" << str2 << "\n";
    return 0;
}