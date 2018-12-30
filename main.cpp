#include <iostream>
#include <ctime>
#include <random>

/*ЗАМЕТКИ

1. Добавить ограниченное кол-во угадываний.
2. Сделать разные реплики на больше, меньше, равно.
3. Сделать возможность сыграть ещё, не выходя из программы
4. Добавить тайтлскрин и возможно, небольшие задержки между некоторыми стейтментами

*/

//проверяем число на больше, меньше, равно...
int check(int tryNumber, int guessNumber){
    using namespace std;

    //переменная с количеством попыток, угадать число.
    static int countOfTry = 0;

    //если число меньше загаданного...
    if (tryNumber < guessNumber){
        system("cls");
        //добавляем значение в переменную попыток
        ++countOfTry;
        cout << "Загаданное число больше." << endl;
        return 1;
    }
    //если число больше загаданного...
    else if(tryNumber > guessNumber){
        system("cls");
        //добавляем значение в переменную попыток
        ++countOfTry;
        cout << "Загаданное число меньше." << endl;
        return 1;
    }
    //если число равно загаданному...
    else if(tryNumber == guessNumber){
        system("cls");
        //добавляем значение в переменную попыток
        ++countOfTry;
        cout << "Поздравляю! Вы угадали число с " << countOfTry << " попытки!" << endl;
        return 0;
    }
    //если ввели что-то совсем другое... (за попытку угадать не считается)
    else{
        system("cls");
        cout << "Что-то неверно..." << endl;
        return 1;
    }
}

void game(int guessNumber, int userNumber){
    using namespace std;
    //прочим пользователя ввести число
    cout << "Введите число от 1 до " << userNumber << ":" << endl;
    int tryNumber; //переменная для попытки угадывания загаданного числа
    while(true){
        cin >> tryNumber;
            //далее алгорим на правильность ввода.
            //здесь, если пользователь ввёл нечисло
            if (cin.fail()){
                cin.clear();
                cin.ignore(32767,'\n');
                system("cls");
                cout << "Введите правильное значение от 1 до " << userNumber << ":" << endl;
            }
            //здесь, если пользователь ввёл числа, гораздо больше-меньше ограничений
            else if(tryNumber > userNumber || tryNumber < 1){
                system("cls");
                cout << "Введите правильное значение от 1 до " << userNumber << ":" << endl;
            }
            else {
                break;
            }
    }
    //проверяем число, совпадает ли оно с загаданным или насколько оно близко к нему?
    //результат сохраняем в переменную. 1 - не совпало, 0 - совпало.
    int result = check(tryNumber, guessNumber);

    //если мы не угадали, то пробуем ещё раз.
    if(result == 1){
        game(guessNumber, userNumber);
    }

}

//создаём угадываемое число
int createGuessNumber (int userNumberGuess){
    using namespace std;

    //объявляем Вихрь Мерсенна
    mt19937 mersenne(static_cast<unsigned int>(time(0)));
    //используем Вихрь Мерсенна для создания угадываемого числа от 1 до userGuessNumber
    int guessNumber = 1 + mersenne() % userNumberGuess;
    return guessNumber;
}

//функция меню, где мы просим число у пользователя
int menu(){
    using namespace std;
    //выводим меню
    cout << "MoreOrLess" << endl;
    cout << "Введите число до которого будем угадывать:" << endl;

    //с помощью цикла требуем у пользователя верного ввода
    while (true){

    //создаём переменную и просим польщователя ввести число
    //это число будет использоваться для максимального диапозона угадывания
    long long int number;
    cin >> number;
        //алгоритм для проверки правильности ввода
        if (cin.fail()){
                cin.clear();
                cin.ignore(32767,'\n');
                system("cls");
                cout << "Введите правильное значение:" << endl;
            }
        //если всё верно, то возвращаем число
        else {
            system("cls");
            return number;
        }
    }
}

int main(){
    using namespace std;
    setlocale(0, "");

    //начинаем с просьбы получить число от пользователя
    int userNumberGuess = menu();
    //а здесь мы уже создаём то число, которое будем угадывать
    int guessNumber = createGuessNumber(userNumberGuess);
    //теперь начинаем игру
    game(guessNumber, userNumberGuess);

    return 0;
}
