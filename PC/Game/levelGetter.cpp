#include <windows.h>
// #include <tchar.h>
// #include <stdio.h>
// #include <strsafe.h>
#include <string>

#include "levelGetter.h"

// #pragma comment(lib, "User32.lib")

LevelGetter::LevelGetter()
{
    //     WIN32_FIND_DATA ffd;
    //    LARGE_INTEGER filesize;
    //    TCHAR szDir[MAX_PATH];
    //    size_t length_of_arg;
    //    HANDLE hFind = INVALID_HANDLE_VALUE;

    //    // Prepare string for use with FindFile functions.  First, copy the
    //    // string to a buffer, then append '\*' to the directory name.

    //    StringCchCopy(szDir, MAX_PATH, TEXT("levels"));
    //    StringCchCat(szDir, MAX_PATH, TEXT("\\*"));

    //    // Find the first file in the directory.

    //    hFind = FindFirstFile(szDir, &ffd);

    //     if (INVALID_HANDLE_VALUE == hFind)
    //    {
    //       cout << INVALID_HANDLE_VALUE << endl;
    //    }

    //    // List all the files in the directory with some info about them.

    //    do
    //    {
    //       if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
    //       {
    //          _tprintf(TEXT("  %s   <DIR>\n"), ffd.cFileName);
    //       }
    //       else
    //       {
    //          filesize.LowPart = ffd.nFileSizeLow;
    //          filesize.HighPart = ffd.nFileSizeHigh;
    //          _tprintf(TEXT("  %s   %ld bytes\n"), ffd.cFileName, filesize.QuadPart);
    //       }
    //    }
    //    while (FindNextFile(hFind, &ffd) != 0);

    //    FindClose(hFind);

    const char *folderPath = ".\\levels\\*.json";
    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA(folderPath, &findData);
    string fullPath;
    if (hFind != INVALID_HANDLE_VALUE)
    {
        cout << "Valid Handle" << endl;
        do
        {
            fullPath = ".\\levels\\";
            fullPath += findData.cFileName;
            cout << "filetype : " << findData.dwFileAttributes << " | fileName : " << findData.cFileName << " | filePath : " << fullPath << endl;
            levels[nbLevel] = fullPath;
            cout << "File " << nbLevel + 1 << ":" << levels[nbLevel] << endl;
            nbLevel++;
        } while (FindNextFileA(hFind, &findData) != 0);
        FindClose(hFind);
    }
    else
    {
        cout << "Error finding files." << endl;
    }
    cout << GetLastError() << endl;
}