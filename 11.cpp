// 310725_1439 Implement basic string operations such as length calculation, copy, reverse, and concatenation using character single dimensional arrays without using built-in string library functions.
#include <iostream>
using namespace std;
int stringLength(char str[]) 
{
    int length = 0;
    while (str[length] != '\0') 
    {
        length++;
    }
    return length;
}
void stringCopy(char dest[], char src[]) 
{
    int i = 0;
    while (src[i] != '\0') 
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; 
}
void stringReverse(char str[]) 
{
    int start = 0;
    int end = stringLength(str) - 1;
    while (start < end) 
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
void stringConcat(char result[], char str1[], char str2[]) 
{
    int i = 0, j = 0;
    while (str1[i] != '\0') 
    {
        result[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0') 
    {
        result[i] = str2[j];
        i++;
        j++;
    }
    result[i] = '\0'; 
}
int main() 
{
    char str1[100], str2[100], result[200], copy[100];
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;
    cout << "Length of str1: " << stringLength(str1) << endl;
    stringCopy(copy, str1);
    cout << "Copy of str1: " << copy << endl;
    stringReverse(str1);
    cout << "Reversed str1: " << str1 << endl;
    stringConcat(result, copy, str2); 
    cout << "Concatenated string (original str1 + str2): " << result << endl;
    return 0;
}
