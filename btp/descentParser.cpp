// Implement Recursive Descent Parser for the given grammar.
// Grammar: X → xY
//  Y → ZwY | xY | ∈
//  Z → yW
//  W → zW | ∈

#include <iostream>
#include <string>
using namespace std;

// Function prototypes
bool X(string input);
bool Y(string input);
bool Z(string input);
bool W(string input);

// X → xY
bool X(string input)
{
    if (input.size() >= 2 && input[0] == 'x')
    {
        return Y(input.substr(1));
    }
    else
    {
        return false;
    }
}

// Y → ZwY | xY | ∈
bool Y(string input)
{
    if (input.empty())
    {
        return true; // Y can be epsilon
    }
    else if (input.size() >= 2 && input[0] == 'z' && input[1] == 'w')
    {
        return Y(input.substr(2)) && Z(input.substr(0, 2));
    }
    else if (input[0] == 'x')
    {
        return Y(input.substr(1));
    }
    else
    {
        return false;
    }
}

// Z → yW
bool Z(string input)
{
    if (input.size() >= 2 && input[0] == 'y')
    {
        return W(input.substr(1));
    }
    else
    {
        return false;
    }
}

// W → zW | ∈
bool W(string input)
{
    if (input.empty())
    {
        return true; // W can be epsilon
    }
    else if (input[0] == 'z')
    {
        return W(input.substr(1));
    }
    else
    {
        return false;
    }
}

int main()
{
    string input;
    cout << "Enter input string: ";
    getline(cin, input);

    if (X(input))
    {
        cout << "Input string is valid." << endl;
    }
    else
    {
        cout << "Input string is invalid." << endl;
    }

    return 0;
}
