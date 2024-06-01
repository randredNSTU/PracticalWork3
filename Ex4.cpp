//Виселица: игрок должен угадать слово, задуманное компьютером, за ограниченное количество попыток.

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// Функция для выбора случайного слова из списка
string chooseWord() {
    vector<string> words = {"apple", "banana", "orange", "grape", "kiwi", "peach"};
    srand(time(0));
    return words[rand() % words.size()];
}

// Функция для отображения угаданных и неугаданных букв слова
void displayWord(const string& word, const vector<char>& guessedLetters) {
    for (char letter : word) {
        if (find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end()) {
            cout << letter << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

int main() {
    const int maxAttempts = 6; // Максимальное количество попыток
    string word = chooseWord(); // Выбираем слово для угадывания
    int attemptsLeft = maxAttempts; // Количество оставшихся попыток
    vector<char> guessedLetters; // Вектор для хранения угаданных букв

    cout << "Добро пожаловать в игру 'Виселица'!" << endl;

    while (attemptsLeft > 0) {
        cout << "Угадайте слово: ";
        displayWord(word, guessedLetters);

        // Проверяем, было ли угадано всё слово
        if (find_if(word.begin(), word.end(), [&](char letter) {
            return find(guessedLetters.begin(), guessedLetters.end(), letter) == guessedLetters.end();
        }) == word.end()) {
            cout << "Поздравляем! Вы угадали слово '" << word << "'!" << endl;
            break;
        }

        // Запрос ввода буквы от пользователя
        char guess;
        cout << "Введите букву: ";
        cin >> guess;

        // Проверяем, была ли уже введена эта буква
        if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            cout << "Вы уже вводили эту букву." << endl;
            continue;
        }

        // Добавляем введенную букву в список угаданных
        guessedLetters.push_back(guess);

        // Проверяем, есть ли введенная буква в загаданном слове
        if (word.find(guess) == string::npos) {
            cout << "Такой буквы нет в слове. Осталось попыток: " << --attemptsLeft << endl;
        }
    }

    if (attemptsLeft == 0) {
        cout << "Извините, вы проиграли. Загаданное слово было: " << word << endl;
    }

    return 0;
}
