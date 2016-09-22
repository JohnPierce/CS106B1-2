//
//  main.cpp
//  CS106B-ProblemSet1-2
//
//  Created by John Pierce on 9/18/16.
//  Copyright © 2016 JohnPierce. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>


using std::string;

// Declaration of a very simple structure that really just defines the data to be presented
struct GradeScores {
    
    int minGrade;
    int maxGrade;
    double avgGrade;
    
};

// Function originally written to pass the open file; however changed it to pass the string in order to control file operations within the function
GradeScores readFileReturnGradeScores(std::string gradeFileIn)
{
    std::ifstream gradeFile(gradeFileIn);  // open the file from the string path of the file
  
    GradeScores myScores;                  // declare GradeScores struct we will return
    myScores.minGrade = 100;                // Assignment says max value 100, min value 0; therefore used this information to simplify for loop
    myScores.maxGrade = 0;                  // Same as above
    int currentVal;
    myScores.avgGrade=0;                    // Just setting to a value
    int count = 0;
    int sumScores = 0;                      // Just setting to a value
    
    //The following code reads in all the data
    //Assumptions taken: all data is type integer, data is clean. Currently no error handling code
    //While loop does a continues update on min and max values
    while ( gradeFile >> currentVal )
    {
        if (myScores.maxGrade < currentVal)
            myScores.maxGrade = currentVal;
        if (myScores.minGrade > currentVal)
            myScores.minGrade = currentVal;
        ++count;
        sumScores = sumScores + currentVal;
    }
    myScores.avgGrade = sumScores/count; //Calculation of the average grade
    
    
    gradeFile.close(); // keep things clean, close the file
    
    return myScores; // return the data
    
}

// Using the below function for debug purposes since I was not able to establish readFileReturnGradeScores in main
// The real problem ended up being that data was not being passed correctly to readFileReturnGradeScores

void bogusFunction ( int foo)
{
    foo = 5;
    
}

//Another function used for debug purposes to make sure the struct was okay

GradeScores dontDoAnything(int bogusNumber)
{
    bogusNumber=5;
    GradeScores henry;
    henry.maxGrade = 75;
    henry.minGrade = 60;
    henry.avgGrade = 68.5;
    return henry;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    GradeScores myGradeScores;
    
    std::cout << "Hello, World!\n";
    
    //declare the file to be used for the grades.
    
    std::ofstream gradeFileOut("/Users/johnp/Desktop/ListProject/CS106B-SessionHandout1/CS106b-ProblemSet1-2/Grades.txt");
    std::string gradeFileIn= "/Users/johnp/Desktop/ListProject/CS106B-SessionHandout1/CS106b-ProblemSet1-2/Grades.txt";
    
    int a=0;  // integer will loop on
    int random;
    
    srand( 365 ); // seeding the random number generator. Next time use time function, didn't this time due to difference in type when using time(NULL)
    
  //Create the grade file with a bunch of random data
    
    for ( a=0; a<100; ++a)
    {
        random = rand() % 100 + 1;
        gradeFileOut << random << "\n";
        std::cout << random << "\n";
        
    }
    gradeFileOut.close(); // closing the grade file
    
    bogusFunction(8);
    dontDoAnything(12);
    
    
    myGradeScores = readFileReturnGradeScores(gradeFileIn);
    
    std::cout << "\n" << "Average Grade  " << myGradeScores.avgGrade << "  Max Grade  " << myGradeScores.maxGrade << "  Min Grade  " << myGradeScores.minGrade << "\n";
    
    
    
    return 0;
}
