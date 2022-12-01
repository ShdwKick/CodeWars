#include <iostream>
#include <list>
#include <regex>
#include <format>
#include <cstdio>
#include <string>
#include <cctype> 
#include <algorithm>
#include <map>


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
int SumTwoLowestElem(vector <int> arr)
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
bool FindStringInString(string str, string ending)
{
    return (ending.length()>0 ? ((str.find(ending,str.length()-ending.length())<str.length()) ? true : false) : true);
}
string delim_to_next_upper_char(char delim,string str)
{
    string str2;
    int pos = str.find(delim);
    str2.push_back((char)toupper((str[pos + 1])));
    str.replace(str.begin() + (pos + 1), str.begin() + (pos + 2), str2);
    str.erase(pos, 1);
    str2 = "";
    return str;
}
string to_camel_case(string str)
{
    char delim;

    while (str.find("-") != string::npos || str.find("_") != string::npos)
    {

        if (str.find("-") != string::npos)
        {
            str = delim_to_next_upper_char('-', str);
        }
        else if (str.find("_") != string::npos)
        {
            str = delim_to_next_upper_char('_',str);
        }
    }
    return str;
}
string createPhoneNumber(int arr[])
{
    char outString[50];
    sprintf_s(outString, "(%d%d%d) %d%d%d-%d%d%d%d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9]);
    return outString;
}
string cleanString(string str) 
{
    int pos = 0;
    while(str.find("#") != string::npos)
    {
        pos = str.find("#");
        if ((pos - 1) >= 0)
        {
            str.erase(pos - 1, 2);
        }
        else
        {
            str.erase(pos, 1);
        }
    }
    return str;
}

string intToRoman(int num)
{
    map<int, char> m{ {1000,'M'}, {500,'D'},{100,'C'},{50,'L'},{10,'X'},{5,'V'},{1,'I'} };
    int arr[7]{1000,500,100,50,10,5,1};
    string str = "";

    while (num > 0)
    {
         if (num >= 1000)
         {
            str.push_back('M');
            num -= 1000;
         }
         else if (num >= 500)
         {
            str.push_back('D');
            num -= 500;
         }
        
    }
    return str;
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

#pragma region Kata4
   /*Assume "#" is like a backspace in string.This means that string "a#bc#d" actually is "bd"

        Your task is to process a string with "#" symbols.

        Examples
        "abc#d##c" ==> "ac"
        "abc##d######" ==> ""
        "#######" ==> ""
        "" ==> ""
    */

    /*
    cout << cleanString("abc#d##c") << "\n";
    cout << cleanString("abc##d######") << "\n";
    cout << cleanString("#######") << "\n";
    */

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


    //cout << SumTwoLowestElem({ 19, 5, 42, 2, 77 });

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


#pragma region Kata8
        //Complete the solution so that it returns true if the first argument(string) passed in ends with the 2nd argument(also a string).
        //
        //Examples:
        //
        //solution('abc', 'bc') // returns true
        //solution('abc', 'd') // returns false
;
       /* cout << FindStringInString("abc","bc") << "\n";
        cout << FindStringInString("abc", "d") << "\n";
        cout << FindStringInString("abcde", "cde") << "\n";
        cout << FindStringInString("abcde", "abc") << "\n";
        cout << FindStringInString("abc", "") << "\n";*/

#pragma endregion

#pragma region Kata9

        //Write a function that accepts an array of 10 integers(between 0 and 9), that returns a string of those numbers in the form of a phone number.
       //int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
       // std::cout << __cplusplus << std::endl;
       // cout << createPhoneNumber(arr) << "\n";// => returns "(123) 456-7890"
#pragma endregion

#pragma region Kata10
    
    /*Complete the method / function so that it converts dash / underscore delimited words into camel casing.The first word within the output should be capitalized only if the original word was capitalized(known as Upper Camel Case, also often referred to as Pascal case).

    Examples
    "the-stealth-warrior" gets converted to "theStealthWarrior"
    "The_Stealth_Warrior" gets converted to "TheStealthWarrior"*/
    /*  cout << to_camel_case("") << "\n";
        cout << to_camel_case("the_stealth_warrior") << "\n";
        cout << to_camel_case("The-Stealth-Warrior") << "\n";
        cout << to_camel_case("A-B-C") << "\n";
    */

#pragma endregion

#pragma region Kata11

    /*Complete the method / function so that it converts dash / underscore delimited words into camel casing.The first word within the output should be capitalized only if the original word was capitalized(known as Upper Camel Case, also often referred to as Pascal case).

    Examples
    "the-stealth-warrior" gets converted to "theStealthWarrior"
    "The_Stealth_Warrior" gets converted to "TheStealthWarrior"*/
    /*  cout << to_camel_case("") << "\n";
        cout << to_camel_case("the_stealth_warrior") << "\n";
        cout << to_camel_case("The-Stealth-Warrior") << "\n";
        cout << to_camel_case("A-B-C") << "\n";
    */

#pragma endregion


#pragma region Kata12
    /*
    Create a function taking a positive integer as its parameterand returning a string containing the Roman Numeral representation of that integer.

    Modern Roman numerals are written by expressing each digit separately starting with the left most digitand skipping any digit with a value of zero.In Roman numerals 1990 is rendered : 1000 = M, 900 = CM, 90 = XC; resulting in MCMXC. 2008 is written as 2000 = MM, 8 = VIII; or MMVIII. 1666 uses each Roman symbol in descending order : MDCLXVI.

    Example :

        solution(1000); // should return "M"
    Help:

    Symbol    Value
    I          1
    V          5
    X          10
    L          50
    C          100
    D          500
    M          1, 000
    Remember that there can't be more than 3 identical symbols in a row.

    More about roman numerals - http://en.wikipedia.org/wiki/Roman_numerals
    */
    cout << intToRoman(1500) << "\n";

#pragma endregion

#pragma endregion

}

