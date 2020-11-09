#include "YellowFlag.h"

/*YellowFlag::YellowFlag(Race subject)
{
	this.subject = subject;
	this.subject.attach(this);
}*/

void YellowFlag::raiseFlag()
{
    if (!flagRaised)
    {
        flagRaised = true;
        cout<<endl;
        cout<<"________________________________________"<<endl;
        cout << "Yellow flag raised" << endl;
        cout<<"________________________________________"<<endl;
        cout<<endl;

    }
}

void YellowFlag::lowerFlag()
{
    if (flagRaised)
    {
        flagRaised = false;

        cout<<endl;
        cout<<"________________________________________"<<endl;
        cout << "Yellow flag lowered" << endl;
        cout<<"________________________________________"<<endl;
        cout<<endl;

    }
}

void YellowFlag::update()
{
    flagRaised = false;
    if (subject->getRaceState() == "Hazardous")
    {
        raiseFlag();
        cout << "Lap Number: " << subject->getCurrentLap() << ". Cars advised to drive with caution" << endl;
        lowerFlag();

    }
}
