#include <iostream>
using namespace std;
// Dada una cadena de caracteres que contiene una frase, escriba una función que reciba 
// un puntero a la frase y la invierta. Por ejemplo, si la frase es huevos revueltos, la frase 
// invertida será sotleuver soveuh

void reverseString(char *str)
{
    
    if(*str == '\0')
    {
        return;
    }
    reverseString(str + 1);
    cout << *str;
}

int main()
{
    char str []  = "Hola";
    cout << "Original String: " << str << endl;
    cout << "Reversed String: ";
    reverseString(str);
    return 0;
}