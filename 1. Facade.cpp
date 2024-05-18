/* ---   �����   --- */
#include "0. Testing.h"

/*   ����������� �1   */
// �����
class Cook
{
public:
	std::string GetBrownie()
	{
		return "����������";
	}

	std::string GetIceCream()
	{
		return "���������";
	}
};

/*   ����������� �2   */
// ������������� �����
class CarFactory
{
public:
	std::string GetCar()
	{
		return "����������";
	}

	std::string GetF1Car()
	{
		return "����� F1";
	}
};

/*   ����������� �3   */
// ���������� �����
class PorcelainFactory
{
public:
	std::string GetCups()
	{
		return "�����";
	}

	std::string GetSaucer()
	{
		return "������";
	}
};

/*   �����   */
// ��������
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
		std::cout << "������������ ��������: "
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

	std::cout << "\n�������� ����������: " << Secretary.GetIceCream() << '\n' << std::endl;

	// ������������ ��������
	Secretary.TeaParty();

	std::cout << "\n�������� ����: " << Secretary.GetCar(LocalCarFactory, Budget) << std::endl;

	return 0;
}

/*   �����:
* "�����" ��������� ��� ��������, ���� �������� � ���� ��� ����� �������������.
* "�������" ������� ������ ��������� ���������� �����-���� ���������� ��������,
* � "�����" ��� ���������� � ������� �� ����
*/