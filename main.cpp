#include <iostream>
#include <ctime>
#include <random>
#include <windows.h>

/*
    cout << ".00...00.....................000........0............0000..0000..." << endl;
    cout << ".0.0.0.0..000..0.00...000...0...0.0.00..0......000..0.....0......." << endl;
    cout << ".0..0..0.0...0.00..0.0___0..0...0.00....0.....0___0..000...000...." << endl;
    cout << ".0.....0.0...0.0.....0......0...0.0.....0.....0.........0.....0..." << endl;
    cout << ".0.....0..000..0......0000...000..0.....00000..000..0000..0000...." << endl;
*/

//ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ
//переменная с количеством попыток, угадать число.
int countOfTry = 0;


//ПРЕДВАРИТЕЛЬНОЕ ОБЪЯВЛЕНИЕ ФУНКЦИЙ
int playAgain();
int check();
int check(int tryNumber, int guessNumber);
void game(int guessNumber, int userNumber);
int createGuessNumber (int userNumberGuess);
int menu();

int main(){
    using namespace std;
    setlocale(0, "");

    //начинаем с просьбы получить число от пользователя
    int userNumberGuess = menu();

    //а здесь мы уже создаём то число, которое будем угадывать
    int guessNumber = createGuessNumber(userNumberGuess);

    //теперь начинаем игру
    game(guessNumber, userNumberGuess);

    //иначе заканчиваем игру
    return 0;
}

//функция меню, где мы просим число у пользователя
int menu(){
    using namespace std;
    //выводим меню
    cout << "  >>   >>                     ===        <            <<<<  <<<<  " << endl;
    cout << "  > > > >  >>>  > >>   >>>   =   = = ==  <      <<<  <     <      " << endl;
    cout << "  >  >  > >   > >>  > >___>  =   = ==    <     <___<  <<<   <<<   " << endl;
    cout << "  >     > >   > >     >      =   = =     <     <         <     <  " << endl;
    cout << "  >     >  >>>  >      >>>>   ===  =     <<<<<  <<<< <<<<  <<<<   " << endl;
    cout << "- - - - - - - - - - - -=By VovaOne - v1.1=- - - - - - - - - - - - " << endl;
    Sleep(800); //небольшая пауза
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
        //easter eggs
        else if(number == 228){
            system("cls");
            cout << "Ку-ку ёпта!" << endl;
            return number;
        }
        else if(number == 1488){
            system("cls");
            cout << "0/" << endl;
            return number;
        }
        else if(number == 1337){
            system("cls");
            cout << "leet" << endl;
            return number;
        }
        //если всё верно, то возвращаем число
        else {
            system("cls");
            return number;
        }
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
            //иначе просто заканчиваем цикл и бесконечные требования о првильном числе
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
    //если угадали, то спрашиваем о повторной игре.
    else if(result == 0){
        playAgain();
    }

}

//проверяем число на больше, меньше, равно...
int check(int tryNumber, int guessNumber){
    using namespace std;

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



//функция для повторной игры. выполняется последней.
int playAgain(){
    using namespace std;

    Sleep(1000);
    //простое меню
    cout << "Сыграем ещё?" << endl;
    cout << "[1] - Да!" << endl;
    cout << "[2] - Нет..." << endl;

    //переменная для выбора
    int sel = 0;
    while(true){
        cin >> sel;
        //далее алгорим на правильность ввода...
        if (cin.fail()){
            cin.clear();
            cin.ignore(32767,'\n');
        }
        else if (sel == 1){
            //если юзверь сограсен, то играем ещё раз
            system("cls");
            countOfTry = 0; //аннулируем значение попыток
            main();

        }
        else if (sel == 2){
            //иначе закрываем программу
            break;
        }
    }
}
