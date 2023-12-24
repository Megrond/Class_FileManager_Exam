﻿#include "Menu.h"


void Menu::display()
{
	cout << endl;
	cout << "Текущий путь: " << currentPath << endl; 
	cout << "1. Показать диски" << endl;
	cout << "2. Показать содержимое" << endl;
	cout << "3. Создать папку" << endl;
	cout << "4. Создать файл" << endl;
	cout << "5. Удалить папку" << endl;
	cout << "6. Удалить файл" << endl;
	cout << "7. Переименовать папку" << endl;
	cout << "8. Переименовать файл" << endl;
	cout << "9. Скопировать папку" << endl;
	cout << "10. Скопировать файл" << endl;
	cout << "11. Переместить папку" << endl;
	cout << "12. Переместить файл" << endl;
	cout << "13. Рассчитать размер" << endl;
	cout << "14. Поиск по маске" << endl;
	cout << "0. Выход" << endl;
	cout << endl;
}

void Menu::run()
{
	while (true)
	{
		display();
		int choice;
		cout << "Выберите действие: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			fileManager.showDrives();
			break;
		case 2:
			fileManager.showContent(currentPath);
			break;
		case 3:
		{
			string folderName;
			cout << "Введите имя папки: ";
			cin >> folderName;
			fileManager.createFolder(currentPath, folderName);
			break;
		}
		case 4:
		{
			string fileName;
			cout << "Введите имя файла: ";
			cin >> fileName;
			fileManager.createFile(currentPath, fileName);
			break;
		}
		case 5:
		{
			string folderName;
			cout << "Введите имя папки: ";
			cin >> folderName;
			fileManager.deleteFolder(currentPath + folderName);
			break;
		}
		case 6:
		{
			string fileName;
			cout << "Введите имя файла: ";
			cin >> fileName;
			fileManager.deleteFile(currentPath + fileName);
			break;
		}
		case 7:
		{
			string folderName, newFolderName;
			cout << "Введите имя папки: ";
			cin >> folderName;
			cout << "Введите новое имя папки: ";
			cin >> newFolderName;
			fileManager.renameFolder(currentPath + folderName, newFolderName);
			break;
		}
		case 8:
		{
			string fileName, newFileName;
			cout << "Введите имя файла: ";
			cin >> fileName;
			cout << "Введите новое имя файла: ";
			cin >> newFileName;
			fileManager.renameFile(currentPath + fileName, newFileName);
			break;
		}
		case 9:
		{
			string source, destination;
			cout << "Войдите в исходную папку: ";
			cin >> source;
			cout << "Введите папку назначения: ";
			cin >> destination;
			fileManager.copyFolder(currentPath + source, currentPath + destination);
			break;
		}
		case 10:
		{
			string source, destination;
			cout << "Введите исходный файл: ";
			cin >> source;
			cout << "Введите конечный файл: ";
			cin >> destination;
			fileManager.copyFile(currentPath + source, currentPath + destination);
			break;
		}
		case 11:
		{
			string source, destination;
			cout << "Войдите в исходную папку: ";
			cin >> source;
			cout << "Введите папку назначения: ";
			cin >> destination;
			fileManager.moveFolder(currentPath + source, currentPath + destination);
			break;
		}
		case 12:
		{
			string source, destination;
			cout << "Введите исходный файл: ";
			cin >> source;
			cout << "Введите конечный файл: ";
			cin >> destination;
			fileManager.moveFile(currentPath + source, currentPath + destination);
			break;
		}
		case 13:
		{
			string path;
			cout << "Введите путь к файлу или папке: ";
			cin >> path;
			fileManager.calculateSize(currentPath + path);
			break;
		}
		case 14:
		{
			string mask;
			cout << "Введите маску: ";
			cin >> mask;
			vector<string> results = fileManager.searchByMask(currentPath, mask);
			cout << "Результаты поиска:" << endl;
			for (const auto& result : results)
			{
				cout << result << endl;
			}
			break;
		}
		case 0:
			return;
		default:
			cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
		}

		cout << endl;
	}
}
