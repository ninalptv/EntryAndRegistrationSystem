#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool IsLogIn()
{
    string username, password, un, pw;
    cout << "Введите имя пользователя: "; cin >> username;
    cout << "Введите пароль: "; cin >> password;
    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);
    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    int choise;
    cout << "1:Регистрация\n2:Логин\nВаш выбор: "; cin >> choise;
    switch (choise)
    {
    case 1: 
    {
        string username, password;
        cout << "Создайте имя пользователя: "; cin >> username;
        cout << "Создайте пароль: "; cin >> password;
        ofstream file;
        file.open(username + ".txt");
        file << username << endl << password;
        file.close();
        main();
        break;
    }
    case 2:
    {
        bool status = IsLogIn();
        if (!status)
        {
            cout << "Не получилось войти!"<<endl;
            system("PAUSE");
            return 0;
        }
        else
        {
            cout << "Успешный вход!" << endl;
            system("PAUSE");
            return 1;  
        }
        break;
    }
    }
}

