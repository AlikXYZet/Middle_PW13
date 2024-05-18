/* ---   Заместитель   --- */
#include "0. Testing.h"

/*   Общий интерфейс информации для "Оригинала" и "Заместителя"   */
// Интерфейс информации
class IData
{
protected:

	// Данные:
	// Необходимые
	std::string PromotionName;
	int Cost;
	int Discount;

	virtual std::string GetName() = 0;
	virtual int GetCost() = 0;
	virtual int GetDiscount() = 0;
};

/*   "Оригинал"   */
// Магазин
class Shop : public IData
{
private:
	// Ненужные дополнительные данные
	int DateFrom = 10;
	int DateTo = 20;

public:

	Shop()
	{
		PromotionName = "Акция 1";
		Cost = 10;
		Discount = 6;
	}

	// Новая акция
	void NewPromotion(
		std::string inName,
		int inCost,
		int inDiscount,
		int inDateFrom,
		int inDateTo)
	{
		PromotionName = inName;
		Cost = inCost;
		Discount = inDiscount;
		DateFrom = inDateFrom;
		DateTo = inDateTo;
	}

	//Получение данных:
	// Название
	std::string GetName() override
	{
		return PromotionName;
	}
	// Стоимость
	int GetCost() override
	{
		return Cost;
	}
	// Скитка
	int GetDiscount() override
	{
		return Discount;
	}
	// Дата с
	int GetDateFrom()
	{
		return DateFrom;
	}
	// Дата по
	int GetDateTo()
	{
		return DateTo;
	}
};

/*   "Заместитель"   */
// Лист заметок
class SheetNotes : public IData
{
	Shop* shop;

public:
	SheetNotes(Shop& inShop)
		: shop(&inShop)
	{}

	void UpdateData()
	{
		PromotionName = shop->GetName();
		Cost = shop->GetCost();
		Discount = shop->GetDiscount();
	}

	//Получение данных:
	// Название
	std::string GetName() override
	{
		if (PromotionName.empty())
			UpdateData();
		return PromotionName;
	}
	// Стоимость
	int GetCost() override
	{
		if (!Cost)
			UpdateData();
		return Cost;
	}
	// Скитка
	int GetDiscount() override
	{
		if (!Discount)
			UpdateData();
		return Discount;
	}
};


int main2()
{
	Shop Shop1;
	SheetNotes Notebook(Shop1);

	std::cout << "--- Данные магазина Shop1: " << '\n'
		<< "Наименование акции: " << Shop1.GetName() << '\n'
		<< "Стоимость: " << Shop1.GetCost() << '\n'
		<< "Скитка: " << Shop1.GetDiscount() << '\n'
		<< "Дата с: " << Shop1.GetDateFrom() << '\n'
		<< "Дата до: " << Shop1.GetDateTo() << '\n'
		<< std::endl;

	std::cout << "--- Данные из заметки: " << '\n'
		<< "Наименование акции: " << Notebook.GetName() << '\n'
		<< "Стоимость: " << Notebook.GetCost() << '\n'
		<< "Скитка: " << Notebook.GetDiscount() << '\n'
		<< std::endl;

	Shop1.NewPromotion("Акция 2", 15, 5, 4, 25);

	std::cout << "--- Неактуальные данные из заметки: " << '\n'
		<< "Наименование акции: " << Notebook.GetName() << '\n'
		<< "Стоимость: " << Notebook.GetCost() << '\n'
		<< "Скитка: " << Notebook.GetDiscount() << '\n'
		<< std::endl;

	Notebook.UpdateData();

	std::cout << "--- Обновлённые данные из заметки: " << '\n'
		<< "Наименование акции: " << Notebook.GetName() << '\n'
		<< "Стоимость: " << Notebook.GetCost() << '\n'
		<< "Скитка: " << Notebook.GetDiscount() << '\n'
		<< std::endl;

	return 0;
}

/*   Вывод:
* "Заместитель" используется для временного хранения информации из "Оригинала"
* с возможностью обновить эти данные, что даёт следующие особенности:
* "Оригинала" изолирован от прямого воздействия "Клиента";
* Можно уменьшить количество обращений к "Оригиналу";
* Можно дублировать не все данные "Оригинала", а только те, что требуются "Клиенту".
*/