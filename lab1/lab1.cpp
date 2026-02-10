#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int base, i, digit;
    char single_digit;            // одна цифра из всего числа
    string number;                // задаваемое число
    long result = 0;              // число в десятичной системе
    long current_pow = 1;         // рассматриваемая степень
    long next_power;              // следующая рассматриваемая степень
    long piece_of_result;         // результат перевода числа в 10-ую сс, прибавляемый к общему результату
    do
    {
        cout << "Введите основание системы счисления (2–16): ";
        if (!(cin >> base))
        {
            cout << "Ошибка! Введите число от 2 до 16\n\n";
            cin.clear();
            cin.ignore(777, '\n');
        }

        if (base < 2 || base > 16)
        {
            cout << "Ошибка! Введите число от 2 до 16.\n";
        }
    } while (base < 2 || base > 16);

    cout << "\nВведите число в заданной системе счисления: ";
    cin >> number;
    i = number.size() - 1;
    while (i >= 0)
    {
        single_digit = number[i];
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
        else if (single_digit == 'A' || single_digit == 'a') digit = 10;
        else if (single_digit == 'B' || single_digit == 'b') digit = 11;
        else if (single_digit == 'C' || single_digit == 'c') digit = 12;
        else if (single_digit == 'D' || single_digit == 'd') digit = 13;
        else if (single_digit == 'E' || single_digit == 'e') digit = 14;
        else if (single_digit == 'F' || single_digit == 'f') digit = 15;
        else
        {
            cout << "\nОшибка: недопустимый символ '" << single_digit << "'\n";
            return 1;
        }
        if (digit >= base)
        {
            cout << "\nОшибка: цифра '" << single_digit << "' (значение " << digit << ") недопустима в системе с основанием " << base << endl;
            return 1;
        }
        piece_of_result = digit * current_pow;
        result = result + piece_of_result;
        if (i > 0)
        {
            next_power = current_pow * base;
            current_pow = next_power;
        }

        i = i - 1;
    }

    cout << endl << number << " в системе с основанием " << base << " = " << result << " в десятичной системе\n";

    cin.get();
    return 0;
}