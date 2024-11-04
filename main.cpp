#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

enum class JSONType : short 
{
    NUMBER, 
    STRING,
    NULLT,
    OBJECT,
    ARRAY,
    BOOL
};

class JSONNode {
    //member variables
    JSONType d_type;
    unordered_map<string , JSONNode> d_data;
    vector<JSONNode> d_array;
    //union to hold the value if their is any value
    union value
    {
        string d_string;
        double d_number;
        bool d_bool;
        value() {}
        ~value() {}

        // conversion operators for the union
        operator std::string()
        {
            return d_string;
        }

        operator double()
        {
            return d_number;
        }

        operator int()
        {
            return d_number;
        }

        operator bool()
        {
            return d_bool;
        }

    } d_value;
    void limitToArray()
    {
        if (!isArray())
        {
            throw std::runtime_error("this operation is only available to array node");
        }
    }

    void limitToObject()
    {
        if (!isObject())
        {
            throw std::runtime_error("this operation is only available to object node");
        }
    }

};