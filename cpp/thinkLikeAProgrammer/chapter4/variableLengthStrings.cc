#include<iostream>
using namespace std;
// string manipulation using arrays of chars
typedef char* arrayString;


//length finds the length of a given arrayString string
// input: string
// output: int

int length(const arrayString& s){
    // initiate length variable
    int length = 0;
    // loop over the string until null guard
    while(s[length] != 0){
        // increment the length variable
        length++;
    }
    //return the length
    return length;
}

//append adds a character to end of string
//input: character, arrayString
//output: side effect change the passed in string

void append(char newChar, arrayString& s){
    // get length of s
    int count = length(s);
    // allocated a new string with size plus one (need two for termination)
    arrayString newString = new char[count + 2];
    // loop through the original array and populate the new string
    for(int i=0;i<count;i++)newString[i] = s[i];

    // add new char to the last position
    newString[count] = newChar;
    newString[count + 1] = 0;

    // deallocate memory of old string
    delete[] s;
    // point the pointer to the new string
    s = newString;
    }


//concatenate takes two strings, adds the second onto the end of the first
//input: arrayString, arrayString
//output: side effect; change the memory address of the first string to new string
void concatenate(arrayString& a, const arrayString& b){
    // get length of a and b 
    int lenA = length(a);
    int lenB = length(b);
    int sum = lenA + lenB;

    // create a new arrayString of length a + b
    arrayString cat = new char[sum + 1];
    // loop through a and loop through b
    for(int i=0;i<lenA;i++){
        cat[i] = a[i];
    }
    for(int i=0;i<lenB;i++){
        cat[i + lenA] = b[i];
    }
    // add a zero to the end
    cat[sum] = 0;
    // deallocate memory of a
    delete[] a;
    // point pointer to new string
    a = cat;
}

//characterAt takes a string and a number and zero indexes using that number
//input: arrayString, int
//output: char
char characterAt(arrayString s, int index){
    // index the string 
    // return the char
    return s[index];
     }


// substring is a routine that takes in parameters to return a substring 
// input: arrayString, start position, length of substring
// output: pointer to new substring arrayString

arrayString substring ( const arrayString& original, int start, int length){
    // make a new arrayString
    arrayString copy = new char[length];
    // loop over original and copy from the start index for length amount of times
    for(int i= start; i < start + length; i++){
        // copy over 
        copy[i - start] = original[i];
    }
    copy[length] = 0;

    return copy;
}

// appendTester
void appendTester(){
    // array a
    arrayString a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] ='t'; a[4] = 0;
    append('!', a);
    cout << a << "\n";

    // array b
    arrayString b = new char[1];
    b[0] = 0;
    append('!', b);
    cout << b << "\n";
}

// concatenateTester
void concatenateTester(){
    // array a and b
    arrayString a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] ='t'; a[4] = 0;

    arrayString b = new char[5];
    b[0] = 'b'; b[1] = 'e'; b[2] = 'd'; b[3] =0;

    // concatenate(a, b);
    // cout << a << "\n";
    
    // array where one is too small
    arrayString d = new char[5];
    d[0] = 0;

    concatenate(d, a);
    cout << d << "\n" << a <<"\n";
    cout << (void*) a << "\n" << (void*) d << "\n";
}

// testsubstring
void testSubstring (){
    arrayString test = new char[4];
    test[0] = 'h'; test[1] = 'i'; test[2] = 'i'; test[3] = 0;

    arrayString a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] ='t'; a[4] = 0;

    arrayString b = new char[1];
    b[0] = 0;

    cout << test << '\n';
    arrayString hi = substring(test, 0, 2);
    arrayString yo = substring(a, 1, 3);
    arrayString whassup = substring(b, 0, 0);
    cout << hi << ' ' << yo << ' ' << whassup;
}

int main(){
    // appendTester();
    // concatenateTester();
    testSubstring();

    return 0;
}
