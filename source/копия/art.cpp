#include "git.h"
#include <iostream>
#include <cstring>

void copyStr(char* a, char* b) {
    for (; (*a = *b); a++, b++);
}
void copyStr(char* a, const char* b) {
    for (; (*a = *b); a++, b++);
}

void addStr(char* a, const char* b) {
    while (*a) a++;
    copyStr(a, b);
}

void gitPush(const char* text) {
    system("git add .>nul");
    char gitText[] = "git commit -m \"";
    int size = strlen(gitText) + strlen(text) + 2;
    char* temp = new char[size];
    strcpy_s(temp, size, gitText);
    addStr(temp, text);
    addStr(temp, "\"");
    std::cout << temp;
    system(temp);
    system("git push");
    system("git status");
    delete[] temp;
}
