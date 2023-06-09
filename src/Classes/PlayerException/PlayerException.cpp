#include "PlayerException.hpp"

PlayerException::PlayerException()
{
    message = "";
}

PlayerException::PlayerException(string message)
{
    this->message = message;
}

string PlayerException::getMessage()
{
    return message;
}

UsernameEmpty::UsernameEmpty()
{
    message = "Username cannot be empty!";
};

AbilityNotOwned::AbilityNotOwned() : PlayerException("Oops you dont have ability card! ")
{
}

string AbilityNotOwned::getMessage(string abilityAttempted)
{
    return this->message + abilityAttempted;
}

AbilityNotAvailable::AbilityNotAvailable() : PlayerException()
{
}

AbilityNotAvailable::AbilityNotAvailable(string message) : PlayerException(message)
{
}
