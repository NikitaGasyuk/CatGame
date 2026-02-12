// Подключаем файл с классом Cat. dir -> Путь до файла
#include "dir/Cat.h"

int main()
{
  // Объявление переменной класса Cat 
  Cat cat{};
  // вызов функции у класса Cat StartGame() то есть начало игры
  cat.StartGame();
  return 0;
}
