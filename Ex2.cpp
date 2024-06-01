//Задача "Игра в крестики-нолики с компьютером". 
//Программа, которая будет играть с пользователем в игру в крестики-нолики, используя простую логику для ходов компьютера.

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

const int SIZE = 3; // Размер игрового поля (3x3)

void initBoard(vector<vector<char>>& board) {
    for (int i = 0; i < SIZE; ++i) { // Проход по строкам
        vector<char> row(SIZE, ' '); // Создание строки размером SIZE, заполненной пробелами
        board.push_back(row); // Добавление строки в доску
    }
}

void printBoard(const vector<vector<char>>& board) {
    cout << "  1   2   3 " << endl; // Вывод верхней строки с номерами столбцов
    for (int i = 0; i < SIZE; ++i) { // Проход по строкам
        cout << i + 1 << " "; // Вывод номера строки
        for (int j = 0; j < SIZE; ++j) { // Проход по столбцам
            cout << board[i][j]; // Вывод текущего элемента доски
            if (j < SIZE - 1) cout << " | "; // Вывод разделителя между элементами (кроме последнего)
        }
        cout << endl; // Переход на новую строку
        if (i < SIZE - 1) cout << " ---+---+---" << endl; // Вывод разделителя между строками (кроме последней)
    }
    cout << endl; // Пустая строка для удобства чтения
}

bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < SIZE; ++i) { // Проверка выигрыша по строкам и столбцам
        if (all_of(board[i].begin(), board[i].end(), [player](char c) { return c == player; }) || // Проверка строки
            all_of(board.begin(), board.end(), [i, player](const vector<char>& row) { return row[i] == player; })) { // Проверка столбца
            return true; // Если есть выигрышная строка или столбец, возвращаем true
        }
    }

    if (all_of(board.begin(), board.end(), [player, n = 0](const vector<char>& row) mutable { return row[n++] == player; }) || // Проверка диагонали 1
        all_of(board.begin(), board.end(), [player, n = 0](const vector<char>& row) mutable { return row[SIZE - 1 - n++] == player; })) { // Проверка диагонали 2
        return true; // Если есть выигрыш по диагонали, возвращаем true
    }

    return false; // Если нет выигрышной комбинации, возвращаем false
}

bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) { // Проход по каждой строке
        if (any_of(row.begin(), row.end(), [](char c) { return c == ' '; })) { // Если есть хотя бы один пустой символ в строке
            return false; // Игра не окончена ничьей
        }
    }
    return true; // Если нет пустых ячеек, игра окончена ничьей
}

void computerMove(vector<vector<char>>& board, char symbol) {
    srand(time(0)); // Инициализация генератора случайных чисел
    int row, col;
    do {
        row = rand() % SIZE; // Генерация случайной строки
        col = rand() % SIZE; // Генерация случайного столбца
    } while (board[row][col] != ' '); // Повторять, пока не будет найдена пустая ячейка
    board[row][col] = symbol; // Установка символа компьютера в выбранную ячейку
}

void countSymbols(const vector<vector<char>>& board, int& xCount, int& oCount) {
    xCount = oCount = 0; // Обнуление счетчиков
    for (const auto& row : board) { // Проход по каждой строке
        xCount += count(row.begin(), row.end(), 'X'); // Подсчет количества крестиков
        oCount += count(row.begin(), row.end(), 'O'); // Подсчет количества ноликов
    }
}

int main() {
    vector<vector<char>> board; // Доска
    initBoard(board); // Инициализация доски

    int choice; // Выбор пользователя (кто начнет игру)
    cout << "Выберите, кто будет ходить первым (1 - вы, 2 - компьютер): "; // Запрос выбора пользователя
    cin >> choice; // Ввод выбора пользователя

    char playerSymbol, computerSymbol; // Символы игроков
    if (choice == 1) { // Если выбрано начать игру с пользователем
        cout << "Выберите символ (X - крестик, O - нолик): "; // Запрос выбора символа
        cin >> playerSymbol; // Ввод символа пользователя
        computerSymbol = (playerSymbol == 'X') ? 'O' : 'X'; // Выбор символа для компьютера
    } else { // Если выбрано начать игру с компьютером
        srand(time(0)); // Инициализация генератора случайных чисел
        computerSymbol = (rand() % 2 == 0) ? 'X' : 'O'; // Случайный выбор символа для компьютера
        playerSymbol = (computerSymbol == 'X') ? 'O' : 'X'; // Определение символа для пользователя
        cout << "Компьютер играет за " << (computerSymbol == 'X' ? "крестики" : "нолики") << endl; // Вывод выбранной стороны компьютера
        cout << "Вы играете за " << (playerSymbol == 'X' ? "крестики" : "нолики") << endl; // Вывод выбранной стороны пользователя
    }

    char currentPlayer = (choice == 1) ? playerSymbol : computerSymbol; // Определение, чей ход первый

    bool gameOver = false; // Переменная для отслеживания завершения игры
    int moveCount = 0; // Счетчик ходов

    while (!gameOver) { // Главный цикл игры
        printBoard(board); // Вывод текущего состояния доски
        moveCount++; // Увеличение счетчика ходов
        cout << "Ход №" << moveCount << ". Сейчас ходит: " << (currentPlayer == playerSymbol ? "вы" : "компьютер") << endl; // Вывод текущего игрока

        if (currentPlayer == playerSymbol) { // Если ходит игрок
            int row, col; // Переменные для хода игрока
            cout << "Введите ваш ход (строка и столбец): "; // Приглашение к вводу хода
            cin >> row >> col; // Ввод строки и столбца
            row--; // Приведение номера строки к индексу массива
            col--; // Приведение номера столбца к индексу массива
            if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') { // Проверка корректности хода
                board[row][col] = currentPlayer; // Установка символа игрока на доску
                if (checkWin(board, currentPlayer)) { // Проверка на победу
                    printBoard(board); // Вывод окончательного состояния доски
                    cout << (currentPlayer == playerSymbol ? "Вы победили!" : "Компьютер победил!") << endl; // Вывод победителя
                    gameOver = true; // Игра завершена
                } else if (checkDraw(board)) { // Проверка на ничью
                    printBoard(board); // Вывод окончательного состояния доски
                    cout << "Ничья!" << endl; // Вывод сообщения о ничьей
                    gameOver = true; // Игра завершена
                }
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Смена игрока
            } else { // Если ход некорректен
                cout << "Некорректный ход. Попробуйте снова." << endl; // Вывод сообщения об ошибке
                moveCount--; // Уменьшение счетчика ходов
            }
        } else { // Если ходит компьютер
            computerMove(board, currentPlayer); // Ход компьютера
            if (checkWin(board, currentPlayer)) { // Проверка на победу компьютера
                printBoard(board); // Вывод окончательного состояния доски
                cout << (currentPlayer == playerSymbol ? "Вы победили!" : "Компьютер победил!") << endl; // Вывод победителя
                gameOver = true; // Игра завершена
            } else if (checkDraw(board)) { // Проверка на ничью
                printBoard(board); // Вывод окончательного состояния доски
                cout << "Ничья!" << endl; // Вывод сообщения о ничьей
                gameOver = true; // Игра завершена
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Смена игрока
        }
    }

    int xCount, oCount; // Переменные для подсчета количества символов на доске
    countSymbols(board, xCount, oCount); // Подсчет символов на доске
    cout << "Количество крестиков (X): " << xCount << endl; // Вывод количества крестиков
    cout << "Количество ноликов (O): " << oCount << endl; // Вывод количества ноликов

    return 0; // Возврат нуля, как признак успешного завершения программы
}
