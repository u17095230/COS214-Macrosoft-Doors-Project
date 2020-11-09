#include "RedFlag.h"

/*RedFlag::RedFlag(Race* subject)
{
	this->subject = subject;
	this->subject->attach(this);
}*/

void RedFlag::raiseFlag()
{
    if (!flagRaised)
    {
        flagRaised = true;
        cout<<endl;
        cout<<"________________________________________"<<endl;
        cout << "Red flag raised" << endl;
        cout<<"________________________________________"<<endl;
        cout<<endl;
    }
}

void RedFlag::lowerFlag()
{
    if (flagRaised)
    {
        flagRaised = false;
        cout<<endl;
        cout<<"________________________________________"<<endl;
        cout << "Red flag lowered" << endl;
        cout<<"________________________________________"<<endl;
        cout<<endl;

    }
}

void RedFlag::update()
{
    flagRaised = false;
    if (subject->getRaceState() == "Extremely dangerous")
    {
        raiseFlag();
        cout << "Lap Number: " << subject->getCurrentLap() << ". Race momentarily paused." << endl;
        lowerFlag();

    }
}

