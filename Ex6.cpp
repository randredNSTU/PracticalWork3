//Задача "Казнь": На лекцию по терверу опоздало несколько человек, которых ждёт расстрел, бан и долг 10 биткоинов. 
//Необходимо вычислить имена этих счастливчиков.

#include <iostream>    // Для ввода/вывода
#include <vector>      // Для использования векторов
#include <algorithm>   // Для использования алгоритмов
#include <ctime>       // Для инициализации генератора случайных чисел
#include <cstdlib>     // Для генерации случайных чисел

using namespace std;    // Использование пространства имен std

int main() {
    // Имена студентов
    vector<string> names = {"Ilya", "Vlad", "Sasha", "Nikita", "Andrey", "Petya"};

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(0)));

    // Выбираем случайное количество опоздавших (от 1 до 6)
    int numLate = rand() % names.size() + 1;

    // Перемешиваем имена студентов
    random_shuffle(names.begin(), names.end());

    // Определяем опоздавших студентов
    vector<string> lateStudents(names.begin(), names.begin() + numLate);

    // Считаем количество опоздавших студентов
    int lateCount = count_if(lateStudents.begin(), lateStudents.end(), [](const string& name) { return !name.empty(); });

    // Выводим имена всех студентов
    cout << "Студенты: ";
    for (const auto& name : names) {  // Использование итераторов для перебора всех студентов
        cout << name << " ";
    }
    cout << endl;

    // Выводим имена опоздавших студентов
    cout << "Опоздавшие студенты: ";
    for (const auto& name : lateStudents) {  // Использование итераторов для перебора опоздавших студентов
        cout << name << " ";
    }
    cout << endl;

    // Выводим количество опоздавших студентов
    cout << "Количество опоздавших студентов: " << lateCount << endl;

    return 0;
}
