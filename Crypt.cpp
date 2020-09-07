#include <iostream>
#include <string>
#include <time.h>

using namespace std;

//functions
void encrypt(string Plain);
void decrypt(string Cypher, string Key, int Key2);
int letter(char lett);
int sqrrt(float number);

int main()
{
    //Ask user for what they want to do
    string response;

    cout << "Welcome to the Encryption System..." << endl;
    cout << "To Encrypt your message, please enter 1..." << endl;
    cout << "To Decrypt your message, please enter 2..." << endl;

    std::getline(cin, response);

    //encryption
    if(response == "1")
    {
        string PlainText;
        cout << "Enter your message to encrypt and press enter" << endl;
        std::getline(cin, PlainText);

        encrypt(PlainText);
        return 0;

    }
    //decryption
    else if(response == "2")
    {
        string CypherText, Key1;
        int Key2;
        cout << "Enter your encrypted message and press enter" << endl;
        std::getline(cin, CypherText);
        cout << "Enter key 1 and press enter" << endl;
        std::getline(cin, Key1);
        cout << "Enter key 2 and press enter" << endl;
        cin >> Key2;

        decrypt(CypherText, Key1, Key2);
        return 0;
    }
    //invalid response
    else
    {
        cout << "Invalid Response!" << endl;
        return 1;
    }
}

//encryption function
void encrypt(string Plain)
{
    char hex[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}; //characters to store hex values
    int temp6, temp1, temp3, temp4, record[Plain.length()], j = 0, temp7;
    float temp2;
    string converted = "", rec = "", temp5;

    //generate random numbers for 2 respectively
    srand(time(NULL));
    temp7 = rand() % 1000;
    for(int i = 0; i < Plain.length(); i++)
    {
        //generate random letters for key1
        temp6 = rand() % 26;
        temp5 = 'a' + temp6;

        //convert message to ascii
        temp1 = Plain.at(i);
        //store position of spaces inputted in key1 add randomly generated letters to it
        if(temp1 == 32)
        {
            record[j] = i - j;
            rec = rec + temp5 + to_string(record[j]);
            j++;
            continue;
        }
        //math operations on message
        temp1 = temp1 * temp1;
        temp1 = temp1 - temp7; //subtract randomly generated number from message (key2)

        //store encrypted message
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

    //print encrypted message with keys
    cout << "Encrypted message: " << converted << endl;
    cout << "Key 1: " << rec << endl;
    cout << "Key 2: " << temp7 << endl;
}

//decryption system
void decrypt(string Cypher, string Key, int Key2)
{
    int temp2 = 16, temp3 = 16 * 16, temp4 = 16 * 16 * 16, temp6[40000], temp7, temp1a[10000], temp8[10000], temp9 = 0, temp11, temp12 = 0;
    string de_converted = "", temp5 = "", space = " ", temp15 = "";
    char dcrypt[40000];

    //Get numbers from key1
    for(int i = 1; i < Key.length(); i++)
    {
        while(isdigit(Key[i]))
        {
            temp15 = temp15 + Key[i];
            i++;
        }
        temp1a[temp9] = std::stoi(temp15);
        temp9++;
        temp15 = "";
    }
    //reverse order of Key1
    temp11 = temp9 - 1;
    for(int i = 0; i < temp9; i++)
    {
        temp8[i] = temp1a[temp11];
        temp11--;
    }

    //stores encrypted message in reverse
    for(int i = 0; i < Cypher.length(); i++)
    {
        temp5 = Cypher[i] + temp5;
    }
    //converts encrypted message in hex to numeric equivalent
    for(int i = 1; i <= Cypher.length(); i++)
    {
        temp6[i - 1] = letter(temp5[i - 1]);
    }

    //decryption workson a four character system so this converts four hex characters together back to one original text character
    int temp13 = Cypher.length() / 4;
    for(int i = 0; i < Cypher.length(); i += 4)
    {
        temp7 = (temp6[i] * temp4) + (temp6[i + 1] * temp3) + (temp6[i + 2] * temp2) + (temp6[i + 3]);
        temp7 = temp7 + Key2;
        temp7 = sqrrt(temp7);
        if(temp13 == temp8[temp12])
        {
            de_converted = char(temp7) + space + de_converted; //store space if encountered with next letter
            temp12++;
        }
        else
        {
            de_converted = char(temp7) + de_converted; //store character
        }
        temp13--;
    }

    //print plain message
    cout << de_converted << endl;
}

//convert hex back to numeric equivalent
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

//personal square root function
int sqrrt(float number)
{
    float temp1;
    for(float m = 1; m * m <= number; m += 0.00001)
    {
        temp1 = m;
    }
    return temp1;
}
