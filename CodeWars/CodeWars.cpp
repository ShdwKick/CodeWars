#include <iostream>
#include <list>
#include <regex>

using namespace std;


string ReverseString(string inputString)
{
    string reversedString;
    for (int i = inputString.length(); i > -1; i--)
    {
       reversedString.push_back(inputString[i]);
    }
    return reversedString;
}
string SplitStringAndReturnReversed(string inputString)
{
    inputString.push_back(' ');
    string revStr = inputString;
    string word;
    string revWord;
    int wrdLen = 0;

    for (int i = 0; i < inputString.length(); i++)
    {
        if (inputString[i] == ' ' || inputString[i]==inputString.back() && i < inputString.length() + 1)
        {
            word = inputString.substr(0,i);
            word.erase(remove(word.begin(),word.end(),' '));
            revWord = ReverseString(word);
            wrdLen = revWord.length();
            inputString.erase(0, i + 1);
            revStr = regex_replace(revStr, regex(word), revWord);
            i = 0;
        }
    }

    return revStr;
}
int SquareDigitsAndConcatThem(int n)
{
    list<int> digits;
    string str;

    while (n > 0)
    {
        digits.push_front(n % 10);
        n = n / 10;
    };

    for (auto x : digits)
    {
        x *= x;
        str.append(to_string(x));
    }

    //cout << str << "\n";
    

    return atoi(str.c_str());
}
int MakeNegative(int x)
{
    return (x<0 ? x: (x * (-1)));
}
int SunTwoLowestElem(vector <int> arr)
{
    sort(arr.begin(), arr.end());
    return arr.at(0)+arr.at(1);
}
bool IsPrime(int num)
{
    int x = 1;
    if (num > 1)
    {
        for (int i = 1; i <= num; i++)
        {
            if ((num % i) == 0)
            {
                x++;
            }
        }
    }
    return ((x > 2 ) ? true : false);
}


int main()
{
#pragma region Kata1-6
#pragma region Kata1
    /* Kata 1
    Complete the function that accepts a string parameter, and reverses each word in the string.All spaces in the string should be retained.

    Examples
         "This is an example!" ==> "sihT si na !elpmaxe"
         "double  spaces" ==> "elbuod  secaps"*/

    /*cout << SplitStringAndReturnReversed("This  is an example!") << "\n";
    cout << SplitStringAndReturnReversed("double  spaces") << "\n";
    cout << SplitStringAndReturnReversed("") << "\n";*/
#pragma endregion

#pragma region Kata2
    /* Kata 2
   Complete the solution so that it reverses the string passed into it.

        'world'  =>  'dlrow'
        'word'   =>  'drow'*/

    /*cout << ReverseString("world") << "\n";
    cout << ReverseString("rat") << "\n";*/

#pragma endregion
    
#pragma region Kata3
    /* Kata 3
    Welcome.In this kata, you are asked to square every digit of a numberand concatenate them.

        For example, if we run 9119 through the function, 811181 will come out, because 92 is 81 and 12 is 1.

        Note: The function accepts an integer and returns an integer*/

    /*cout << SquareDigitsAndConcatThem(3753) << "\n";
    cout << SquareDigitsAndConcatThem(9119) << "\n";*/
#pragma endregion

//here
#pragma region Kata4
   /* Given a list of digits, return the smallest number that could be formed from these digits, using the digits only once(ignore duplicates).

        Notes:
    Only positive integers will be passed to the function(> 0), no negatives or zeros.
        Input >> Output Examples
        minValue({ 1, 3, 1 }) ==> return (13)
        Explanation :
        (13) is the minimum number could be formed from {
        1, 3, 1
    }, Without duplications*/

#pragma endregion

#pragma region Kata5
            /* In this simple assignment you are given a number and have to make it negative. But maybe the number is already negative?

            Examples
            makeNegative(1);  // return -1
            makeNegative(-5); // return -5
            makeNegative(0);  // return 0
            Notes
            The number can be negative already, in which case no change is required.
            Zero (0) is not checked for any specific sign. Negative zeros make no mathematical sense.*/

    /*cout << MakeNegative(-5) << "\n";
    cout << MakeNegative(1) << "\n";
    cout << MakeNegative(0) << "\n";
    cout << MakeNegative(5) << "\n";*/

#pragma endregion

#pragma region Kata6
    /*Create a function that returns the sum of the two lowest positive numbers given an array of minimum 4 positive integers.No floats or non - positive integers will be passed.

        For example, when an array is passed like[19, 5, 42, 2, 77], the output should be 7.

        [10, 343445353, 3453445, 3453545353453] should return 3453455.*/


    //cout << SunTwoLowestElem({ 19, 5, 42, 2, 77 });

#pragma endregion
#pragma endregion

#pragma region Kata7-12

#pragma region Kata7
    /*Define a function that takes an integer argumentand returns a logical value true or false depending on if the integer is a prime.

        Per Wikipedia, a prime number(or a prime) is a natural number greater than 1 that has no positive divisors other than 1 and itself.

        Requirements
        You can assume you will be given an integer input.
        You can not assume that the integer will be only positive.You may be given negative numbers as well(or 0).
        NOTE on performance : There are no fancy optimizations required, but still the most trivial solutions might time out.Numbers go up to 2 ^ 31 (or similar, depending on language).Looping all the way up to n, or n / 2, will be too slow.
        Example
        */
        //is_prime(1)  /* false */
        //is_prime(2)  /* true  */
        //is_prime(-1) /* false */
    
    /*cout << IsPrime(1) << "\n";
    cout << IsPrime(3) << "\n";
    cout << IsPrime(5) << "\n";*/
#pragma endregion



#pragma endregion
}

