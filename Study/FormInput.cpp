#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
vector<T> getSeparatedValuesFromUser(char separator = ',')
{
    stringstream ss;
    string str;
    getline(cin, str); // store a whole line
    //replace( str.begin(), str.end(), ',',' '); // Replacing ',' for ' '
    replace(str.begin(), str.end(), separator, ' ');
    ss << str;

    T value{0};
    vector<T> values;
    while (ss >> value) // store in value only the integers inside ss
    {
        values.push_back(value);
    }

    return values;
}

int main()
{
    cout << "Enter , seperated values: ";
    auto values = getSeparatedValuesFromUser<int>();

    //display values
    cout << "Read values: " << endl;
    for (auto v : values)
    {
        cout << v << endl;
    }
}