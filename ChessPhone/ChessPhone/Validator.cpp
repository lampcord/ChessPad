#include "Validator.h"

validatorresult Validator::IsValid(string tokens)
{
    if (tokens.size() == 0) return validatorresult::keepgoing;
    if (tokens.size() > validlength) return validatorresult::reject;

    if (tokens.size() == 1)
    {
        if (validfirstdigit.count(tokens[0]) == 0) return validatorresult::reject;
    }
    else
    {
        if (validdigits.count(tokens.back()) == 0) return validatorresult::reject;
    }


    if (tokens.size() == validlength) return validatorresult::accept;

    return validatorresult::keepgoing;
}

void SevenDigitPhoneNumberValidator::initialize()
{
    validdigits = set<char>({ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' });
    validfirstdigit = set<char>({ '2', '3', '4', '5', '6', '7', '8', '9' });
    validlength = 7;
}

void TenDigitPhoneNumberValidator::initialize()
{
    validdigits = set<char>({ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' });
    validfirstdigit = set<char>({ '2', '3', '4', '5', '6', '7', '8', '9' });
    validlength = 10;
}
