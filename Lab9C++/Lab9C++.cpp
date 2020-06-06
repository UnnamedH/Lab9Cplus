#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <vector>
using namespace std;

bool isTimeCorrect(tm proceduresTime[],int i) {
    bool value = false;

    time_t year = proceduresTime[i].tm_year;
    time_t month = proceduresTime[i].tm_mon;
    time_t day = proceduresTime[i].tm_mday;
    time_t hours = proceduresTime[i].tm_hour;
    time_t minutes = proceduresTime[i].tm_min;
    time_t seconds = proceduresTime[i].tm_sec;


    if (month > 0 && month <= 12) {
        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
            {
                if ((day <= 31) && (day > 0))
                    value = true;
                break;
            }
            case 4:
            case 6:
            case 9:
            case 11:
            {
                if ((day <= 30) && (day > 0))
                    value = true;
                break;
            }
            case 2:
            {
                if (year % 4 != 0)
                {
                    if ((day <= 28) && (day > 0))
                        value = true;
                }
                else if (year % 4 == 0)
                {
                    if ((day <= 29) && (day > 0))
                        value = true;
                }
            }

        }

    }
        return value;
    
}

void easy() {
    time_t year;
    time_t month;
    time_t day;
    time_t hours;
    time_t minutes;
    time_t seconds;
    int colvoProcedures = 0;
    char point;
    char TwoPoins;
    tm proceduresTime[100] = {};
    int k = 0;
    cout << "Нажмите E, если хотите завершить ввод." << endl;
    while (!GetKeyState(VK_DELETE)) {
        cout << "Введите время процедуры (dd:mm:yyyy hh:mm:ss): ";
        while (cin >> day >> point >> month >> point >> year >> point >> hours >> TwoPoins >> minutes >> TwoPoins >> seconds) {
            //struct tm newtime;
            //time_t now = time(0);
            //localtime_s(&newtime, &now);
            proceduresTime[k].tm_year = year;
            proceduresTime[k].tm_mon = month;
            proceduresTime[k].tm_mday = day;
            proceduresTime[k].tm_hour = hours;
            proceduresTime[k].tm_min = minutes;
            proceduresTime[k].tm_sec = seconds;
            /*newtime.tm_year = year;
            newtime.tm_mon = month;
            newtime.tm_mday = day;
            newtime.tm_hour = hours;
            newtime.tm_min = minutes;
            newtime.tm_sec = seconds;*/
            
            if (isTimeCorrect(proceduresTime,k) && point == '.' && TwoPoins == ':') {
                colvoProcedures++;
                break;
            }
        }
        k++;
    }
    
    for (int i = 1; i < colvoProcedures; i++) {
        cout << endl <<"Время " << i++ << "процедуры" << proceduresTime[k].tm_mday << point << proceduresTime[k].tm_mon << 
            point << proceduresTime[k].tm_year << point << proceduresTime[k].tm_hour 
            << TwoPoins << proceduresTime[k].tm_min << TwoPoins << proceduresTime[k].tm_sec;
    }

}

int main()
{
    setlocale(LC_ALL,"");
    easy();
}


