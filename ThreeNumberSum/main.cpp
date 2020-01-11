//
//  main.cpp
//  ThreeNumberSum
//
//  Created by adeeb mohammed on 06/01/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

// program for finding the set of three numbers which forms a sum

// problem statement:-
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
// this is a left right pointer business
// array related sum finding easy technique
// Step 1:-> sort the array in the ascending order
// step 2:-> keep two pointers left and right
// step 3:- iterate the array to n -2
// step 4 :- on each element place the left pointer as the next element and
// right most element as the right most pointer
// left + right + key element = sum of the array
//  if the obtained sum is greater than the actual sum decrement right pointer
// if the obtained sum is smaller than the actua; incremenebt the left pointer
// once we found sum, the next jump the two pointers same time.
// if one pointer crosses another just stop iterating
// time complexity is 0(n2) and space complexity is o(1)

std::vector<std::vector<int>> threeNumberSum(std::vector<int> array, int targetSum) {
    std::vector<std::vector<int>> resultVector;
    auto inputSize = array.size();
    auto leftPointer = 0;
    auto rightPointer = inputSize - 1;
    auto obtainedSum = 0;
    
    // sort the array in ascending order.
    std::sort(array.begin(),array.end());
    
    for(auto i = 0 ; i <  inputSize - 2; i++){
        rightPointer = inputSize - 1; // resetting
        leftPointer = i + 1;// reseting pointers
        while(leftPointer < rightPointer){
            obtainedSum = array.at(i) + array.at(leftPointer) + array.at(rightPointer);
            if(obtainedSum == targetSum){
                resultVector.push_back({array.at(i),array.at(leftPointer),array.at(rightPointer)});
                leftPointer++;
                rightPointer--;
            }else if(obtainedSum < targetSum){
                leftPointer++;
            }else if(obtainedSum > targetSum){
                rightPointer--;
            }
        }
    }
    return resultVector;
}

int main(int argc, const char * argv[]) {
  auto result =  threeNumberSum({5,4,3,2,1,3,9,11}, 6);
    
    for (auto it : result) {
        std::cout << "Triplet ";
       for (auto it1 : it) {
            std::cout << it1 << " ";
        }
        std::cout << std::endl;
    }
  return 0;
}
