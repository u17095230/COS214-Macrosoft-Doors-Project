#include "CheckeredFlag.h"

/*CheckeredFlag::CheckeredFlag(Race* subject)
{
	this->subject = subject;
	this->subject->attach(this);
}*/

void CheckeredFlag::raiseFlag()
{
    if (!flagRaised)
    {
        flagRaised = true;

        cout<<endl;
        cout<<"________________________________________"<<endl;
        cout << "Checkered flag raised" << endl;
        cout<<"________________________________________"<<endl;
        cout<<endl;

    }
}

void CheckeredFlag::lowerFlag()
{
    if (flagRaised)
    {
        flagRaised = false;

        cout<<endl;
        cout<<"________________________________________"<<endl;
        cout << "Checkered flag lowered" << endl;
        cout<<"________________________________________"<<endl;
        cout<<endl;

    }
}

void CheckeredFlag::update()
{
    flagRaised = false;
    if (subject->getRaceState() == "Final Lap")
    {
        raiseFlag();
        cout << "Lap Number: " << subject->getCurrentLap() << ". Final lap!" << endl;

        lowerFlag();
        subject->endRace();
    }
}

