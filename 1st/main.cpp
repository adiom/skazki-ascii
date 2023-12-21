#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int width = 10;
const int height = 5;

// Игровое поле
char gameBoard[height][width];

// Параметры игрока
int playerX, playerY;

// Функция для отрисовки игрового поля
void drawBoard() {
    system("cls"); // Очищаем консоль перед отрисовкой нового кадра

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << gameBoard[i][j] << ' ';
        }
        cout << endl;
    }
}

// Функция для генерации лабиринта
void generateMaze() {
    srand(time(0));

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            // Генерируем случайные стены
            if (rand() % 3 == 0) {
                gameBoard[i][j] = '#';
            } else {
                gameBoard[i][j] = ' ';
            }
        }
    }

    // Устанавливаем начальное положение игрока
    playerX = 0;
    playerY = 0;
    gameBoard[playerY][playerX] = 'P';

    // Устанавливаем выход из лабиринта
    int exitX = width - 1;
    int exitY = height - 1;
    gameBoard[exitY][exitX] = 'E';
}

// Функция для обработки движения игрока
void movePlayer(char direction) {
    gameBoard[playerY][playerX] = ' '; // Очищаем предыдущую позицию игрока

    switch (direction) {
        case 'w':
            if (playerY > 0 && gameBoard[playerY - 1][playerX] != '#') {
                playerY--;
            }
            break;
        case 's':
            if (playerY < height - 1 && gameBoard[playerY + 1][playerX] != '#') {
                playerY++;
            }
            break;
        case 'a':
            if (playerX > 0 && gameBoard[playerY][playerX - 1] != '#') {
                playerX--;
            }
            break;
        case 'd':
            if (playerX < width - 1 && gameBoard[playerY][playerX + 1] != '#') {
                playerX++;
            }
            break;
    }

    gameBoard[playerY][playerX] = 'P'; // Устанавливаем новую позицию игрока
}

int main() {
    generateMaze();

    char move;
    while (true) {
        drawBoard();
        cout << "Введите направление (w - вверх, s - вниз, a - влево, d - вправо): ";
        cin >> move;

        if (move == 'q') {
            break; // Завершаем игру, если введен 'q'
        }

        movePlayer(move);
    }

    return 0;
}

