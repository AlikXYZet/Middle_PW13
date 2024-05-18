/* ---   �����������   --- */
#include "0. Testing.h"

/*   ����� ��������� ���������� ��� "���������" � "�����������"   */
// ��������� ����������
class IData
{
protected:

	// ������:
	// �����������
	std::string PromotionName;
	int Cost;
	int Discount;

	virtual std::string GetName() = 0;
	virtual int GetCost() = 0;
	virtual int GetDiscount() = 0;
};

/*   "��������"   */
// �������
class Shop : public IData
{
private:
	// �������� �������������� ������
	int DateFrom = 10;
	int DateTo = 20;

public:

	Shop()
	{
		PromotionName = "����� 1";
		Cost = 10;
		Discount = 6;
	}

	// ����� �����
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

	//��������� ������:
	// ��������
	std::string GetName() override
	{
		return PromotionName;
	}
	// ���������
	int GetCost() override
	{
		return Cost;
	}
	// ������
	int GetDiscount() override
	{
		return Discount;
	}
	// ���� �
	int GetDateFrom()
	{
		return DateFrom;
	}
	// ���� ��
	int GetDateTo()
	{
		return DateTo;
	}
};

/*   "�����������"   */
// ���� �������
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

	//��������� ������:
	// ��������
	std::string GetName() override
	{
		if (PromotionName.empty())
			UpdateData();
		return PromotionName;
	}
	// ���������
	int GetCost() override
	{
		if (!Cost)
			UpdateData();
		return Cost;
	}
	// ������
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

	std::cout << "--- ������ �������� Shop1: " << '\n'
		<< "������������ �����: " << Shop1.GetName() << '\n'
		<< "���������: " << Shop1.GetCost() << '\n'
		<< "������: " << Shop1.GetDiscount() << '\n'
		<< "���� �: " << Shop1.GetDateFrom() << '\n'
		<< "���� ��: " << Shop1.GetDateTo() << '\n'
		<< std::endl;

	std::cout << "--- ������ �� �������: " << '\n'
		<< "������������ �����: " << Notebook.GetName() << '\n'
		<< "���������: " << Notebook.GetCost() << '\n'
		<< "������: " << Notebook.GetDiscount() << '\n'
		<< std::endl;

	Shop1.NewPromotion("����� 2", 15, 5, 4, 25);

	std::cout << "--- ������������ ������ �� �������: " << '\n'
		<< "������������ �����: " << Notebook.GetName() << '\n'
		<< "���������: " << Notebook.GetCost() << '\n'
		<< "������: " << Notebook.GetDiscount() << '\n'
		<< std::endl;

	Notebook.UpdateData();

	std::cout << "--- ���������� ������ �� �������: " << '\n'
		<< "������������ �����: " << Notebook.GetName() << '\n'
		<< "���������: " << Notebook.GetCost() << '\n'
		<< "������: " << Notebook.GetDiscount() << '\n'
		<< std::endl;

	return 0;
}

/*   �����:
* "�����������" ������������ ��� ���������� �������� ���������� �� "���������"
* � ������������ �������� ��� ������, ��� ��� ��������� �����������:
* "���������" ���������� �� ������� ����������� "�������";
* ����� ��������� ���������� ��������� � "���������";
* ����� ����������� �� ��� ������ "���������", � ������ ��, ��� ��������� "�������".
*/