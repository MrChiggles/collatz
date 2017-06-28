//
//  main.cpp
//  Program_2
//
//  Created by Wesley Schrauwen on 2017/06/27.
//  Copyright © 2017 Wesley. All rights reserved.
//

#include <iostream>

/*
 Performs the Collatz sequence.
 Returns the total track count of a inputs sequence.
 The Collatz sequence performs two seperate operations based on a number being even or odd.
 If odd the number is tripled and one is added, if not it is halved.
 This process is repeated until one is reached.
 Convergence to one has been proven for all real numbers above zero and less than 2^60.
 */
u_long collatzTrackCount(u_long num){
    return num <= 1 ? 1 : 1 + (num % 2 ? collatzTrackCount(num * 3 + 1) : collatzTrackCount(num >> 1));
};

int main(int argc, const char * argv[]) {
    
    
    
    if (argc < 2) {
        std::cout << "Insufficient Parameters" << std::endl << "Please enter a positive integer." << std::endl;
        return 1;
    } else if (std::string(argv[1]) == "-h" || std::string(argv[1]) == "-help"){
        std::cout << std::endl << "The Collatz Sequence is an interesting mathematical anomaly for real whole numbers and has two seperate operations depending on a numbers state. " << std::endl << "If a number should be even then one should halve it. If odd then one should triple it and add one. After repeating this process n times it appears that a number should converge to 1 however this has not yet been proven." << std::endl << std::endl << "To determine how many operations one would undergoe please enter a whole positive number less than " << ULONG_MAX << std::endl << std::endl;
        return 1;
    }
    
    std::cout << "Parameter: " << argv[1] << std::endl;
    
    u_long input;
    
    try {
        input = std::stoll(argv[1]);
    } catch (std::exception) {
        std::cout << "There was an error with your input. " << std::endl << " Either it was too large or was not a valid number." << std::endl << "Please try again with a non-zero positive number less than " << ULONG_MAX << std::endl;
        return 1;
    }
    
    if (input <= 0) {
        std::cout << "Input Error. Cannot input Zero or Negative Numbers" << std::endl << " Either it was too large or was not a valid number." << std::endl << "Please try again with a non-zero positive number less than " << ULONG_MAX << std::endl;
        return 1;
    }
    
    
    std::cout << "Count: " << collatzTrackCount(input) << std::endl;
    
    return 0;
}
