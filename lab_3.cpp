#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Введите N: ";
    cin >> n;
    for(int i=n; i > -1; i--){
        cout << i << endl;
        if (i % 5 == 0) {
        cout << "BEEP\n";
        } 
    }
    return 0;
}
