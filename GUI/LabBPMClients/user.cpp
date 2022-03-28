#include "user.h"

User::User()
{
    SetName ("Name");
    SetSurname ("Surname");
    SetEmail ("biba@boba.com");
}

void User::SetName (std::string NewName)
{
    Name = NewName;
}

void User::SetSurname (std::string NewSurName)
{
    Surname = NewSurName;
}

void User::SetEmail (std::string NewEmail)
{
    Email = NewEmail;
}

std::string User::GetName ()
{
    return Name;
}

std::string User::GetSurname ()
{
    return Surname;
}

std::string User::GetEmail ()
{
    return Email;
}
