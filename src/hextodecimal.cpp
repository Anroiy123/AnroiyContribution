#include "hextodecimal.h"

std::string HexToDecimal::CovertIntegerPartToDecimal(std::string integerPart)
{
    if (integerPart == "0")
    {
        return "0";
    }
    else
    {
        int decimalValue = 0;
        int base = 1;

        for (int i = integerPart.size() - 1; i >= 0; i--)
        {
            if (integerPart[i] >= '0' && integerPart[i] <= '9')
            {
                decimalValue += (integerPart[i] - '0') * base;
            }
            else if (integerPart[i] >= 'A' && integerPart[i] <= 'F')
            {
                decimalValue += (integerPart[i] - 'A' + 10) * base;
            }

            base *= 16;
        }

        return std::to_string(decimalValue);

    }
}

std::string HexToDecimal::ConvertFractionalPartToDecimal(std::string fractionalPart, int precision)
{
    if (fractionalPart == "0")
    {
        return "";
    }
    else
    {
        double decimalValue = 0;
        double base = 16;

        for (int i = 0; i < fractionalPart.size(); i++)
        {
            if (fractionalPart[i] >= '0' && fractionalPart[i] <= '9')
            {
                decimalValue += (fractionalPart[i] - '0') / base;
            }
            else if (fractionalPart[i] >= 'A' && fractionalPart[i] <= 'F')
            {
                decimalValue += (fractionalPart[i] - 'A' + 10) / base;
            }

            base *= 16;
        }

        std::string decimalValueString = std::to_string(decimalValue);
        return decimalValueString.substr(2, precision);

    }
}

/*helpfull function*/
// int HexToDecimal::ConvertToDecimal(char hexDigit)
// {
//     if (hexDigit >= '0' && hexDigit <= '9')
//     {
//         return hexDigit - '0';
//     }
//     else if (hexDigit >= 'A' && hexDigit <= 'F')
//     {
//         return hexDigit - 'A' + 10;
//     }

//     throw std::invalid_argument("Invalid hexadecimal digit");
// }

HexToDecimal::HexToDecimal()
{
}

std::string HexToDecimal::Convert(std::string hexNumber, int precision)
{
    ValidNumberConversions::IsHexadecimalNumber(hexNumber);

    size_t dotPosition = hexNumber.find('.');

    std::string integerPart = hexNumber.substr(0, dotPosition);
    std::string fractionalPart = (dotPosition != std::string::npos) ? hexNumber.substr(dotPosition + 1) : "0";

    std::string integerPartDecimal = CovertIntegerPartToDecimal(integerPart);
    std::string fractionalPartDecimal = ConvertFractionalPartToDecimal(fractionalPart, precision);

    if (fractionalPartDecimal.empty())
    {
        return integerPartDecimal;
    }
    else
    {
        return integerPartDecimal + "." + fractionalPartDecimal;
    }
}
