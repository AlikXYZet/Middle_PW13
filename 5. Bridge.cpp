/* ---   Мост   --- */
#include "0. Testing.h"

/*   Реализация (интерфейс)   */
// Персонаж
__interface Character
{
	virtual void ReactionAttack() = 0;
	virtual void ReactionProtection() = 0;
};

/*   Абстрактный класс   */
// Реакция
class Reaction abstract
{
protected:
	Character* character;

public:
	Reaction(Character* inChar) : character(inChar) {}

	virtual void Action() = 0;
};

// Реакция: Атака
class Attack : public Reaction
{
public:
	Attack(Character* inChar) : Reaction(inChar) {}
	
	void Action() override
	{
		character->ReactionAttack();
	}
};

// Реакция: Защита
class Protection : public Reaction
{
public:
	Protection(Character* inChar) : Reaction(inChar) {}

	void Action() override
	{
		character->ReactionProtection();
	}
};

// Реализация: Маг
class Mage : public Character
{
public:
	void ReactionAttack() override
	{
		std::cout << "Магические атаки" << std::endl;
	}

	void ReactionProtection() override
	{
		std::cout << "Магическая защита" << std::endl;
	}
};

// Реализация: Мечник
class Swordsman : public Character
{
public:
	void ReactionAttack() override
	{
		std::cout << "Атаки мечом" << std::endl;
	}

	void ReactionProtection() override
	{
		std::cout << "Защита щитом" << std::endl;
	}
};

int main5()
{
	Mage Druid;
	Swordsman Paladin;

	std::cout << "Проверка атаки:" << std::endl;

	Attack attack(&Druid);
	std::cout << "Маг: ";
	attack.Action();

	attack = Attack(&Paladin);
	std::cout << "Мечник: ";
	attack.Action();


	std::cout << "\nПроверка защиты:" << std::endl;

	Protection protection(&Druid);
	std::cout << "Маг: ";
	protection.Action();

	protection = Protection(&Paladin);
	std::cout << "Мечник: ";
	protection.Action();

	return 0;
}

/*   Вывод:
* "Мост" (связь "Абстракции" к "Реализации") позволяет вызывать конкректный метод
* "Реализации" через "Абстракцию" не зависимо от класса "Абстракции".
* Можно реализовать без общего класса-интерфейса « Character ».
*/