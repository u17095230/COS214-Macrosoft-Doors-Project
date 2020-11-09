#include <iostream>
#include"FormulaOneTeam.h"
#include<iostream>
#include<string>

using namespace std;

int main() {


    //Add a bypass

    //Begin
    int numSeasons = 0;

    cout<<"Please enter the number of seasons you want your team to run for:"<<endl;
    cin>>numSeasons;


    FormulaOneTeam* fOneTeam = new FormulaOneTeam(numSeasons);



    fOneTeam->runChampionships();





}
