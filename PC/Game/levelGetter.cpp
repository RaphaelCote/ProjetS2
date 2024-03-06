#include <windows.h>
#include <string>

#include "levelGetter.h"

LevelGetter::LevelGetter()
{
    const char *folderPath = ".\\levels\\*.json";
    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA(folderPath, &findData);
    if (hFind != INVALID_HANDLE_VALUE)
    {
        cout << "Valid Handle" << endl;
        do
        {
            string fullPath;
            fullPath = ".\\levels\\";
            fullPath += findData.cFileName;
            // cout << "filetype : " << findData.dwFileAttributes << " | fileName : " << findData.cFileName << " | filePath : " << fullPath << endl;
            levels.add(fullPath);
            // cout << "File " << nbLevel << ":" << levels[nbLevel] << endl;
            nbLevel++;
        } while (FindNextFileA(hFind, &findData) != 0);
        FindClose(hFind);
    }
    else
    {
        cout << "Error finding files." << endl;
    }
}