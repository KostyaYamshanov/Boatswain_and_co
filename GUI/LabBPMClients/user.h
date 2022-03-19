#ifndef USER_H
#define USER_H
#include <string>

class User
{
public:
    User();
    void SetName (std::string NewName);
    void SetSurname (std::string NewSurName);
    void SetEmail (std::string NewEmail);
    std::string GetName ();
    std::string GetSurname ();
    std::string GetEmail ();
private:
    std::string Name;
    std::string Surname;
    std::string Email;
};

#endif // USER_H
