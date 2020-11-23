// MachineLearning.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "DataPoint.h"
#include "KNearestNeighbors.h"

int main()
{
    // KNearestNeighbours Test.
    DataPoint P1;
    P1.SetClassification(1);
    P1.InsertData(2, 1.0f, 2.0f);

    DataPoint P2;
    P2.SetClassification(1);
    P2.InsertData(2, 0.0f, 0.0f);

    DataPoint P3;
    P3.SetClassification(1);
    P3.InsertData(2, 1.0f, 1.0f);

    DataPoint P4;
    P4.SetClassification(1);
    P4.InsertData(2, 1.0f, 2.0f);

    DataPoint P5;
    P5.SetClassification(2);
    P5.InsertData(2, 3.0f, 1.0f);

    DataPoint P6;
    P6.SetClassification(2);
    P6.InsertData(2, 2.0f, 1.0f);

    DataPoint P7;
    P7.SetClassification(2);
    P7.InsertData(2, 2.0f, 2.0f);

    DataPoint TestingPoint;
    TestingPoint.InsertData(2, 3.0f, 2.0f);

    KNearestNeighbors KNeighbors;
    KNeighbors.AddData(P1);
    KNeighbors.AddData(P2);
    KNeighbors.AddData(P3);
    KNeighbors.AddData(P4);
    KNeighbors.AddData(P5);
    KNeighbors.AddData(P6);
    KNeighbors.AddData(P7);

    const int Classification = KNeighbors.Evaluate(TestingPoint, 3);

    std::cout << "Classification is : " << Classification << std::endl;
}