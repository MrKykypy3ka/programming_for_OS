#include <iostream>

using namespace std;

int main()
{
        int n;
    double x, y, s = 0;
    
    cout << "Введите количество вершин многоугольника: ";
    cin >> n;
    
    double* x_arr = new double[n];
    double* y_arr = new double[n];
    
    cout << "Введите координаты вершин многоугольника (x, y):\n";
    for (int i = 0; i < n; i++) {
        cout << "Вершина " << i + 1 << ": ";
        cin >> x >> y;
        x_arr[i] = x;
        y_arr[i] = y;}
    
    for (int i = 0; i < n - 1; i++) {
    s += (x_arr[i] + x_arr[i+1]) * (y_arr[i+1] - y_arr[i]);}
    s += (x_arr[n-1] + x_arr[0]) * (y_arr[0] - y_arr[n-1]);
    s = abs(s / 2);
    
    cout << "Площадь многоугольника равна " << s << endl;
    
    delete[] x_arr;
    delete[] y_arr;
    
    return 0;
}
