#include <iostream>
using namespace std;
int year_num(int y);
int month_num(int y, int m);
int pass_days(int y, int m);
int main() {
    int year, month, days, space;
    while(cin >> year >> month) {
        space = pass_days(year, month) % 7;
        days = month_num(year, month);
        cout << "一 二 三 四 五 六 日" << endl;
        for(int i = 0; i < space; i++) {
            cout << "   ";
        }
        for(int j = 1; j <= days; j++) {
            if(j < 10)
                cout << " ";
            cout << j << " ";
            if(j == 7 - space || j == 14 - space || j == 21 - space || j == 28 - space || j == 35 - space)
                cout << endl;
        }
        cout << endl;
    }
}
int year_num(int y) {
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        return 366;
    else
        return 365;
}
int month_num(int y, int m) {
    switch (m) {
            case 2:
                if(y == 365)
                    return 28;
                else
                    return 29;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
                break;
            default:
                return 31;
        }
}
int pass_days(int y, int m) {
    int sum = 0;
    for(int i = 1900; i < y; i++) {
        sum += year_num(i);
    }
    if(m > 1) {
        for(int j = 1; j < m; j++) {
            sum += month_num(y, j);
        }
    }
    return sum;
}
