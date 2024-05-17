/* ---   �������� �������� ����� �������   --- */
#include "0. Testing.h"

//����� �� ���������
int DefaultSelection = 1;

bool MainSelection(int sel)
{
	switch (sel)
	{
	case 1:
		main1();
		break;
	case 2:
		main2();
		break;
	case 3:
		main3();
		break;
	case 4:
		main4();
		break;
	case 5:
		main5();
		break;
	case 6:
		main6();
		break;
	default:
		std::cout << "������������ ����. ����� �� ��������� : "
			<< DefaultSelection
			<< '\n'
			<< std::endl;;
		return true;
		break;
	}

	return false;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "����������� �������:\n"
		<< "1. �����\n"
		<< "2. �����������\n"
		<< "3. �����������\n"
		<< "4. �������\n"
		<< "5. ����\n"
		<< "6. ��������\n"
		<< '\n';

	std::cout << "�������� ����������� ������: ";
	int Selection;
	std::cin >> Selection;
	std::cout << std::endl;

	DefaultSelection = ((DefaultSelection - 1) % 6) + 1;

	if (MainSelection(Selection))
		MainSelection(DefaultSelection);

	return 0;
}