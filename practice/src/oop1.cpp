#include <iostream>

struct Logger{
    virtual void LogMessage(char const * message) = 0;
    virtual ~Logger() = default;
};

struct ConsoleLogger final: Logger
{
    virtual void LogMessage(char const* message) override{
        std::cout << message << "\n";
    }

    ConsoleLogger* get(){
        return  this;
    }
};


int main(){
    ConsoleLogger logger{new ConsoleLogger() };
    // ConsoleLogger logger{std::make_unique<ConsoleLogger>()};

    Logger* logger_ptr{
        dynamic_cast<Logger *>(logger.get())
    };
    logger_ptr->LogMessage("Hello");
    return 0;
}