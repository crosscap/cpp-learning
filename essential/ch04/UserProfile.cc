#include "UserProfile.h"

inline void UserProfile::set_percentage_correct()
{
    _percentage_correct = _guess_count == 0 ? 0.0 :
        (double)_correct_count / (double)_guess_count;
}

inline bool UserProfile::operator==(UserProfile &rhs) const
{
    return _user_ID == rhs._user_ID;
}

inline bool UserProfile::operator!=(UserProfile &rhs) const
{
    return !(*this == rhs);
}

ostream & operator<<(ostream &os, const UserProfile &rhs)
{
    os << "user ID: " << rhs.user_ID() << '\n'
       << "level: " << rhs.level() << '\n'
       << "login count: " << rhs.log_count() << '\n'
       << "guess count: " << rhs.guess_count() << '\n'
       << "correct count: " << rhs.correct_count() << '\n'
       << "percentage correct: " << rhs.percentage_correct() << endl;

    return os;
}

istream& operator>>( istream &is, UserProfile &rhs )
{ // yes, this assumes the input is valid ...
    string login;
    int level;
    is >> login >> level;

    int lcount, gcount, gcorrect;
    is >> lcount >> gcount >> gcorrect;

    rhs.set_user_name( login );
    rhs.set_level( level );

    rhs.set_log_count( lcount );
    rhs.set_guess_count( gcount );
    rhs.set_correct_count( gcorrect );

    return is;
}