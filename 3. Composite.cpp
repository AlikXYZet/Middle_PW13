/* ---   Компоновщик   --- */
#include "0. Testing.h"

#include <list>

// Предварительная инициализация
class Composite;

// Реализация структуры
class Component
{
protected:
	// Какая-то информация (Название)
	std::string NameData;

	// Конструктор
	Component(std::string inName) : NameData(inName) {}

	friend class Composite;

public:
	/*   Виртуальные функции:   */
	// Какая-либо операция (Вывод цепочки наследования)
	virtual void Operation()
	{
		Operation("");
	};
	virtual void Operation(std::string inData) = 0;

	// Добавление элемента
	virtual void Add(Component* inComp) = 0;

	// Удаление элемента
	virtual void Remove(Component* inComp) = 0;

	// Вернуть потомка по номеру (начиная с 0, класс Сomposite)
	virtual Component* GetChild(int inChild) = 0;
};

// Класс Composite - может иметь потомков
class Composite : public Component
{
private:
	// Список потомков
	std::list<Component*> L;

public:
	// Конструктор
	Composite(std::string inName) : Component(inName) { }

	void Operation() override
	{
		Component::Operation();
	};
	// Какая-либо операция (Вывод цепочки наследования)
	void Operation(std::string inData) override
	{
		for (
			std::list<Component*>::iterator it = L.begin();	// Объявить итератор на список L
			it != L.end();
			it++)
		{
			std::string Data;
			if (!inData.empty())
				Data = inData;
			Data = Data + NameData + " -> ";
			(*it)->Operation(Data);
		}
	}

	// Добавить компонент в список
	void Add(Component* inComp) override
	{
		L.push_back(inComp);
	}

	// Удаление компонента
	void Remove(Component* inComp)
	{
		for (
			std::list<Component*>::iterator it = L.begin();	// Объявить итератор на список L
			it != L.end(); 
			it++)
		{
			// Если есть элемент, то удалить
			if (*it == inComp)
			{
				L.erase(it);
				break;
			}
		}
	}

	// Вернуть потомка по номеру (начиная с 0)
	Component* GetChild(int iChild) override
	{
		std::list<Component*>::iterator it = L.begin();	// Объявить итератор на список L
		for (
			int i = 0;
			(i < iChild) && (it != L.end());
			i++)
		{
			it++;
		}
		return *it;
	}
};

// Класс Лист - нету потомков
class Leaf : public Component
{
public:
	// Конструктор
	Leaf(std::string inName) : Component(inName) { }

	void Operation() override
	{
		Component::Operation();
	};

	void Operation(std::string inData) override
	{
		std::cout << inData << NameData << std::endl;
	}

private:
	// Скрыть "лишние" для данного класса функции
	void Add(Component* inComp) override { };
	void Remove(Component* inComp) override { };
	Component* GetChild(int inChild) override
	{
		return nullptr;
	}
};

int main3()
{
	// Инициализация
	Composite* O = new Composite("O");

	Leaf* A = new Leaf("A");
	Composite* B = new Composite("B");
	Leaf* C = new Leaf("C");

	Leaf* BA = new Leaf("BA");
	Leaf* BB = new Leaf("BB");

	// Составление "древа"
	O->Add(A);
	O->Add(B);
	O->Add(C);

	B->Add(BA);
	B->Add(BB);
	B->Add(C);

	std::cout << "\n====== Вывод основной \"Ветви\" O\n";
	O->Operation();

	std::cout << "\n====== Вывод второстепенной \"Ветви\" B\n";
	B->Operation();

	std::cout << "\n====== Вывод TEST = O->GetChild(1)\n";
	Component* TEST = O->GetChild(0);
	TEST->Operation();


	// Удаление компонентов
	B->Remove(C);
	O->Remove(B);

	std::cout << "\n====== Вывод основной \"Ветви\" O после удалений\n";
	O->Operation();

	std::cout << "\n====== Вывод второстепенной \"Ветви\" B после удалений\n";
	B->Operation();

	return 0;
}