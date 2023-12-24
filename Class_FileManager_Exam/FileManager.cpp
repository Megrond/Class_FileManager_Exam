#include "FileManager.h"

void FileManager::showContent(const string& path)
{
	for (const auto& entry : fs::directory_iterator(path))
	{
		cout << entry.path().filename() << endl;
	}
}

bool FileManager::createFolder(const string& path, const string& folderName)
{
	if (!fs::exists(path))
	{
		cout << "Недопустимый путь." << endl;
		return false;
	}

	fs::path folderPath = fs::path(path) / folderName;

	try
	{
		create_directory(folderPath);
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Не удалось создать папку: " << err.what() << endl;
		return false;
	}

	cout << "Папка создана успешно." << endl;
	return true;
}

bool FileManager::createFile(const string& path, const string& fileName)
{
	if (!fs::exists(path))
	{
		cout << "Недопустимый путь." << endl;
		return false;
	}

	fs::path filePath = fs::path(path) / fileName;

	ofstream file(filePath);
	if (!file)
	{
		cout << "Не удалось создать файл." << endl;
		return false;
	}

	file.close();
	cout << "Файл успешно создан." << endl;
	return true;
}

bool FileManager::deleteFolder(const string& path)
{
	if (!fs::exists(path))
	{
		cout << "Недопустимый путь." << endl;
		return false;
	}

	try
	{
		fs::remove_all(path);
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Не удалось удалить папку: " << err.what() << endl;
		return false;
	}

	cout << "Папка успешно удалена." << endl;
	return true;
}

bool FileManager::deleteFile(const string& path)
{
	if (!fs::exists(path))
	{
		cout << "Недопустимый путь." << endl;
		return false;
	}

	try
	{
		fs::remove(path);
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Не удалось удалить файл: " << err.what() << endl;
		return false;
	}

	cout << "Файл успешно удален." << endl;
	return true;
}

bool FileManager::renameFolder(const string& path, const string& newFolderName)
{
	if (!fs::exists(path))
	{
		cout << "Недопустимый путь." << endl;
		return false;
	}

	fs::path newPath = fs::path(path).parent_path() / newFolderName;

	try
	{
		fs::rename(path, newPath);
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Не удалось переименовать папку: " << err.what() << endl;
		return false;
	}

	cout << "Папка успешно переименована." << endl;
	return true;
}

bool FileManager::renameFile(const string& path, const string& newFileName)
{
	if (!fs::exists(path))
	{
		cout << "Недопустимый путь." << endl;
		return false;
	}

	fs::path newPath = fs::path(path).parent_path() / newFileName;

	try
	{
		fs::rename(path, newPath);
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Не удалось переименовать файл: " << err.what() << endl;
		return false;
	}

	cout << "Файл успешно переименован." << endl;
	return true;
}

bool FileManager::copyFolder(const string& source, const string& destination)
{
	if (!fs::exists(source))
	{
		cout << "Исходная папка не существует." << endl;
		return false;
	}

	try
	{
		fs::copy(source, destination, fs::copy_options::recursive);
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Не удалось скопировать папку: " << err.what() << endl;
		return false;
	}

	cout << "Папка успешно скопирована." << endl;
	return true;
}

bool FileManager::copyFile(const string& source, const string& destination)
{
	if (!fs::exists(source))
	{
		cout << "Исходный файл не существует." << endl;
		return false;
	}

	try
	{
		fs::copy(source, destination);
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Не удалось скопировать файл: " << err.what() << endl;
		return false;
	}

	cout << "Файл успешно скопирован." << endl;
	return true;
}

bool FileManager::moveFolder(const string& source, const string& destination)
{
	if (!fs::exists(source))
	{
		cout << "Исходная папка не существует." << endl;
		return false;
	}

	try
	{
		fs::rename(source, destination);
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Не удалось переместить папку: " << err.what() << endl;
		return false;
	}

	cout << "Папка успешно перемещена." << endl;
	return true;
}

bool FileManager::moveFile(const string& source, const string& destination)
{
	if (!fs::exists(source))
	{
		cout << "Исходный файл не существует." << endl;
		return false;
	}

	try
	{
		fs::rename(source, destination);
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Не удалось переместить файл: " << err.what() << endl;
		return false;
	}

	cout << "Файл успешно перемещен." << endl;
	return true;
}

uintmax_t FileManager::calculateSize(const string& path)
{
	if (!fs::exists(path))
	{
		cout << "Недопустимый путь." << endl;
		return 0;
	}

	uintmax_t size = 0;

	try
	{
		if (fs::is_regular_file(path))
		{
			size = fs::file_size(path);
		}
		else if (fs::is_directory(path))
		{
			for (const auto& entry : fs::recursive_directory_iterator(path))
			{
				if (entry.is_regular_file())
				{
					size += entry.file_size();
				}
			}
		}
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Не удалось рассчитать размер: " << err.what() << endl;
		return 0;
	}

	cout << "Размер: " << size << " байт" << endl;
}

vector<string> FileManager::searchByMask(const string& path, const string& mask)
{
	vector<string> results;

	if (!fs::exists(path))
	{
		cout << "Недопустимый путь." << endl;
		return results;
	}

	try
	{
		for (const auto& entry : fs::recursive_directory_iterator(path))
		{
			if (entry.is_regular_file() && entry.path().filename().string().find(mask) != string::npos)
			{
				results.push_back(entry.path().string());
			}
		}
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Поиск не удался: " << err.what() << endl;
		return results;
	}

	return results;
}
