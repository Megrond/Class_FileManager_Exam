#pragma once
#include "FileManager.h"

class Menu
{
private:
    FileManager& fileManager;
    string currentPath;

public:
    Menu(FileManager& fm) : fileManager(fm), currentPath("/") {}
    void display();
    void run();
};
