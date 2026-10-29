#pragma once

namespace miit::algebra
{
	/**
	* @brief базовый класс генераторов чисел. каждый наследник реализует свой способ получения очередного числа
	*/
	class Generator
	{
		public:
			/**
			* @brief чисто виртуальный деструктор
			*/
			virtual ~Generator() = 0;

			/**
			* @brief выдать очередное число
			* @return сгенерированное число
			*/
			virtual int generate() = 0;
	};
}
