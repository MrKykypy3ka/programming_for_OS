#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main()
{
    ifstream inputFile("input.c");

    if (!inputFile.is_open()) {
        cout << "Не удалось открыть файл" << endl;
        return 1;
    }

    stack<int> stack;

    char ch;
    int pos = 0;
    bool errorFound = false;

    while (inputFile.get(ch))
    {
        pos++;

        if (ch == '{') {
            stack.push(pos);
        }
        else if (ch == '}') {
            if (stack.empty()) {
                cout << "Ошибка: неожиданная закрывающаяся скобка } в позиции " << pos << endl;
                errorFound = true;
                break;
            }
            else {
                stack.pop();
            }
        }
    }

    inputFile.close();

    if (!errorFound && !stack.empty()) {
        cout << "Ошибка: не хватает закрывающейся скобки } в позиции " << stack.top() << endl;
        errorFound = true;
    }

    if (!errorFound) {
        cout << "Скобки расставлены правильно" << endl;
    }

    ofstream outputFile("out.txt");

    if (!outputFile.is_open()) {
        cout << "Не удалось создать файл" << endl;
        return 1;
    }

    if (errorFound) {
        outputFile << "Ошибка при проверке скобок в файле input.c";
    }
    else {
        outputFile << "Скобки в файле input.c расставлены правильно";
    }

    cout << "Результат проверки сохранен в файле out.txt" << endl;

    outputFile.close();

    return 0;
}
