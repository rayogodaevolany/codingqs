#include <iostream>


//I feel like I was supposed to do this with the linkedlist version of the string

using namespace std;

class String {
    private:
        typedef char* arrayString;
    public:
        String();
        String(const String & original);
        String(char str[], size_t size);
        ~String();
        String& operator=(const String & rhs);
        arrayString getString();
        void setString(char str[], size_t size);
        void append(char newChar);
        void concatenate(const arrayString& b);
        char characterAt(int index);
    private:
        arrayString _head;
        int length(const arrayString& s);
        void deleteString(arrayString head);
        arrayString copiedString(const arrayString& original);
};

String::String(){
    // new string that terminates in 0 still.
    // I don't know if that works well actually
    _head = new char[1];
    _head[0] = 0;
}

String::String(const String & original){
    _head = copiedString(original._head);
}

String::String(char str[], size_t size){
    _head = new char[size + 1];
    // copy all elements
    for(int i = 0;i < size; i++){
        _head[i] = str[i];
    }
    // should be size for the right index of the last place
    _head[size] = 0;
}

String::arrayString String::getString(){
    return _head;
}

String::~String(){
    deleteString(_head);
}


String& String::operator=(const String & rhs){
    if(this != &rhs){
        deleteString(_head);
        _head = copiedString(rhs._head);
    }

    return *this;
}

void String::setString(char str[], size_t size){
    _head = new char[size + 1];
    // copy all elements
    for(int i = 0;i < size; i++){
        _head[i] = str[i];
    }
    // should be size for the right index of the last place
    _head[size] = 0;
}

//length finds the length of a given arrayString string
// input: string
// output: int

int String::length(const arrayString& s){
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

void String::append(char newChar){
    // get length of s
    int count = length(_head);
    // allocated a new string with size plus one (need two for termination)
    arrayString newString = new char[count + 2];
    // loop through the original array and populate the new string
    for(int i=0;i<count;i++)newString[i] = _head[i];

    // add new char to the last position
    newString[count] = newChar;
    newString[count + 1] = 0;

    // deallocate memory of old string
    delete[] _head;
    // point the pointer to the new string
    _head = newString;
    }


//concatenate takes two strings, adds the second onto the end of the first
//input: arrayString, arrayString
//output: side effect; change the memory address of the first string to new string
void String::concatenate(const arrayString& b){
    // get length of a and b 
    int lenA = length(_head);
    int lenB = length(b);
    int sum = lenA + lenB;

    // create a new arrayString of length a + b
    arrayString cat = new char[sum + 1];
    // loop through a and loop through b
    for(int i=0;i<lenA;i++){
        cat[i] = _head[i];
    }
    for(int i=0;i<lenB;i++){
        cat[i + lenA] = b[i];
    }
    // add a zero to the end
    cat[sum] = 0;
    // deallocate memory of a
    deleteString(_head);
    // point pointer to new string
    _head = cat;
}

//characterAt takes a string and a number and zero indexes using that number
//input: arrayString, int
//output: char
char String::characterAt(int index){
    // index the string 
    // return the char
    return _head[index];
     }

void String::deleteString(arrayString head){
    // remove string
    delete[] head;
    head = NULL;
}

String::arrayString String::copiedString(const arrayString& original){
    int len;
    len = length(original);
    arrayString copy = new char[len];
    for(int i = 0;i < len; i++) copy[i] = original[i];
    return copy;
}

void test (String hi){
    cout << hi.getString();
}

int main(){
    String str;
    str.append('h');
    str.append('i');

    char arr[3] = {'u','h','u'};

    String second(arr, 3);
    cout << str.getString() << " "<< second.getString()<< " "<< second.characterAt(0) << endl;

    char world[5] = {'w','o','r','l','d'};
    second.setString(world, 5);
    cout << str.getString() << endl;

    str = second;

    str.concatenate(second.getString());
    cout << str.getString()<<endl;

    test(str);





    return 0;
}
