#include <string>
using namespace std;

class ProgramInfo
{
public:
    static int tests_passed() { return _tests_passed; }
    static int tests_run() { return _tests_run; }
    static int version_number() { return _version_number; }
    static string version_stamp() { return _version_stamp; }
    static string program_name() { return _program_name; }
    static void set_name(string name) { _program_name = name; }
    static void set_stamp(string stamp) { _version_stamp = stamp; }
    static void set_version(int num) { _version_number = num; }
    static void reset_run_time() { _tests_run = 0; }
    static void add_run_time() { ++_tests_run; }
    static void reset_passed_time() { _tests_passed = 0; }
    static void add_passed_time() { ++_tests_passed; }
private:
    static string _program_name;
    static string _version_stamp;
    static int _version_number;
    static int _tests_run;
    static int _tests_passed;
};

string ProgramInfo::_program_name;
string ProgramInfo::_version_stamp;
int ProgramInfo::_version_number;
int ProgramInfo::_tests_run;
int ProgramInfo::_tests_passed;