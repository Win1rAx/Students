///
//  main.cpp
//  students
//
//  Created by Алексей Маслов on 27.09.2024.
//

#include <iostream>
#include "function.hpp"
#include <fstream>
#include <string>
using namespace std;
class Password
{
public:

    void Entrance()
    {
        string login = "logins.txt";
        string password = "passwords.txt";

        ifstream logins;
        ifstream passwords;

        logins.open(login);
        passwords.open(password);

        if (!logins.is_open() || !passwords.is_open())
        {
            cout << "Ошибка!" << endl;
        }
        else
        {
            string login_correct;
            string pass_correct;
            cout << "Введите свой логин: "; cin >> login_correct;
            cout << endl;
            cout << "Введите свой пароль: "; cin >> pass_correct;
            
            
            string log_cheker;
            string pass_cheker;
            
            bool login_found = false;
            bool password_found = false;
            
        /*
            while (!logins.eof()) //Пока не закончатся символы, идем по циклу.
            {
                std::getline(logins, log_cheker);
                // log >> log_cheker; //Передаем данные с файла в переменную.
            }
            while (!passwords.eof()) //Пока не закончатся символы, идем по циклу.
            {
                std::getline(passwords, pass_cheker);
                // pass >> pass_cheker; //Передаем данные с файла в переменную.
            }
        
            if (login_correct != log_cheker && pass_correct != pass_cheker)
            {
                std::cout << "Пароль или логин введен не правильно!" << std::endl;
            }
            else
            {
                std::cout << "Данные введены верно!" << std::endl;
            }
            */
            
            while (getline(logins, log_cheker)) {
                
                //std::cout << log_cheker << std::endl;
                
                if (login_correct == log_cheker) {
                    login_found = true;
                }
            }
            while (getline(passwords, pass_cheker)) {
                if(pass_correct == pass_cheker){
                    password_found = true;
                }
                if(password_found == login_found){
                    break;
                }
            
            }
            if(!login_found){
                std::cout << "login uncorrect" << std::endl;
                //std::cout << log_cheker << " " << login_correct;
            }else if(!password_found){
                std::cout << "password uncorrect" << std::endl;
            }else{
                std::cout << "Welcome " << login_correct << std::endl;
            }
            logins.close();
            passwords.close();

            
        }
    }
    void Sign_up()
    {
        string login = "logins.txt";
        string password = "passwords.txt";

        fstream log;
        fstream pass;

        log.open(login, fstream::in | fstream::out | fstream::app);
        pass.open(password, fstream::in | fstream::out | fstream::app);

        if (!log.is_open() && !pass.is_open())
        {
            cout << "Ошибка!" << endl;
        }
        else
        {
            string log_cheker;
            string pass_cheker;
            cout << "Введите свой логин: "; cin >> log_cheker;
            cout << endl;
            cout << "Введите свой пароль: "; cin >> pass_cheker;

            log << '\n' << log_cheker;
            pass << '\n' << pass_cheker;

            cout << "Регистрация прошла успешно!" << endl;

            

        }
        log.close();
        pass.close();
    }

};
class menu
{
public:

    int RunMenu()
    {
        int punkt;
        cout << "Добро пожаловать!" << endl;
        cout << "1.Вход" << endl;
        cout << "2.Регистрация" << endl;
        cin >> punkt;

        if (punkt != 1 && punkt != 2)
        {
            cout << "Выбран неверный пункт меню!" << endl;
        }
        if (punkt == 1)
        {
            
            Password pass;
            pass.Entrance();
        }
        if (punkt == 2)
        {
            
            Password pass;
            pass.Sign_up();
        }
        return 0;
    }
};
int main()
{
    
    menu Menu;

    Menu.RunMenu();

    return 0;
}
