#include <string>

#include "levelGetter.h"

levelGetter::levelGetter()
{
     const char * folderPath = "path/to/your/folder";
    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA(folderPath, &findData);
    string fullPath;
    if (hFind != INVALID_HANDLE_VALUE)
    {
        do{
            if (findData.dwFileAttributes & FILE_ATTRIBUTE_NORMAL)
                fullPath = folderPath;
                fullPath = fullPath + "\\";
                fullPath = fullPath + findData.cFileName;
                levels[nbLevel] = fullPath;
                nbLevel ++;
        } while (FindNextFileA(hFind, &findData) != 0);
        FindClose(hFind);
    }
    else 
    {
        cout << "Error finding files." << endl;
    }
}

