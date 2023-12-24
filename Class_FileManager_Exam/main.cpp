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

//Для проверки работоспособности программы необходимо переключить компилятор на С++ 17. Проект -> Свойства -> С/С++ -> Стандарт языка. Переключить двойным нажатием
// Внимание! По дефолту текущий путь диск С. Для изменения пути нужно ввести абсолютный путь!
//При копировании и перемещении указываем относительный путь