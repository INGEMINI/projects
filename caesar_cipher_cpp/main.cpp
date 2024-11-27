#include <iostream>
#include <string>
#include <cctype> // For isalpha() and isdigit()
using namespace std;

// Function to encrypt a message using Caesar Cipher
string encrypt(const string& message, int key) {
    string encryptedMessage = "";
    for (char ch : message) {
        if (isalpha(ch)) { // Encrypt only alphabetic characters
            char offset = isupper(ch) ? 'A' : 'a';
            encryptedMessage += char((ch - offset + key) % 26 + offset);
        } else {
            encryptedMessage += ch; // Non-alphabetic characters remain unchanged
        }
    }
    return encryptedMessage;
}

// Function to decrypt a message using Caesar Cipher
string decrypt(const string& encryptedMessage, int key) {
    string decryptedMessage = "";
    for (char ch : encryptedMessage) {
        if (isalpha(ch)) { // Decrypt only alphabetic characters
            char offset = isupper(ch) ? 'A' : 'a';
            decryptedMessage += char((ch - offset - key + 26) % 26 + offset);
        } else {
            decryptedMessage += ch; // Non-alphabetic characters remain unchanged
        }
    }
    return decryptedMessage;
}

// Function to validate the key
int validateKey(const string& keyInput) {
    for (char ch : keyInput) {
        if (!isdigit(ch)) {
            throw invalid_argument("Key must be a positive integer.");
        }
    }
    return stoi(keyInput);
}

// Main function
int main() {
    string message;
    string keyInput;
    int key;
    int choice;

    cout << "=== Caesar Cipher Encryption/Decryption ===\n";

    while (true) {
        cout << "\nChoose an option:\n";
        cout << "1. Encrypt a message\n";
        cout << "2. Decrypt a message\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        if (choice == 3) {
            cout << "Exiting program. Goodbye!\n";
            break;
        }

        cout << "Enter the message: ";
        getline(cin, message);

        cout << "Enter the key (positive integer): ";
        cin >> keyInput;

        try {
            key = validateKey(keyInput); // Validate and convert the key
            key = key % 26; // Optimize key for cyclic shifts
        } catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << "\n";
            continue;
        }

        if (choice == 1) {
            string encryptedMessage = encrypt(message, key);
            cout << "Encrypted Message: " << encryptedMessage << "\n";
        } else if (choice == 2) {
            string decryptedMessage = decrypt(message, key);
            cout << "Decrypted Message: " << decryptedMessage << "\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
