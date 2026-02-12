// директива препроцессора которая защищает от цикличности
#pragma once

// подключение библиотек iostream, vector, random
#include <iostream>
#include <vector>
#include <random>

// объявление пространства имен и переменных
namespace
{
	constexpr auto kMaxHappiness = 100;
	constexpr auto KMaxLives = 9;
	constexpr auto kHappinesIncrement = 10;
}
// инициализация класса
class Cat
{
public:
  // объявление публичной функции StartGame
	void StartGame();

private:

  // инициализация переменной вводимого размера карты
	int enter_size_map;
  // инициализация очков здоровья который приравнены к переменной kMaxKives
	int Health_Point{ KMaxLives };
  // инициализация переменной очков счастья
	int happines_number{};
	// инициализация переменной размера, которая будет ввести по карте
	std::size_t position_cat{};
  // инициализация вектора пути кота. с помощью него можно отслеживать путь
	std::vector<int> road_cat;
  // функция по обновлению очков счастья кота.
	void UpdateHappiness();
  // функция по обновлению очков здоровья
	void UpdateNumberOfLives();
  // функция ходьбы
	void Move();
  // функция окончания игры
	void EndGame();
  // функция случайного ивента
	void RandEvent();
};
