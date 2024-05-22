/* ---   Легковес   --- */
#include "0. Testing.h"

#include <unordered_map>

// Структура для подобных характеристик оружия
struct SharedState
{
	std::string NameType;
	int Damage;
	float RechargeTime;

	// Конструктор
	SharedState(const std::string inNameType, int inDamage, float inRechargeTime)
		: NameType(inNameType), Damage(inDamage), RechargeTime(inRechargeTime)
	{}

	// Перегрузка оператора для вывода информации
	friend std::ostream& operator<<(std::ostream& cout, const SharedState& ss)
	{
		return cout << ss.NameType << " , " << ss.Damage << " , " << ss.RechargeTime;
	}
};

/*   Легковес   */
// Оружие
class Weapon
{
private:
	// Указатель на общие данные
	SharedState* sState;

public:
	// Конструктор
	Weapon(SharedState& inSharedState)
		: sState(&inSharedState)
	{}

	// Перегрузка оператора для вывода информации
	friend std::ostream& operator<<(std::ostream& cout, const Weapon& w)
	{
		return cout << "[ " << *(w.sState) << " ]";
	}
};

/*   Фабрика Легковесов   */
// Фабрика Оружий
class WeaponFactory
{
private:
	std::unordered_map<std::string, Weapon*> m_weapon;

public:
	// Добавить элемент в контейнер и вернуть указатель на него
	Weapon* addWeapon(SharedState& inSharedState)
	{
		// Если элемент не встречался по названию
		if (m_weapon.find(inSharedState.NameType) == m_weapon.end())
		{
			// то добавить в контейнер
			m_weapon[inSharedState.NameType] = new Weapon(inSharedState);
		}
		return m_weapon[inSharedState.NameType];
	}

	// Получить указатель на элемент контейнера:
	// по имени
	Weapon* getWeapon(std::string inNameType)
	{
		if (m_weapon.find(inNameType) != m_weapon.end())
		{
			return m_weapon[inNameType];
		}
		return nullptr;
	}
	// по характеристику
	Weapon* getWeapon(SharedState inSharedState)
	{
		return getWeapon(inSharedState.NameType);
	}
	// по указателю на характеристику
	Weapon* getWeapon(SharedState* inSharedState)
	{
		return getWeapon(inSharedState->NameType);
	}

	// Перегрузка оператора для вывода информации
	friend std::ostream& operator<<(std::ostream& cout, const WeaponFactory& wf)
	{
		for (auto it = wf.m_weapon.begin();
			it != wf.m_weapon.end(); ++it)
			cout << "[" << it->first << ", " << *(it->second) << "]" << '\n';
		return cout << std::endl;
	}
};

int main6()
{
	// "Фабрика" Оружий -- База данных на характеристики оружия
	WeaponFactory wFactory;

	// Инициализация характеристики оружия
	SharedState* sState1 = new SharedState("Pistol", 23, 3.0);
	SharedState* sState2 = new SharedState("Pistol", 12, 1.7);
	SharedState* sState3 = new SharedState("MiniGun", 60, 15.0);
	SharedState* sState4 = new SharedState("Stick", 1, 0.1);

	// Инициализация оружия и добавление из в "Фабрику"
	Weapon* W1 = wFactory.addWeapon(*sState1);
	Weapon* W2 = wFactory.addWeapon(*sState2);
	wFactory.addWeapon(*sState3);
	wFactory.addWeapon(*sState4);

	std::cout << "Вывод w1 и w2:\n"
		<< *W1 << '\n'
		<< *W2 << '\n'
		<< std::endl;

	std::cout << "Вывод из wFactory по Имени:\n"
		<< *wFactory.getWeapon("Pistol") << '\n'
		<< *wFactory.getWeapon(sState3) << '\n'
		<< std::endl;

	std::cout << "Вывод всех элементов wFactory:\n"
		<< wFactory << std::endl;

	return 0;
}

/*   Вывод:
* "Легковес" экономит память, разделяя общие данные объектов между собой,
* вместо хранения одинаковых данных в каждом объекте,
* что позволяет вместить бóльшее количество
* объектов в отведённую оперативную память
*/