//
// Created by Alexander Schmid on 2020/11/07.
//

#include "Testing.h"
#include"CarBuild.h"

Testing::Testing()
{
    next = nullptr;
    windtunnelUses = 400;

}

void Testing::setNext(Testing *n)
{
    if(next!=nullptr)
    {
        next->setNext(n);
    }
    else
    {
        next = n;
    }

}

void Testing::testComponent(CarBuild* i)
{
}