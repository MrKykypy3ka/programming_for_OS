#include <iostream>

using namespace std;

bool polindrom(string s){
    for(int i=0; i < s.length(); i++){
        if(s[i] != s[s.length() - 1 - i]){
            return false;
        }
    }
    return true;
}


int main()
{
    string s;
    cout << "Введите число или строку: ";
    cin >> s;
    cout << polindrom(s);
}