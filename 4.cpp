#include <iostream>
int stringLength(char str[]) 
{
    int i = 0;
    while (str[i] != '\0') 
    {
        i++;
    }
    return i;
}
void stringCopy(char b[], char a[]) 
{
    int i = 0;
    while (a[i] != '\0') 
    {
        b[i] = a[i];
        i++;
    }
}
void stringReverse(char str[]) 
{
    int length = 0;
    while (str[length] != '\0') 
    {
        length++;
    }
    for (int i = 0; i < length / 2; i++) 
    {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}
void stringConcat(char dest[], char src[]) 
{
    int i = 0;
    while (dest[i] != '\0') 
    {
        i++;
    }
    int j = 0;
    while (src[j] != '\0') 
    {
        dest[i]=src[j];
        i++;
        j++;
    }
}
int main() 
{
    char str1[40], str2[20], str3[20];
    std::cout << "enter first string: \n";
    std::cin.getline(str1, 20);
    std::cout << "enter second string: \n";
    std::cin.getline(str3, 20);
    stringCopy(str2, str1);
    int len = stringLength(str1);
    std::cout << "length: " << len << "\n";
    std::cout << "copy: " << str2 << "\n";
    stringReverse(str2);
    std::cout << "reversed copy: " << str2 << "\n";
    stringConcat(str1, str3);
    std::cout << "concatenated string: " << str1 << "\n";
    return 0;
}