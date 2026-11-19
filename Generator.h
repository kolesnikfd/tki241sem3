#pragma once

namespace miit::algebra
{
	/**
	* @brief Базовый класс генераторов чисел
	*        Каждый наследник реализует свой способ получения очередного числа
	*/
	class Generator
	{
		public:
			/**
			* @brief Чисто виртуальный деструктор
			*/
			virtual ~Generator() = 0;

			/**
			* @brief Выдать очередное число
			* @return Сгенерированное число
			*/
			virtual int generate() const = 0;
	};
}
