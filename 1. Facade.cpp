/* ---   Фасад   --- */
#include "0. Testing.h"

/*   Исполнитель №1   */
// Повар
class Cook
{
public:
	std::string GetBrownie()
	{
		return "Пироженное";
	}

	std::string GetIceCream()
	{
		return "Мороженое";
	}
};

/*   Исполнитель №2   */
// Автомобильный завод
class CarFactory
{
public:
	std::string GetCar()
	{
		return "Автомобиль";
	}

	std::string GetF1Car()
	{
		return "Болид F1";
	}
};

/*   Исполнитель №3   */
// Фарфоровый завод
class PorcelainFactory
{
public:
	std::string GetCups()
	{
		return "Чашки";
	}

	std::string GetSaucer()
	{
		return "Блюдце";
	}
};

/*   Фасад   */
// Менеджер
class Manager
{
private:
	Cook& cook;
	PorcelainFactory& porcelainFactory;

public:
	Manager(Cook inCook, PorcelainFactory inPorcelainFactory)
		: cook(inCook), porcelainFactory(inPorcelainFactory)
	{}

	std::string GetIceCream()
	{
		return cook.GetIceCream();
	}

	std::string GetCar(CarFactory& factory, int money)
	{
		if (money < 100)
			return "Not money";
		else if (money < 1000)
			return factory.GetCar();
		else
			return factory.GetF1Car();
	}

	void TeaParty()
	{
		std::cout << "Организовано чаепитие: "
			<< porcelainFactory.GetCups() << ", "
			<< porcelainFactory.GetSaucer() << ", "
			<< cook.GetBrownie() << "."
			<< std::endl;
	}
};

int main1()
{
	Cook CookNumber1;
	CarFactory LocalCarFactory;
	PorcelainFactory ChinesePorcelain;

	Manager Secretary(CookNumber1, ChinesePorcelain);

	int Budget = 700;

	std::cout << "\nПолучить мороженное: " << Secretary.GetIceCream() << '\n' << std::endl;

	// Организовать чаепитие
	Secretary.TeaParty();

	std::cout << "\nПолучить авто: " << Secretary.GetCar(LocalCarFactory, Budget) << std::endl;

	return 0;
}

/*   Вывод:
* "Фасад" действует как Менеджер, чтто работает с теми или иными исполнителями.
* "Клиенту" остаётся только запросить выполнение какой-либо заложенной операции,
* а "Фасад" уже организует и сделает за него
*/