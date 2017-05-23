#define prog 2
#if(prog == 1)

//Exercise 1
//
//* write a bubble sort function that takes two parameters
//bubbleSort(vector, function pointer)
//function pointer : bool(*compare)(int x, int y);
//
//*write two boolean functions to compare two integers :
//- compare_gt(int a, int b) : returns true if a is greater than b
//- compare_lt(int a, int b) : returns true if a is less than b
//
//* pass the boolean functions as callbacks to test bubbleSort function
//- one test should sort vector in non - increasing order
//- one test should sort vector in non - decreasing order

#include <iostream>
#include <iterator>
#include <vector>
using namespace std;


bool compare_gt(int a, int b) { return (a > b) ? true : false; }
bool compare_lt(int a, int b) {return (a < b) ? true : false; }

void bubbleSortFn(vector<int> &vec, bool(*compareFn)(int x, int y));

int main() {
    
    cout << "Booblay sorting...\n";
    
    vector<int> myVec;
    
    for (int i = 0; i < 10; i++)
        myVec.push_back(rand() % 50);
    
    cout << "Before sorting...\n";
    copy(myVec.begin(), myVec.end(), ostream_iterator<int>(cout, " "));
    
    cout << "\n\nSorted in non-increasing order...\n";
    bubbleSortFn(myVec, &compare_lt);
    copy(myVec.begin(), myVec.end(), ostream_iterator<int>(cout, " < "));
    
    cout << "\n\nSorted in non-decreasing order...\n";
    bubbleSortFn(myVec, &compare_gt);
    copy(myVec.begin(), myVec.end(), ostream_iterator<int>(cout, " > "));
    
    return 0;
}

void bubbleSortFn(vector<int> &vec, bool(*compareFn)(int x, int y)) {
    bool needNextPass = true;
    for (int k = 1; k < vec.size() && needNextPass; k++) {
        // vector may be sorted and next pass not needed
        needNextPass = false;
        for (int i = 0; i < vec.size() - k; i++)
        {
            if (compareFn(vec[i], vec[i + 1]))
            {
                // Swap list[i] with list[i + 1]
                int temp = vec[i]; 
                vec[i] = vec[i + 1]; 
                vec[i + 1] = temp; 
                
                needNextPass = true; // Next pass still needed 
            } 
        } 
    } 
}

#elif(prog == 2)

/*
 Create a functor for the generate algorithm to generate 
 into a vector of size 10, the first 10 numbers 
 in the Fibonacci sequence
 
 The functor generates a number based on two the previous 
 two numbers in the sequence. These two numbers must be 
 maintained as the “state” of your function object
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<iterator>

using namespace std;

class fibo
{
public:
    
    int operator()()
    {
        a = b;
        b = c;
        c = a + b;
        return c;
        
    }
private:
    int a = 0;
    int b = 1;
    int c;
    
};
int main()
{
    
    vector<int> myVec2(10);
    
    generate(myVec2.begin(), myVec2.end(), fibo());
    copy(myVec2.begin(), myVec2.end(), ostream_iterator<int>(cout, " "));
    
    return 0;
}

#endif
