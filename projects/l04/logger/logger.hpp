#include <fstream>
#include <cstring>
#include <ctime>
#include <sstream>

class logger
{
private:
    int level = 0x1111;
    std::ofstream logfile;

public:

    logger();
    ~logger();
    int log(const char *msg);
};