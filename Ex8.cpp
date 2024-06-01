//Задача "Ограбление". Студенты из АБс-322 провинившись перед преподавателем задолжали по 10 биткойнов с человека. 
//Определить сколько человек провинились и посчитать общую сумму долга.

#include <iostream>    // Для ввода/вывода
#include <vector>      // Для использования векторов
#include <algorithm>   // Для использования алгоритмов
#include <ctime>       // Для инициализации генератора случайных чисел
#include <cstdlib>     // Для генерации случайных чисел
#include <numeric>     // Для использования функции accumulate
#include <iomanip>     // Для управления форматированием вывода

using namespace std;   // Использование пространства имен std

int main() {
    const int totalStudents = 32;             // Общее количество студентов
    const int debtPerStudent = 10;            // Долг на одного студента в биткойнах
    const double bitcoinToUSD = 67663.0;      // Стоимость 1 биткойна в долларах

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(0)));

    // Случайное определение количества провинившихся студентов
    int numGuiltyStudents = rand() % totalStudents + 1;

    // Создание вектора с долгами студентов
    vector<int> debts(totalStudents, 0);
    fill_n(debts.begin(), numGuiltyStudents, debtPerStudent);

    // Подсчет общего долга в биткойнах
    int totalDebtBitcoin = accumulate(debts.begin(), debts.end(), 0);

    // Подсчет общего долга в долларах
    double totalDebtUSD = totalDebtBitcoin * bitcoinToUSD;

    // Вывод результатов
    cout << "Количество провинившихся студентов: " << numGuiltyStudents << endl;
    cout << "Общий долг в биткойнах: " << totalDebtBitcoin << " BTC" << endl;
    cout << fixed << setprecision(2); // Установка формата вывода для чисел с плавающей точкой
    cout << "Общий долг в долларах: " << totalDebtUSD << " $" << endl;

    return 0;
}
