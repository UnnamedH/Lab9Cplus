#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <vector>

using namespace std;

bool isTimeCorrect(tm time) {
    bool value = false;

    time_t year = time.tm_year;
    time_t month = time.tm_mon;
    time_t day = time.tm_mday;
    time_t hours = time.tm_hour;
    time_t minutes = time.tm_min;
    time_t seconds = time.tm_sec;


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

time_t getTimeFromConsole() {
    string date_str;
    string time_str;
    cin >> date_str >> time_str;

    int day = 0;
    int month = 0;
    int year = 0;
    if (sscanf_s(date_str.c_str(), "%d.%d.%d", &day, &month, &year) == -1) {
        return -1;
    }

    int hour = 0;
    int min = 0;
    int sec = 0;
    if (sscanf_s(time_str.c_str(), "%d:%d:%d", &hour, &min, &sec) == -1) {
        return -1;
    }
    
    struct tm time = { 0 };

    time.tm_year = year;
    time.tm_mon = month;
    time.tm_mday = day;
    time.tm_hour = hour;
    time.tm_min = min;
    time.tm_sec = sec;

    if (!isTimeCorrect(time)) {
        return -1;
    }

    time.tm_year = time.tm_year - 1900;
    time.tm_mon = time.tm_mon - 1;

    return mktime(&time);
}

string formatTime(time_t timeSeconds)
{
    tm time;
    localtime_s(&time, &timeSeconds);
    char buffer[100];
    strftime(buffer, 100, "%d.%m.%Y %H:%M:%S", &time);
    return buffer;
}

int main()
{
    setlocale(LC_ALL,"");
    
    cout << "Введите время первой процедуры (dd.mm.yyyy hh:mm:ss): ";
    time_t firstTime = getTimeFromConsole();
    if (firstTime == -1) {
        cout << "Указано неверное время первой процедуры";
        return 0;
    }
    
    cout << "Введите время второй процедуры (dd.mm.yyyy hh:mm:ss): ";
    time_t secondTime = getTimeFromConsole();
    if (secondTime == -1) {
        cout << "Указано неверное время второй процедуры";
        return 0;
    }

    cout << "Введите количество процедур: ";
    int numberOfProcedures;
    cin >> numberOfProcedures;
    if (numberOfProcedures <= 0) {
        cout << "Указано неверное количество процедур";
        return 0;
    }

    double interval = difftime(secondTime, firstTime);
    if (interval <= 0) {
        cout << "Конечное время должно быть позже чем начальное";
        return 0;
    }

    time_t time = firstTime-3600;
    for (int i = 1; i <= numberOfProcedures; i++) {
        cout << endl << "Время " << i << " процедуры: " << formatTime(time);
        time = time + interval;
    }
    cout << endl;

    return 0;

}




