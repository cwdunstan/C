#include "testmover.h"

TestMover::TestMover(std::string name) : status(Status::Running), name(name) {

}

TestMover::~TestMover() {

}

void TestMover::fail() {
    status = Status::Failed;
}

TestMover::Status TestMover::getStatus() {
    return status;
}

std::string TestMover::getName() {
    return name;
}
