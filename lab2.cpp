#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string number, full_bits, notfull_bits, expo;
    int exp, full, mantis, single_digit, i, znak, digit, isfull;
    float notfull;
    isfull = -1;
    full = 0;
    notfull = 0;
    i = 0;

    cout << "Введите число: ";
    cin >> number;

    if (number[0] == '-')
    {
        znak = 1;
        for (int check = 1; check < number.size() && number[check] != ',' && number[check] != '.'; check++)
        {
            isfull++;
            single_digit = number[check];
            if (single_digit == '0') digit = 0;
            else if (single_digit == '1') digit = 1;
            else if (single_digit == '2') digit = 2;
            else if (single_digit == '3') digit = 3;
            else if (single_digit == '4') digit = 4;
            else if (single_digit == '5') digit = 5;
            else if (single_digit == '6') digit = 6;
            else if (single_digit == '7') digit = 7;
            else if (single_digit == '8') digit = 8;
            else if (single_digit == '9') digit = 9;
            else
            {
                cout << "\nОшибка: недопустимый символ '" << single_digit << "'\n";
                return 1;
            }
            full = full * 10 + digit;
        }

    }
    else
    {
        znak = 0;
        for (int check = 0; check < number.size() && number[check] != ',' && number[check] != '.'; check++)
        {
            isfull++;
            single_digit = number[check];
            if (single_digit == '0') digit = 0;
            else if (single_digit == '1') digit = 1;
            else if (single_digit == '2') digit = 2;
            else if (single_digit == '3') digit = 3;
            else if (single_digit == '4') digit = 4;
            else if (single_digit == '5') digit = 5;
            else if (single_digit == '6') digit = 6;
            else if (single_digit == '7') digit = 7;
            else if (single_digit == '8') digit = 8;
            else if (single_digit == '9') digit = 9;
            else
            {
                cout << "\nОшибка: недопустимый символ '" << single_digit << "'\n";
                return 1;
            }
            full = full * 10 + digit;
        }

    }
    int perevod1 = full; 
    full_bits = "";

    if (perevod1 == 0) 
        full_bits = "0";
    else 
    {
        while (perevod1 > 0) 
        {
            full_bits = to_string(perevod1 % 2) + full_bits;
            perevod1 = perevod1 / 2;
        }
    }

    for (int check = isfull + 2; check < number.size(); check++)
    {
            if (number[check] == ',' || number[check] == '.') continue;
            single_digit = number[check];
            if (single_digit == '0') digit = 0;
            else if (single_digit == '1') digit = 1;
            else if (single_digit == '2') digit = 2;
            else if (single_digit == '3') digit = 3;
            else if (single_digit == '4') digit = 4;
            else if (single_digit == '5') digit = 5;
            else if (single_digit == '6') digit = 6;
            else if (single_digit == '7') digit = 7;
            else if (single_digit == '8') digit = 8;
            else if (single_digit == '9') digit = 9;
            else
            {
                cout << "\nОшибка: недопустимый символ '" << single_digit << "'\n";
                return 1;
            }
            notfull = notfull * 10 + digit;
            i++;
    }

    notfull_bits = "";
    notfull = notfull / pow(10, i);
    float perevod2 = notfull;
    if (perevod2 == 0)
        notfull_bits = "00000000000000000000000";
    else
    {
        for (int i = 0; i < 24; i++)
        {
            perevod2 = perevod2 * 2;
            if (perevod2 >= 1)
            {
                perevod2 = perevod2 - 1;
                notfull_bits = notfull_bits + "1";
            }
            else
                notfull_bits = notfull_bits + "0";
        }
    }

    if (full == 0) 
    {
        i = 1;
        while (i < notfull_bits.size() && notfull_bits[i] != '1') 
        {
            i++;
        }
        exp = 127 - i;
    }
    else
        exp = full_bits.size() - 1 + 127;
    
    expo = "";
    int perevod3 = exp;
    if (perevod3 == 0)
        expo = "00000000";
    if (number == "0" || number == "-0")
        expo = "00000000";
    if (full == 0 && notfull == 0)
        expo = "00000000";
    else
    {
        while (perevod3 > 0)
        {
            expo = to_string(perevod3 % 2) + expo;
            perevod3 = perevod3 / 2;
        }
    }
    
    for (int check = full_bits.size() - 1; check >= 0; check--)
    {
        notfull_bits = full_bits[check] + notfull_bits;
    }

    cout << "Представление числа " << number << " в формате IEEE754:\n"
        << znak << ' ' << expo << ' ' << notfull_bits.substr(0, 23) << endl;

    cin.get();
    return 0;
}