#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string line;

    // Перевірка існування файлу
    ifstream checkFile("text.txt");
    if (checkFile.is_open()) {
        cout << "Файл text.txt вже існує." << endl;
        checkFile.close();
    }
    else {
        cout << "Файл text.txt не існує. Буде створено новий файл." << endl;
    }

    // Запис у файл
    ofstream outFile("text.txt");

    if (!outFile.is_open()) {
        cout << "Помилка відкриття файлу для запису!" << endl;
        return 1;
    }

    cout << "Введіть 5 рядків тексту:" << endl;

    for (int i = 0; i < 5; i++) {
        getline(cin, line);
        outFile << line << endl;
    }

    outFile.close();
    cout << "\nДані успішно записані у файл.\n" << endl;

    // Читання з файлу
    ifstream inFile("text.txt");

    if (!inFile.is_open()) {
        cout << "Помилка відкриття файлу для читання!" << endl;
        return 1;
    }

    cout << "Вміст файлу:" << endl;

    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();

    return 0;
}