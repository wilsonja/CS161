/****************************************************************
 * Author: Jacob Wilson
 * Date: 8/1/15
 * Description: Assignment 6 (Find Mode). A function is used to
 * determine the modal numbers (those that appear most often) in
 * a provided array. A vector containing the modal numbers
 * sorted in ascending order is returned.
 ****************************************************************/

#include <iostream>
#include <vector>               // required for use of vectors
#include <algorithm>            // required for use of sort function

int main()
{
    int testArray[6] = {1342, 1342, 34, 34, 1342, 6};          // array used to test findMode function
    int arraySize = 6;                              // size of array
    
    // findMode function prototype: accepts an array of integers and an integer representing
    // the array size as arguments. Returns an integer vector which will contain the modal
    // numbers.
    std::vector<int> findMode(int [], int);
    
    std::vector<int> displayVector = findMode(testArray, arraySize);    // vector to display results
    
    for(int index = 0; index < displayVector.size(); index++)           // loop using test the vector for
    {                                                                   // displaying mode vector contents
        std::cout << displayVector[index] << std::endl;
    }
    
    return 0;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                  findMode                                         *
 * The findMode function accepts an array of integers and an integer representing    *
 * the array size as arguments. It then loops through the array to determine the     *
 * frequency of numbers within the array. When the frequency of a number occurence   *
 * is determined to be the highest, the value is added to the mode vector. If two    *
 * or more numbers have the same frequency, an additional loop is used to determine  *
 * which numbers are already present within the mode vector. If a number is present, *
 * it isn't added, if it is not present, it will be added. The vector is then sorted *
 * in ascending order and returned to the main function.                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

std::vector<int> findMode(int array[], int size)        // findMode function header; returns a vector
{
    std::vector<int> modeVect;                          // this is the final vector containing the mode
    
    int highestFreq = 0;            // highestFreq is intialized to 0 so that the function can be used
                                    // to determine the actual highest frequency (in case of no mode)
    
    /* the first loop will determine the number that will be compared
     * to all other numbers in the second loop */
    for(int index = 0; index < size; index++)
    {
        /* the second loop compares the number determined by the first loop,
         * to all numbers present in the array */
        int frequency = 0;
        for(int count = 0; count < size; count++)
        {
            if(array[index] == array[count])        // if a number exists more than once, the frequency counter is increased
                frequency++;
        }
        if(frequency > highestFreq)                 // if the current frequency exceeds the highest frequency,
        {                                           // the current number is the mode, the vector is cleared,
            modeVect.clear();                       // and the current number is added to the mode vector.
            modeVect.push_back(array[index]);       // a new highestFreq is set for use with following loops.
            highestFreq = frequency;
        }
        else if(frequency == highestFreq)           // if two numbers are present the same number of times,
        {                                           // more than one mode exists.
            
            /* a loop will check for the presence of the current array value in the
             * mode vector. a bool variable is initialized to false and will indicate
             * true if the array value is present in the vector. if it is not present,
             * the bool variable will remain false and the array value will be added
             * to the mode vector. */
            bool inVector = false;
            for(int modeIndex = 0; modeIndex < modeVect.size(); modeIndex++)
            {
                if(modeVect[modeIndex] == array[index])
                    inVector = true;
            }
            if(!inVector)
                modeVect.push_back(array[index]);
        }
    }
    
    std::sort(modeVect.begin(), modeVect.end());            // use of the sort function to sort the mode
                                                            // vector from smallest to largest.
    return modeVect;
}
