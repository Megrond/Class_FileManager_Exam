#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
#include "FileManager.h"
#include "Menu.h"

using namespace std;
namespace fs = filesystem;

int main()
{
	setlocale(LC_ALL, "RU");

    FileManager fileManager;
    Menu menu(fileManager);
    menu.run();

}

//��� �������� ����������������� ��������� ���������� ����������� ���������� �� �++ 17. ������ -> �������� -> �/�++ -> �������� �����. ����������� ������� ��������
// ��������! �� ������� ������� ���� ���� �. ��� ��������� ���� ����� ������ ���������� ����!
//��� ����������� � ����������� ��������� ������������� ����