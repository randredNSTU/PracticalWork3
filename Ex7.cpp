//Задача "Штурм 502 кабинета": Студенты не успевают сдавать лабораторные работы и они начинают приходить заранее и занимать очередь. 
//Необходимо найти количество таких студентов.

#include <iostream>    // Для ввода/вывода
#include <vector>      // Для использования векторов
#include <algorithm>   // Для использования алгоритмов
#include <ctime>       // Для инициализации генератора случайных чисел
#include <cstdlib>     // Для генерации случайных чисел
#include <numeric>     // Для использования функции accumulate

using namespace std;   // Использование пространства имен std

int main() {
    const int totalStudents = 150;  // Всего студентов
    const int days = 10;            // Количество дней
    vector<int> studentsPerDay(days);  // Вектор для хранения количества студентов по дням

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(0)));

    // В 1 день приходит 2 человека
    studentsPerDay[0] = 2;

    // Генерация количества студентов для последующих дней
    for (int i = 1; i < days; ++i) {
        // Количество студентов в текущий день должно быть больше, чем в предыдущий день
        studentsPerDay[i] = studentsPerDay[i - 1] + rand() % ((totalStudents - studentsPerDay[i - 1]) / (days - i) + 1);
    }

    // Вывод количества студентов по дням
    cout << "Количество студентов по дням:" << endl;
    for (int i = 0; i < days; ++i) {
        cout << "День " << i + 1 << ": " << studentsPerDay[i] << " студентов" << endl;
    }

    // Подсчет общего количества студентов за все дни
    int totalCount = accumulate(studentsPerDay.begin(), studentsPerDay.end(), 0);
    cout << "Сколько раз в сумме студенты пораньше приходили в 502 кабинет за все дни: " << totalCount << endl;

    return 0;
}
