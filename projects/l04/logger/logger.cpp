#include <fstream>
#include <cstring>
#include <ctime>
#include <sstream>
#include "logger.hpp"

logger::logger()
{
    time_t now = time(0);
    std::stringstream tmp;
    tmp << "log " << ctime(&now) << ".txt";
    this->logfile.open("log.txt");
    this->logfile << "Init program...\n";
}

logger::~logger()
{
}

int logger::log(const char *msg)
{
    if (this->level > 0x0001)
    {
        time_t now = time(0);

        std::stringstream tmp;
        tmp << ctime(&now) << " =>\t" << msg;

        this->logfile << tmp.str();

        return 1;
    }
    return 0;
}
