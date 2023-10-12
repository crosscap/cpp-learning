#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class UserProfile
{
public:
    UserProfile(string login = "guest", string uLevel = levels[0])
        : _user_name(login), _level(uLevel),
          _user_ID(ID_counter++),_log_count(1),
          _guess_count(0), _correct_count(0), _percentage_correct(0.0) {}

    string user_name() const { return _user_name; }
    int log_count() const { return _log_count; }
    int guess_count() const { return _guess_count; }
    int correct_count() const { return _correct_count; }
    string level() const { return _level; }
    double percentage_correct() const { return _percentage_correct; }
    int user_ID() const {return _user_ID; }

    void set_user_name(const string &val) { _user_name = val;}
    void set_log_count(int val = 1) { _log_count = val; }
    void set_guess_count(int val) { _guess_count = val; }
    void set_correct_count(int val) { _correct_count = val; }
    void set_level(int index) { _level = levels[index]; }
    void set_percentage_correct();

    void bump_log_count(int cnt = 1) { _log_count += cnt; }
    void bump_guess_count(int cnt = 1) { _guess_count += cnt; }
    void bump_correct_count(int cnt = 1) { _correct_count += cnt; }

    bool operator==(UserProfile &rhs) const;
    bool operator!=(UserProfile &rhs) const;
private:
    string _user_name;
    int _log_count;
    int _guess_count;
    int _correct_count;
    string _level;
    double _percentage_correct;
    int _user_ID;

    static vector<string> levels;
    static int ID_counter;
};

vector<string> UserProfile::levels = {
    "beginner", "intermediate", "advanced", "guru"
};
int UserProfile::ID_counter = 0;
