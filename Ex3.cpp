//Задача "Игра в угадывание чисел"
//Программа, которая будет загадывать число от 1 до 100 и предлагать пользователю угадать его. 
//Программа должна давать подсказки, чтобы пользователь мог угадать число за наименьшее количество попыток.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    int secretNumber = rand() % 100 + 1; // Загаданное число от 1 до 100
    int guess, attempts = 0; // Попытка пользователя и счетчик попыток
    cout << "Компьютер загадал число от 1 до 100. Попробуй угадать." << endl;

    do {
        cout << "Введите ваше предположение: ";
        cin >> guess;
        ++attempts; // Увеличиваем счетчик попыток

        if (guess < secretNumber) {
            cout << "Загаданное число больше." << endl;
        } else if (guess > secretNumber) {
            cout << "Загаданное число меньше." << endl;
        } else {
            cout << "Поздравляю! Вы угадали число " << secretNumber << " за " << attempts << " попыток." << endl;
        }
    } while (guess != secretNumber);

    return 0;
}
