//DISPLAY 11.12 Implementation of StringVar 
//This is the implementation of the class StringVar.
//The definition for the class StringVar is in Display 11.11.
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cstring>
using namespace std;

    //Uses cstddef and cstdlib:
    StringVar::StringVar(int size) : max_length(size)
    {
        value = new char[max_length + 1];//+1 is for '\0'.
        value[0] = '\0';
    }

    //Uses cstddef and cstdlib:
    StringVar::StringVar( ) : max_length(100)
    {
        value = new char[max_length + 1];//+1 is for '\0'.
        value[0] = '\0';
    }

    //Uses cstring, cstddef, and cstdlib:
    StringVar::StringVar(const char a[]) : max_length(strlen(a))
    {
        value = new char[max_length + 1];//+1 is for '\0'.
        strcpy(value, a);
    }
    //Uses cstring, cstddef, and cstdlib:
    StringVar::StringVar(const StringVar& string_object)
                            : max_length(string_object.length( ))
    {
        value = new char[max_length + 1];//+1 is for '\0'.
        strcpy(value, string_object.value);
    }

StringVar::~StringVar( )
    {
        delete [] value;
    }

    //Uses cstring:
    int StringVar::length( ) const
    {
        return strlen(value);
    }

    //Uses iostream:
    void StringVar::input_line(istream& ins)
    {
        ins.getline(value, max_length + 1);
    }

    //Uses iostream:
    ostream& operator <<(ostream& outs, const StringVar& the_string)
    {
        outs << the_string.value;
        return outs;
    }

