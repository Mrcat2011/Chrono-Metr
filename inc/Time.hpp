#ifndef TIME_H_
#define TIME_H_

#include <ctime>
#include <string>

class Time {    
    private:
        time_t now;
    public:
        void Update();
        std::string getTime();

};

#endif //!TIME_H_