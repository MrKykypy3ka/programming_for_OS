#include <iostream>

using namespace std;

int main()
{
    float n = 0, m;
    for(int i=0; i < 5; i++){
        cout << "Введите возраст " << i+1 << " человека: ";
        cin >> n;
        if (m < n) {
            m = n;
        } 
    }
    cout << "Стоимость билетов составит " << 50.0 * ((100 - m) / 100);
    return 0;
}
