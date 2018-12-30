#include <iostream>
#include <ctime>
#include <random>

/*�������

1. �������� ������������ ���-�� ����������.
2. ������� ������ ������� �� ������, ������, �����.
3. ������� ����������� ������� ���, �� ������ �� ���������
4. �������� ���������� � ��������, ��������� �������� ����� ���������� ������������

*/

//��������� ����� �� ������, ������, �����...
int check(int tryNumber, int guessNumber){
    using namespace std;

    //���������� � ����������� �������, ������� �����.
    static int countOfTry = 0;

    //���� ����� ������ �����������...
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

//������� ����, ��� �� ������ ����� � ������������
int menu(){
    using namespace std;
    //������� ����
    cout << "MoreOrLess" << endl;
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
        //���� �� �����, �� ���������� �����
        else {
            system("cls");
            return number;
        }
    }
}

int main(){
    using namespace std;
    setlocale(0, "");

    //�������� � ������� �������� ����� �� ������������
    int userNumberGuess = menu();
    //� ����� �� ��� ������ �� �����, ������� ����� ���������
    int guessNumber = createGuessNumber(userNumberGuess);
    //������ �������� ����
    game(guessNumber, userNumberGuess);

    return 0;
}
