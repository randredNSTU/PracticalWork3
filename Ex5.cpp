//Игра "Блек-джек": Игроки играют против дилера, пытаясь набрать 21 очко или как можно ближе, но не больше.

#include <iostream>    // Подключение библиотеки для ввода-вывода
#include <vector>      // Подключение библиотеки для работы с векторами
#include <algorithm>   // Подключение библиотеки алгоритмов
#include <ctime>       // Подключение библиотеки для работы со временем
#include <cstdlib>     // Подключение стандартной библиотеки C

using namespace std;   // Использование стандартного пространства имен

// Функция для подсчета очков в руке
int countPoints(const vector<int>& hand) {
    int sum = 0;    // Инициализация суммы очков
    int aces = 0;   // Инициализация количества тузов

    // Использование алгоритма for_each для подсчета очков
    for_each(hand.begin(), hand.end(), [&](int card) {
        if (card >= 10) {
            sum += 10;  // Карты с номиналом 10 и выше дают 10 очков
        } else if (card == 1) {
            aces++;     // Увеличиваем количество тузов
            sum += 11;  // Сначала считаем туз как 11
        } else {
            sum += card;  // Добавляем номинал карты к сумме
        }
    });

    // Если перебор и есть тузы, уменьшаем сумму
    while (sum > 21 && aces > 0) {
        sum -= 10;  // Уменьшаем сумму на 10
        aces--;     // Уменьшаем количество тузов
    }

    return sum;  // Возвращаем сумму очков
}

// Функция для вывода карты
string cardToString(int card) {
    if (card == 1) return "A";    // Если карта - туз, возвращаем "A"
    if (card == 11) return "J";   // Если карта - валет, возвращаем "J"
    if (card == 12) return "Q";   // Если карта - дама, возвращаем "Q"
    if (card == 13) return "K";   // Если карта - король, возвращаем "K"
    return to_string(card);       // Возвращаем номинал карты как строку
}

// Функция для вывода руки игрока или дилера
void printHand(const vector<int>& hand, const string& name) {
    cout << name << " карты: ";   // Выводим имя игрока
    // Используем итераторы для обхода вектора карт
    for (auto it = hand.begin(); it != hand.end(); ++it) {
        cout << cardToString(*it) << " ";  // Выводим карту
    }
    // Выводим сумму очков в руке
    cout << "(Очки: " << countPoints(hand) << ")" << endl;
}

int main() {
    // Инициализируем генератор случайных чисел текущим временем
    srand(static_cast<unsigned int>(time(0)));

    // Колода карт
    vector<int> deck;
    for (int i = 1; i <= 13; ++i) {     // Для каждого номинала карт от 1 до 13
        for (int j = 0; j < 4; ++j) {   // Для каждой из четырех мастей
            deck.push_back(i);          // Добавляем карту в колоду
        }
    }

    // Перемешиваем колоду с помощью random_shuffle
    random_shuffle(deck.begin(), deck.end());

    vector<int> playerHand;   // Рука игрока
    vector<int> dealerHand;   // Рука дилера

    // Раздаем по две карты игроку и дилеру
    playerHand.push_back(deck.back());  // Добавляем карту игроку
    deck.pop_back();                    // Удаляем карту из колоды
    dealerHand.push_back(deck.back());  // Добавляем карту дилеру
    deck.pop_back();                    // Удаляем карту из колоды
    playerHand.push_back(deck.back());  // Добавляем карту игроку
    deck.pop_back();                    // Удаляем карту из колоды
    dealerHand.push_back(deck.back());  // Добавляем карту дилеру
    deck.pop_back();                    // Удаляем карту из колоды

    // Выводим карты игрока
    printHand(playerHand, "Ваши"); //printHand - итератор
    // Выводим первую карту дилера
    cout << "Первая карта дилера: " << cardToString(dealerHand[0]) << endl;

    // Ход игрока
    while (true) {
        cout << "Хотите взять еще карту или остановиться? (Y/N): ";
        char choice;      // Переменная для хранения выбора игрока
        cin >> choice;    // Ввод выбора
        if (choice == 'Y') {
            playerHand.push_back(deck.back());  // Добавляем карту игроку
            deck.pop_back();                    // Удаляем карту из колоды
            printHand(playerHand, "Ваши");      // Выводим карты игрока
            if (countPoints(playerHand) > 21) { // Проверяем перебор
                cout << "Перебор! Вы проиграли." << endl;
                return 0;   // Завершаем игру
            }
        } else if (choice == 'N') {
            break;    // Игрок остановился, выходим из цикла
        }
    }

    // Ход дилера
    printHand(dealerHand, "Карты дилера");   // Выводим карты дилера
    while (countPoints(dealerHand) < 17) {   // Дилер берет карту, если меньше 17 очков
        dealerHand.push_back(deck.back());   // Добавляем карту дилеру
        deck.pop_back();                     // Удаляем карту из колоды
        printHand(dealerHand, "Карты дилера");  // Выводим карты дилера
    }

    int playerPoints = countPoints(playerHand);  // Очки игрока
    int dealerPoints = countPoints(dealerHand);  // Очки дилера

    // Определение победителя
    if (dealerPoints > 21 || playerPoints > dealerPoints) {
        cout << "Вы выиграли!" << endl;    // Игрок выиграл
    } else if (playerPoints < dealerPoints) {
        cout << "Дилер выиграл!" << endl;  // Дилер выиграл
    } else {
        cout << "Ничья!" << endl;          // Ничья
    }

    return 0;  // Завершаем программу
}
