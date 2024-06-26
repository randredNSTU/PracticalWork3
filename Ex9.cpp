//Задача "Рейтинг студентов": В НГТУ проводятся ежемесячные экзамены.
//Нужно определить средний балл каждого студента и найти студента с наивысшим средним баллом.

#include <iostream>    // Подключаем библиотеку для ввода/вывода
#include <vector>      // Подключаем библиотеку для использования векторов
#include <algorithm>   // Подключаем библиотеку для использования алгоритмов
#include <numeric>     // Подключаем библиотеку для использования функции accumulate

using namespace std;   // Используем пространство имен std

// Структура для хранения информации о студенте
struct Student {
    string name;        // Имя студента
    vector<int> scores; // Вектор оценок студента
};

int main() {
    // Создаем вектор студентов с их именами и оценками
    vector<Student> students = {
        {"Налитов", {85, 90, 78, 92, 88}},
        {"Андриянов", {80, 85, 84, 79, 90}},
        {"Плисова", {90, 92, 88, 91, 85}}
    };

    string topStudent;          // Имя студента с наивысшим средним баллом
    double highestAverage = 0.0; // Наивысший средний балл

    // Перебираем всех студентов
    for (const auto& student : students) {
        // Вычисляем средний балл студента
        double average = accumulate(student.scores.begin(), student.scores.end(), 0.0) / student.scores.size();
        // Если средний балл текущего студента выше наивысшего среднего балла, обновляем значения
        if (average > highestAverage) {
            highestAverage = average;
            topStudent = student.name;
        }
    }

    // Выводим имя студента с наивысшим средним баллом и сам средний балл
    cout << "Студент с наивысшим средним баллом: " << topStudent << " со средним баллом " << highestAverage << endl;

    return 0; // Завершаем программу
}
