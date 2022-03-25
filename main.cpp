#include <iostream>
using namespace std;

string TakeSecondPart(string number)
{
    string result = "";
    int dotCounter = 0;

    for (int i = number.length() - 1; i >= 0; i--)
    {
        if ((i == (number.length() - 1)) && (number[i] == '.'))
        {
            result += '0';
        }
        else
        {
            result = number[i] + result;
        }

        if (number[i] == '.')
        {
            dotCounter++;
            return result;
        }
    }

    if (dotCounter == 0)
    {
        return result = ".0";
    }
}

string TakeFirstPart(string number)
{
    string result = "";

    for (int i = 0; i < number.length(); i++)
    {
        if ((i == 0) && (number[i] == '.'))
        {
            result += '0';
        }
        if ((i == 0) && (number[i] == '0'))
        {
            continue;
        }
        else
        {
            if (number[i] != '.')
            {
                result += number[i];
            }
        }

        if (number[i] == '.')
        {
            return result;
        }
    }

    return result;
}

string LongRealNumberComparisonInDetail(string number1part, string number2part, int part)
{
    string result = "";

    if (part == 1)
    {
        if (number1part.length() > number2part.length())
        {
            return result = "More";
        }
        else if (number1part.length() < number2part.length())
        {
            return result = "Less";
        }
        else
        {
            for (int i = 0; i < number1part.length(); i++)
            {
                if (number1part[i] > number2part[i])
                {
                    return result = "More";
                }
                else if (number1part[i] < number2part[i])
                {
                    return result = "Less";
                }
            }

            return result = "Equal";
        }
    }
    else // (part == 2)
    {
        if (number1part.length() > number2part.length()) // first number bigger
        {
            int i = 0;
            for (; i < number2part.length(); i++)
            {
                if (number1part[i] > number2part[i])
                {
                    return result = "More";
                }
                else if (number1part[i] < number2part[i])
                {
                    return result = "Less";
                }
            }

            for (; i < number1part.length(); i++)
            {
                if (number1part[i] > '0')
                {
                    return result = "More";
                }
            }

            return result = "Equal";
        }
        else if (number1part.length() < number2part.length()) // second number bigger
        {
            int i = 0;
            for (; i < number1part.length(); i++)
            {
                if (number1part[i] > number2part[i])
                {
                    return result = "More";
                }
                else if (number1part[i] < number2part[i])
                {
                    return result = "Less";
                }
            }

            for (; i < number2part.length(); i++)
            {
                if (number1part[i] > '0')
                {
                    return result = "More";
                }
            }

            return result = "Equal";
        }
        else // equal length
        {
            for (int i = 0; i < number1part.length(); i++)
            {
                if (number1part[i] > number2part[i])
                {
                    return result = "More";
                }
                else if (number1part[i] < number2part[i])
                {
                    return result = "Less";
                }
            }

            return result = "Equal";
        }
    }
}

string LongRealNumberComparison(string firstNumber, string secondNumber)
{
    string result = "";

    result = LongRealNumberComparisonInDetail(TakeFirstPart(firstNumber), TakeFirstPart(secondNumber), 1);

    if (result != "Equal")
        return result;

    result = LongRealNumberComparisonInDetail(TakeSecondPart(firstNumber), TakeSecondPart(secondNumber), 2);

    return result;
}

int LongNumberValidation(string number)
{
    int counter = 0;

    if ((number[0] == '-') || (number[0] == '.')
        || ((number[0] >= '0') && (number[0] <= '9')))
    {
        if (((number[0] == '-') || (number[0] == '.'))
            && (number.length() == 1))
        {
            cout << "Wrong number! Only '-' or dot. Even one number must be in your number!" << endl;
            return 0;
        }

        for (int i = 0; i < number.length(); i++)
        {
            if (number[i] == '.')
            {
                counter++;
            }
        }

        if (counter < 2)
        {
            for (int i = 1; i < number.length(); i++)
            {
                counter = 0;

                if (((number[i] < '0') || (number[i] > '9'))
                    && (number[i] != '.'))
                {
                    cout << "Wrong number! Wrong symbol detected. Symbol : " << number[i] << endl;
                    return 0;
                }
                else
                {
                    if ((number[1] == '.') && (number.length() == 2)
                        && ((number[0] == '-')))
                    {
                        cout << "Wrong number! Even one number must be in your number." << endl;
                        return 0;
                    }
                }
            }
        }
        else
        {
            cout << "Wrong number! Two dots are invalid! It should be one dot!" << endl;
            return 0;
        }
    }
    else
    {
        cout << "Wrong number First symbol is not '-' or '.' or number." << endl;
        return 0;
    }

    return 1;
}

string IfNegativeNumber(string funcRes, string firstNumber, string secondNumber)
{
    string result = "";

    if ((firstNumber[0] == '-') || (secondNumber[0] == '-'))
    {
        if ((firstNumber[0] == '-') && (secondNumber[0] != '-'))
        {
            return result = "Less";
        }

        if ((firstNumber[0] != '-') && (secondNumber[0] == '-'))
        {
            return result = "More";
        }

        if ((firstNumber[0] == '-') && (secondNumber[0] == '-'))
        {
            if (funcRes == "More")
            {
                return result = "Less";
            }
            else if (funcRes == "Less")
            {
                return result = "More";
            }
            else
            {
                return funcRes;
            }
        }
    }
    else
    {
        return funcRes;
    }
}

void Tests()
{
    cout << "Enter first number  : 2.39\n";
    cout << "Enter second number : 3.61\n";
    cout << "Answer " << IfNegativeNumber(LongRealNumberComparison("2.39", "3.61"), "2.39", "3.61") << endl;

    cout << endl << "Enter first number  : 0123\n";
    cout << "Enter second number : 12.3\n";
    cout << "Answer " << IfNegativeNumber(LongRealNumberComparison("0123", "12.3"), "0123", "12.3") << endl;

    cout << endl << "Enter first number  : 12345678\n";
    cout << "Enter second number : 12345678.00\n";
    cout << "Answer " << IfNegativeNumber(LongRealNumberComparison("12345678", "12345678.00"), "12345678", "12345678.00") << endl;

    cout << endl << "Enter first number  : -1.0\n";
    cout << "Enter second number : 1.0\n";
    cout << "Answer " << IfNegativeNumber(LongRealNumberComparison("-1.0", "1.0"), "-1.0", "1.0") << endl;

    cout << endl << "Enter first number  : -1.1\n";
    cout << "Enter second number : -1.2\n";
    cout << "Answer " << IfNegativeNumber(LongRealNumberComparison("-1.1", "-1.2"), "-1.1", "-1.2") << endl;

    cout << endl << "Enter first number  : -.0\n";
    cout << "Enter second number : -.0\n";
    cout << "Answer " << IfNegativeNumber(LongRealNumberComparison("-.0", "-.0"), "-.0", "-.0") << endl;

    cout << endl << "Enter first number  : -.02\n";
    cout << "Enter second number : -.0200\n";
    cout << "Answer " << IfNegativeNumber(LongRealNumberComparison("-.0", "-.0"), "-.0", "-.0") << endl;

    cout << endl << "Enter first number  : 0.0300\n";
    cout << "Enter second number : 0.03\n";
    cout << "Answer " << IfNegativeNumber(LongRealNumberComparison("0.0300", "0.03"), "0.0300", "0.03") << endl;

}

int main(int argc, char** argv)
{
    string firstNumber, secondNumber;

    Tests();

    do
    {
        cout << endl << "Enter first number\n";
        cin >> firstNumber;
    } while (LongNumberValidation(firstNumber) != 1);

    do
    {
        cout << "Enter second number\n";
        cin >> secondNumber;
    } while (LongNumberValidation(secondNumber) != 1);

    cout << "Answer " << IfNegativeNumber(LongRealNumberComparison(firstNumber, secondNumber), firstNumber, secondNumber) << endl;

    return 0;
}