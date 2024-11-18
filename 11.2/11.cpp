#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

size_t CountWords(const string& s) {
    size_t wordCount = 0;
    size_t start = 0;

    while ((start = s.find_first_not_of(" ", start)) != string::npos) {
        start = s.find_first_of(" ", start);
        wordCount++;
    }

    return wordCount;
}

string ReadFileContent(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        throw runtime_error("Не вдалося відкрити файл: " + filePath);
    }

    string content, line;
    while (getline(file, line)) {
        content += line + '\n';
    }

    file.close();
    return content;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string filePath = "D:\\vs project\\11.2\\3.txt";
    cout << "Шлях до файлу: " << filePath << endl;
    try {
        string fileContent = ReadFileContent(filePath);
        size_t wordCount = CountWords(fileContent);
        cout << "Кількість слів у файлі: " << wordCount << endl;
    }
    catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
    }

    return 0;
}