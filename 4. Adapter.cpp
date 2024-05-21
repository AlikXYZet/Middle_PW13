/* ---   Адаптер (двусторонний)   --- */
#include "0. Testing.h"

// Аналоговый токовый сигнал: 4-20 мА
class s_mA
{
private:
	// Фактическое значение
	double MilliAmps;

public:
	// Конструктор
	s_mA(double inA) : MilliAmps(inA) {}

	// Получить значение
	double Get_mA()
	{
		return MilliAmps;
	}
};

// Аналоговый сигнал напряжения: 0-10 В
class s_V
{
private:
	// Фактическое значение
	double Volts;

public:
	// Конструктор
	s_V(double inV) : Volts(inV) {}

	// Получить значение
	double Get_V()
	{
		return Volts;
	}
};

// Двусторонний "Адаптер" для преобразования аналогового сигнала
class Adapter : public s_mA, public s_V
{
public:
	// Конструктор при входных значениях тока
	Adapter(s_mA inA)
		: s_mA(inA),
		s_V((inA.Get_mA() - 4) / 16 * 10)
	{}

	// Конструктор при входных значениях напряжения
	Adapter(s_V inV)
		: s_V(inV),
		s_mA((inV.Get_V() / 10 * 16) + 4)
	{}
};

int main4()
{
	std::cout << "===   Adapter Test version V1 ===" << std::endl;
	// Тест преобразования тока в напряжение
	s_mA A1(12.5);
	Adapter AV1(A1);

	std::cout
		<< "Adapter AV1(A1):" << '\n'
		<< "Volts: " << AV1.Get_V() << '\n'
		<< "mAmps: " << AV1.Get_mA() << '\n'
		<< std::endl;

	// Тест преобразования напряжения в ток
	s_V V1(5.3125);
	Adapter AV2(V1);

	std::cout
		<< "Adapter AV2(V1):" << '\n'
		<< "Volts: " << AV2.Get_V() << '\n'
		<< "mAmps: " << AV2.Get_mA() << '\n'
		<< std::endl;

	// Тест вывода значений из "Адаптера"
	Adapter Test = s_V(5);
	s_V* V2 = new Adapter(Test);
	s_mA* A2 = new Adapter(Test);

	std::cout
		<< "Test:" << '\n'
		<< "V2 = " << V2->Get_V() << " V" << '\n'
		<< "A2 = " << A2->Get_mA() << " mA" << '\n'
		<< std::endl;

	return 0;
}

/*   Вывод:
* "Адаптер" позволяет преобразовывать и хранить информацию из одного класса в другой,
* что позволяет работать с несовместимыми интерфейсами (классами)
*/