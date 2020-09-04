#include <iostream>

using namespace std;

void encrypt(string Plain);
void decrypt(string Cypher);
int letter(char lett);
int sqrrt(float number);

int main()
{
    string response;

    cout << "CAUTION: DO NOT USE SPACES IN YOUR MESSAGE!" << endl;
    cout << "SIMPLY BEGIN EACH NEW WORD WITH A CAPITAL LETTER!" << endl;
    cout << "Welcome to the Encryption System..." << endl;
    cout << "To Encrypt your message, please enter 1..." << endl;
    cout << "To Decrypt your message, please enter 2..." << endl;

    std::getline(cin, response);

    if(response == "1")
    {
        string PlainText;
        cout << "Enter your message to encrypt and press enter" << endl;
        std::getline(cin, PlainText);

        encrypt(PlainText);
        return 0;

    }
    else if(response == "2")
    {
        string CypherText;
        cout << "Enter your encrypted message and press enter" << endl;
        std::getline(cin, CypherText);

        decrypt(CypherText);
        return 0;
    }
    else
    {
        cout << "Invalid Response!" << endl;
        return 1;
    }
}

void encrypt(string Plain)
{
    char hex[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int temp1, temp3, temp4;
    float temp2;
    string converted = "";

    for(int i = 0; i < Plain.length(); i++)
    {
        temp1 = Plain.at(i);
        temp1 = temp1 * temp1;
        temp1 = temp1 - 5;

        while(temp1 > 0)
        {
            temp2 = temp1 / 16.0;
            temp3 = temp2;
            temp2 = temp2 - temp3;
            temp4 = temp2 * 16;
            converted = converted + hex[temp4];
            temp1 = temp3;
        }
    }
    cout << converted << endl; //B3414921B861B861C581
}

void decrypt(string Cypher)
{
    int temp2 = 16, temp3 = 16 * 16, temp4 = 16 * 16 * 16, temp6[40000], temp7;
    string de_converted = "", temp5 = "";
    char dcrypt[40000];

    for(int i = 0; i < Cypher.length(); i++)
    {
        temp5 = Cypher[i] + temp5;
    }
    for(int i = 1; i <= Cypher.length(); i++)
    {
        temp6[i - 1] = letter(temp5[i - 1]);
    }

    for(int i = 0; i < Cypher.length(); i += 4)
    {
        temp7 = (temp6[i] * temp4) + (temp6[i + 1] * temp3) + (temp6[i + 2] * temp2) + (temp6[i + 3]);
        temp7 = temp7 + 5;
        temp7 = sqrrt(temp7);
        de_converted = char(temp7) + de_converted;
    }

    cout << de_converted << endl;
}

int letter(char lett)
{
    switch(lett)
    {
        case '0':
            return 0;
            break;
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 8;
            break;
        case '9':
            return 9;
            break;
        case 'A':
            return 10;
            break;
        case 'B':
            return 11;
            break;
        case 'C':
            return 12;
            break;
        case 'D':
            return 13;
            break;
        case 'E':
            return 14;
            break;
        case 'F':
            return 15;
            break;
        default:
            break;
    }
}

int sqrrt(float number)
{
    float temp1;
    for(float m = 1; m * m <= number; m += 0.00001)
    {
        temp1 = m;
    }
    return temp1;
}
