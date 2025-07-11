/*** Project A Problem 8.9, Chapter 8
*--------------------------------------------- ***** 
Modify Programming Project 7.20.3 so that you first print the lines in the order that they were entered, then print them in sorted order. 
***** When you sort the lines, only rearrange the pointers in the lines array. Write a program that reads lines of text and appends them to a char buffer[1000]. */

// Programmer: Heily Cabrera // Tester: Giannfranco Brance
// Group Project A //
/***** Members *****/
/***** Ashley Jacobson *****/
/***** Giannfranco Brance *****/
/***** Audrey Tapia *****/
/***** Heily Cabrera Guerrero *****/


#include <iostream> 
#include <string>  
#include <cctype>   

using namespace std;

int charAlphabetIndex(char c) 
{
    return (c) - 'A';
}

char alphabetIndexToChar(int index, char baseChr) 
{
    return baseChr + index;
}

string encrypt(const string& plaintext, const string& keyword) 
{
    string ciphertext = "";
    int keywordIndex = 0; 

    for (char pChar : plaintext) 
{
        if (isalpha(pChar)) 
  {
            char kChar = (keyword[keywordIndex % keyword.length()]);
            int shift = charAlphabetIndex(kChar);

            char base = isupper(pChar) ? 'A' : 'a';

            int pIndex = charAlphabetIndex(pChar);

            int cIndex = (pIndex + shift) % 26;

            ciphertext += alphabetIndexToChar(cIndex, base);

            keywordIndex++;
      }
    else 
      {
            ciphertext += pChar;
      }
    }
    return ciphertext;
}

string decrypt(const string& ciphertext, const string& keyword) {
    string plaintext = "";
    int keywordIndex = 0; 

    for (char cChar : ciphertext) {
        if (isalpha(cChar)) 
        { 
            char kChar = (keyword[keywordIndex % keyword.length()]);
            int shift = charAlphabetIndex(kChar);

            char base = isupper(cChar) ? 'A' : 'a';

            int cIndex = charAlphabetIndex(cChar);
            
            int pIndex = (cIndex - shift + 26) % 26;

            plaintext += alphabetIndexToChar(pIndex, base);

            
            keywordIndex++;
        } 
        else 
        {
            plaintext += cChar;
        }
    }
    return plaintext;
}

int main() {
    string keyword;
    string inputText;
    char choice;

    
    cout << "Enter the keyword (letters only): ";
    getline(std::cin, keyword);

    
    bool validKeyword = false;
    while (!validKeyword) {
        if (keyword.empty()) {
            cout << "Keyword cannot be empty. Please enter a keyword: ";
            getline(cin, keyword);
            continue;
        }
        validKeyword = true;
        for (char c : keyword) {
            if (!isalpha(c)) {
                cout << "Keyword must contain only letters. Please re-enter: ";
                getline(std::cin, keyword);
                validKeyword = false;
                break;
            }
        }
    }

    cout << "Do you want to (E)ncrypt or (D)ecrypt? ";
    cin >> choice;
    
    cin.ignore(); 

    while (choice != 'E' && choice != 'D') {
        cout << "Invalid choice. Please enter 'E' for Encrypt or 'D' for Decrypt: ";
        cin >> choice;
        cin.ignore(); // Consume newline
    }

    
    cout << "Enter the text to process: ";
    getline(std::cin, inputText);

    if (choice == 'E') {
        string encryptedText = encrypt(inputText, keyword);
        cout << "\nEncrypted Text: " << encryptedText << endl;
    } else { // choice == 'D'
        string decryptedText = decrypt(inputText, keyword);
        cout << "\nDecrypted Text: " << decryptedText << endl;
    }

    return 0;
}
