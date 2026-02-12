#include "Cat.h"

void Cat::UpdateHappiness()
{
  // обновление очков счастья при помощи переменной пространства имен
    happines_number += kHappinesIncrement;
  // добавление 1 в вектор
    road_cat.push_back(1);
}

void Cat::UpdateNumberOfLives()
{
  // уменьшение очков здоровья
    Health_Point--;
  // добавление -1 в вектор
    road_cat.push_back(-1);
}

void Cat::Move()
{
  // увеличение значения позиции кота, то есть его движение вперед
    position_cat++;
    road_cat.push_back(0);
}

void Cat::EndGame()
{
  // проверка как игра закончится. Если очки здоровья опустятся до нуля или меньше нуля то выведится одно сообщение,
  // если наберется нужное количество очков счастья то другое сообщение, если позиция кота будет равна вводимому значению,
  // то кот прошел полностью мир и изучил его.
    if (Health_Point <= 0)
    {
        std::cout << "Cat ran is live... We Lose..." << std::endl;
    }
    else if (happines_number == kMaxHappiness)
    {
        std::cout << "Cat is Happy!!! We Win!!!" << std::endl;
    }
    else if (position_cat == enter_size_map)
    {
        std::cout << "World Explored we win !!!" << std::endl;
    }
  // вывод полного пути
    std::cout << "Full road " << std::endl;
    for (int i = 0; i < road_cat.size(); i++)
    {
        std::cout << road_cat[i] << " ";
    }
}

void Cat::RandEvent()
{
  // создаем генератор псевдослучайных чисел и при вызове функции
  // генерируем случайное значение и при каждом значении вызываем нужную функцию
    std::random_device random_dev;
    std::mt19937 random_engine{ random_dev() };
    std::uniform_int_distribution distibute{ -1, 1 };
    int RandEvent = distibute(random_engine);
    if (RandEvent == 0)
    {
        Move();
    }
    else if (RandEvent == 1)
    {
        UpdateHappiness();
    }
    else if (RandEvent == -1)
    {
        UpdateNumberOfLives();
    }
}

void Cat::StartGame()
{
  // Просим пользователя ввести размер карты и запускаем цикл который вызывает случайные события влияющие на кота
  // P.S. можно сюда поставить генератор случайных чисел в определенном диапазоне и не вводить вручную.
    std::cout << "Where size world map?" << std::endl;
    std::cin >> enter_size_map;
    while (Health_Point > 0 && happines_number != kMaxHappiness && position_cat != enter_size_map)
    {
        RandEvent();
    }
  // если одно из условий выполнилось, то игра останавливается
    if(Health_Point <= 0 || happines_number == kMaxHappiness || position_cat == enter_size_map)
    {
        EndGame();
    }
}
