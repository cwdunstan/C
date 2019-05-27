#ifndef TESTMOVER_H
#define TESTMOVER_H

#include "gamestage.h"

class TestMover : public GameStage {
public:
    enum class Status {
        Running,
        Passed,
        Failed
    };

    TestMover(std::string name);
    virtual ~TestMover() = 0;

    /**
     * @brief fail Sets the test's status to Failed
     */
    void fail();
    Status getStatus();
    std::string getName();

protected:
    Status status;

private:
    std::string name;
};

#endif // TESTMOVER_H
