#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void encrypt(string Plain);
void decrypt(string Cypher, string Key);
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
        string CypherText, Key;
        cout << "Enter your encrypted message and press enter" << endl;
        std::getline(cin, CypherText);
        cout << "Enter key and press enter" << endl;
        std::getline(cin, Key);

        decrypt(CypherText, Key);
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
    int temp1, temp3, temp4, record[Plain.length()], j = 0;
    float temp2;
    string converted = "", rec = "", temp5 = "-";

    for(int i = 0; i < Plain.length(); i++)
    {
        temp1 = Plain.at(i);
        if(temp1 == 32)
        {
            record[j] = i - j;
            rec = rec + temp5 + to_string(record[j]); //fix this
            j++;
            continue;
        }
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

    cout << "Encrypted message: " << converted << endl;
    cout << "Key: " << rec << endl;
}

void decrypt(string Cypher, string Key)
{
    int temp2 = 16, temp3 = 16 * 16, temp4 = 16 * 16 * 16, temp6[40000], temp7, temp8[10000], temp9 = 0, temp11, temp12 = 0;
    string de_converted = "", temp5 = "", space = " ";
    char dcrypt[40000], temp10[10000];

    //Get numbers from key
    for(int i = 0; i < Key.length(); i++)
    {
        temp10[i] = Key[i];
    }
    for(int i = 0; i < Key.length(); i++)
    {
        while(temp10[i] != '-') //check condition
        {
            temp8[temp9] = temp10[i];
            temp9++;
        }
    }
    //reverse order
    //use

    for(int i = 0; i < Cypher.length(); i++)
    {
        temp5 = Cypher[i] + temp5;
    }
    for(int i = 1; i <= Cypher.length(); i++)
    {
        temp6[i - 1] = letter(temp5[i - 1]);
    }

    int temp13 = Cypher.length() / 4;
    for(int i = 0; i < Cypher.length(); i += 4)
    {
        temp7 = (temp6[i] * temp4) + (temp6[i + 1] * temp3) + (temp6[i + 2] * temp2) + (temp6[i + 3]);
        temp7 = temp7 + 5;
        temp7 = sqrrt(temp7);
        if(temp13 == temp8[temp12])//fix this all
        {
            de_converted = char(temp7) + space + de_converted;
            temp12++;
        }
        else
        {
            de_converted = char(temp7) + de_converted;
        }
        temp13--;
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
