#include <iostream>

using namespace std;

int main()
{
    int passengers, freeSeats;
    cout << "Введите количество пассажиров, ожидающих на автобусной станции: ";
    cin >> passengers;
    freeSeats = 50 - passengers % 50;
    cout << "Количество свободных мест в последнем автобусе: " << freeSeats;
    return 0;
}
