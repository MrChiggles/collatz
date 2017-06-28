//
//  main.cpp
//  mathTest
//
//  Created by Wesley Schrauwen on 2017/06/27.
//  Copyright © 2017 Wesley. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 Performs the Collatz sequence.
 The Collatz sequence performs two seperate operations based on a number being even or odd.
 If odd the number is tripled and one is added, if not it is halved.
 This process is repeated until one is reached.
 Convergence to one has been proven for all real numbers above zero and less than 2^60.
 */
class Collatz {
private:
    //    Determines if a number is even
    bool isEven(long num){
        return num % 2 == 0;
    };
    
    //    Returns the even Collatz operation
    long long decreaseInput(long num){
        return num / 2;
    }
    
    //    Returns the odd Collatz operation
    long long increaseInput(long num){
        return num * 3 + 1;
    };
    
public:
    //    Returns the track count of a Collatz sequence on a given number.
    int getTrackCount(long num){
        
        //        Prevents non-positive inputs
        if (num <= 1){
            return 1;
        }
        
        int trackCount = 1;
        
        //        Loops until we have converged on one
        while (num != 1){
            
            if (isEven(num)){
                
                num = decreaseInput(num);
                
            } else {
                
                num = increaseInput(num);
                
            }
            
            trackCount += 1;
            
        }
        
        return trackCount;
        
    };
};


int main(int argc, const char * argv[]) {
    
    if (argc < 2) {
        cout << "Insufficient Parameters" << endl << "Please enter a positive integer." << endl;
        return 1;
    }  else if (std::string(argv[1]) == "-h" || std::string(argv[1]) == "-help"){
        std::cout << std::endl << "The Collatz Sequence is an interesting mathematical anomaly for real whole numbers and has two seperate operations depending on a numbers state. " << std::endl << "If a number should be even then one should halve it. If odd then one should triple it and add one. After repeating this process n times it appears that a number should converge to 1 however this has not yet been proven." << std::endl << std::endl << "To determine how many operations one would undergoe please enter a whole positive number less than " << LONG_MAX << std::endl << std::endl;
        return 1;
    }
    
    Collatz collatz;
    
    cout << "Parameter: " << argv[1] << endl;
    
    long input;
    
    try {
        input = stol(argv[1]);
    } catch (exception) {
        cout << "There was an error with your input. " << endl << " Either it was too large or was not a valid number." << endl << "Please try again with a non-zero positive number less than " << LONG_MAX << endl;
        return 1;
    }
    
    if (input <= 0) {
        cout << "Input Error. Cannot input Zero or Negative Numbers" << endl << " Either it was too large or was not a valid number." << endl << "Please try again with a non-zero positive number less than " << LONG_MAX << endl;
        return 1;
    }
    
    int trackCount = collatz.getTrackCount(input);
    
    cout << "Track Count: " << trackCount << endl;
    
    
    return 0;
}
