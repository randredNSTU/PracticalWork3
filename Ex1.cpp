//Задача "Перемешивание карт". Программа, которая будет перемешивать колоду карт и выводить результат.

#include <iostream>      // Подключаем библиотеку для работы с вводом и выводом
#include <vector>        // Подключаем библиотеку для работы с вектором
#include <algorithm>     // Подключаем библиотеку для использования алгоритмов
#include <random>        // Подключаем библиотеку для генерации случайных чисел
#include <chrono>        // Подключаем библиотеку для работы с временем
#include <map>           // Подключаем библиотеку для работы с ассоциативными контейнерами

using namespace std;     // Используем пространство имен std, чтобы не писать std:: перед каждым вызовом

// Определение структуры карты
struct Card {
    string suit;         // Масть карты (например, Черви)
    string rank;         // Тип карты (например, Туз)
};

// Функция для печати колоды
void printDeck(const vector<Card>& deck) {
    for (const auto& card : deck) {   // Для каждой карты в колоде
        cout << card.rank << " " << card.suit << endl;  // Выводим тип и масть карты
    }
    cout << endl;  // Печатаем пустую строку для разделения
}

int main() {
    // Определение мастей и типа
    vector<string> suits = {"Черви", "Бубны", "Трефы", "Пики"};  // Вектор строк для мастей карт
    vector<string> ranks = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Валет", "Дама", "Король", "Туз"};  // Вектор строк для типа карт

    // Создание колоды карт
    vector<Card> deck;  // Вектор для хранения колоды карт
    for (const auto& suit : suits) {   // Для каждой масти
        for (const auto& rank : ranks) {  // Для каждого типа
            deck.push_back(Card{suit, rank});  // Добавляем карту в колоду
        }
    }

    // Печать исходной колоды
    cout << "Исходная колода:" << endl;  // Выводим сообщение о том, что сейчас будет исходная колода
    printDeck(deck);  // Вызываем функцию для печати колоды

    // Перемешивание колоды
    auto seed = chrono::system_clock::now().time_since_epoch().count();  // Получаем текущее время в качестве зерна для генератора случайных чисел
    shuffle(deck.begin(), deck.end(), default_random_engine(seed));  // Перемешиваем колоду, используя случайное зерно

    // Печать перемешанной колоды
    cout << "Перемешанная колода:" << endl;  // Выводим сообщение о том, что сейчас будет перемешанная колода
    printDeck(deck);  // Вызываем функцию для печати колоды

    // Дополнительная задача: Подсчет карт по мастям
    map<string, int> suitCount;  // Создаем map для подсчета количества карт каждой масти
    for (const auto& card : deck) {  // Для каждой карты в колоде
        suitCount[card.suit]++;  // Увеличиваем счетчик для соответствующей масти
    }

    // Печать результата подсчета
    cout << "Подсчет карт по мастям:" << endl;  // Выводим сообщение о начале подсчета карт по мастям
    for (const auto& entry : suitCount) {  // Для каждого элемента в map
        cout << entry.first << ": " << entry.second << endl;  // Выводим масть и количество карт этой масти
    }

    return 0;  // Завершаем выполнение программы
}
