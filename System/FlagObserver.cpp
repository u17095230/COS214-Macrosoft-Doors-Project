#include "FlagObserver.h"

void FlagObserver::changeFlagState()
{
    if (flagRaised)
        lowerFlag();
    else
        raiseFlag();
}
FlagObserver::FlagObserver() {

}
FlagObserver::FlagObserver(Race *subject) {
    this->subject = subject;
    subject->attach(this);

}

void FlagObserver::update() {

}

FlagObserver::~FlagObserver() {
    delete subject;
}
