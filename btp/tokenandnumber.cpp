// int main()\n{\nint a = 5;\nfloat 1a = 10;\nreturn;\n}

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Check if a given character is a valid identifier character
bool isIdentifierChar(char c)
{
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9') ||
           (c == '_');
}

// Token type enum
enum TokenType
{
    KEYWORD,
    IDENTIFIER,
    OPERATOR,
    PARENTHESIS,
    NUMBER,
    INVALID
};

// Token struct
struct Token
{
    string value;
    TokenType type;
};

// Get the token type of a given token string
TokenType getTokenType(const string &token)
{
    if (token == "int" || token == "float" || token == "return")
    {
        return KEYWORD;
    }
    else if (isIdentifierChar(token[0]))
    {
        for (int i = 1; i < token.size(); i++)
        {
            if (!isIdentifierChar(token[i]))
            {
                return INVALID;
            }
        }
        return IDENTIFIER;
    }
    else if (token == "=" || token == ";")
    {
        return OPERATOR;
    }
    else if (token == "(" || token == ")")
    {
        return PARENTHESIS;
    }
    else if (token[0] >= '0' && token[0] <= '9')
    {
        for (int i = 1; i < token.size(); i++)
        {
            if (token[i] < '0' || token[i] > '9')
            {
                return INVALID;
            }
        }
        return NUMBER;
    }
    else
    {
        return INVALID;
    }
}

int main()
{
    // Input program
    string program = "int main()\n{\nint a = 5;\nfloat 1a = 10;\nreturn;\n}";

    // Tokenize the program
    istringstream iss(program);
    string token;
    int numTokens = 0;
    while (iss >> token)
    {
        numTokens++;
        TokenType type = getTokenType(token);
        if (type == INVALID)
        {
            cout << "Invalid token: " << token << endl;
        }
        else
        {
            cout << "Valid token: " << token << " (" << type << ")" << endl;
        }
    }

    // Output the total number of tokens
    cout << "Total number of tokens: " << numTokens << endl;

    return 0;
}
