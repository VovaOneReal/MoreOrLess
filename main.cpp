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

//���������� ����������
//���������� � ����������� �������, ������� �����.
int countOfTry = 0;


//��������������� ���������� �������
int playAgain();
int check();
int check(int tryNumber, int guessNumber);
void game(int guessNumber, int userNumber);
int createGuessNumber (int userNumberGuess);
int menu();

int main(){
    using namespace std;
    setlocale(0, "");

    //�������� � ������� �������� ����� �� ������������
    int userNumberGuess = menu();

    //� ����� �� ��� ������ �� �����, ������� ����� ���������
    int guessNumber = createGuessNumber(userNumberGuess);

    //������ �������� ����
    game(guessNumber, userNumberGuess);

    //����� ����������� ����
    return 0;
}

//������� ����, ��� �� ������ ����� � ������������
int menu(){
    using namespace std;
    //������� ����
    cout << "  >>   >>                     ===        <            <<<<  <<<<  " << endl;
    cout << "  > > > >  >>>  > >>   >>>   =   = = ==  <      <<<  <     <      " << endl;
    cout << "  >  >  > >   > >>  > >___>  =   = ==    <     <___<  <<<   <<<   " << endl;
    cout << "  >     > >   > >     >      =   = =     <     <         <     <  " << endl;
    cout << "  >     >  >>>  >      >>>>   ===  =     <<<<<  <<<< <<<<  <<<<   " << endl;
    cout << "- - - - - - - - - - - -=By VovaOne - v1.1=- - - - - - - - - - - - " << endl;
    Sleep(800); //��������� �����
    cout << "������� ����� �� �������� ����� ���������:" << endl;

    //� ������� ����� ������� � ������������ ������� �����
    while (true){

    //������ ���������� � ������ ������������ ������ �����
    //��� ����� ����� �������������� ��� ������������� ��������� ����������
    long long int number;
    cin >> number;
        //�������� ��� �������� ������������ �����
        if (cin.fail()){
                cin.clear();
                cin.ignore(32767,'\n');
                system("cls");
                cout << "������� ���������� ��������:" << endl;
            }
        //easter eggs
        else if(number == 228){
            system("cls");
            cout << "��-�� ����!" << endl;
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
        //���� �� �����, �� ���������� �����
        else {
            system("cls");
            return number;
        }
    }
}

//������ ����������� �����
int createGuessNumber (int userNumberGuess){
    using namespace std;

    //��������� ����� ��������
    mt19937 mersenne(static_cast<unsigned int>(time(0)));
    //���������� ����� �������� ��� �������� ������������ ����� �� 1 �� userGuessNumber
    int guessNumber = 1 + mersenne() % userNumberGuess;
    return guessNumber;
}

void game(int guessNumber, int userNumber){
    using namespace std;
    //������ ������������ ������ �����
    cout << "������� ����� �� 1 �� " << userNumber << ":" << endl;
    int tryNumber; //���������� ��� ������� ���������� ����������� �����
    while(true){
        cin >> tryNumber;
            //����� ������� �� ������������ �����.
            //�����, ���� ������������ ��� �������
            if (cin.fail()){
                cin.clear();
                cin.ignore(32767,'\n');
                system("cls");
                cout << "������� ���������� �������� �� 1 �� " << userNumber << ":" << endl;
            }
            //�����, ���� ������������ ��� �����, ������� ������-������ �����������
            else if(tryNumber > userNumber || tryNumber < 1){
                system("cls");
                cout << "������� ���������� �������� �� 1 �� " << userNumber << ":" << endl;
            }
            //����� ������ ����������� ���� � ����������� ���������� � ��������� �����
            else {
                break;
            }
    }
    //��������� �����, ��������� �� ��� � ���������� ��� ��������� ��� ������ � ����?
    //��������� ��������� � ����������. 1 - �� �������, 0 - �������.
    int result = check(tryNumber, guessNumber);

    //���� �� �� �������, �� ������� ��� ���.
    if(result == 1){
        game(guessNumber, userNumber);
    }
    //���� �������, �� ���������� � ��������� ����.
    else if(result == 0){
        playAgain();
    }

}

//��������� ����� �� ������, ������, �����...
int check(int tryNumber, int guessNumber){
    using namespace std;

    if (tryNumber < guessNumber){
        system("cls");
        //��������� �������� � ���������� �������
        ++countOfTry;
        cout << "���������� ����� ������." << endl;
        return 1;
    }
    //���� ����� ������ �����������...
    else if(tryNumber > guessNumber){
        system("cls");
        //��������� �������� � ���������� �������
        ++countOfTry;
        cout << "���������� ����� ������." << endl;
        return 1;
    }
    //���� ����� ����� �����������...
    else if(tryNumber == guessNumber){
        system("cls");
        //��������� �������� � ���������� �������
        ++countOfTry;
        cout << "����������! �� ������� ����� � " << countOfTry << " �������!" << endl;
        return 0;
    }
    //���� ����� ���-�� ������ ������... (�� ������� ������� �� ���������)
    else{
        system("cls");
        cout << "���-�� �������..." << endl;
        return 1;
    }
}



//������� ��� ��������� ����. ����������� ���������.
int playAgain(){
    using namespace std;

    Sleep(1000);
    //������� ����
    cout << "������� ���?" << endl;
    cout << "[1] - ��!" << endl;
    cout << "[2] - ���..." << endl;

    //���������� ��� ������
    int sel = 0;
    while(true){
        cin >> sel;
        //����� ������� �� ������������ �����...
        if (cin.fail()){
            cin.clear();
            cin.ignore(32767,'\n');
        }
        else if (sel == 1){
            //���� ������ ��������, �� ������ ��� ���
            system("cls");
            countOfTry = 0; //���������� �������� �������
            main();

        }
        else if (sel == 2){
            //����� ��������� ���������
            break;
        }
    }
}
