#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

// Function to get current timestamp
string getCurrentTime() {
    time_t now = time(0);
    char* dt = ctime(&now); // Convert time to string
    string timestamp = dt;
    timestamp.pop_back(); // Remove the newline character from the end
    return timestamp;
}

// Function to simulate chatbot response
string getChatbotResponse(const string& userInput) {
    // Simple rule-based responses
    if (userInput == "hi" || userInput == "hello")
        return "Hello! How can I help you today?";
    else if (userInput == "how are you")
        return "I'm just a bunch of code, but I'm doing fine! How about you?";
    else if (userInput == "bye")
        return "Goodbye! Have a great day!";
    else
        return "I'm not sure how to respond to that.";
}

int main() {
    string userMessage;
    string chatbotResponse;

    // Open the log file in append mode
    ofstream logFile("chat_log.txt", ios::app);
    if (!logFile) {
        cerr << "Error opening file for logging." << endl;
        return 1;
    }

    cout << "Chatbot: Hello! Type 'bye' to exit the chat." << endl;

    while (true) {
        // Get user input
        cout << "You: ";
        getline(cin, userMessage);

        // Exit if user types "bye"
        if (userMessage == "bye") {
            chatbotResponse = "Goodbye! Have a great day!";
            cout << "Chatbot: " << chatbotResponse << endl;

            // Log final message
            logFile << "[" << getCurrentTime() << "] You: " << userMessage << endl;
            logFile << "[" << getCurrentTime() << "] Chatbot: " << chatbotResponse << endl;
            break;
        }

        // Generate chatbot response
        chatbotResponse = getChatbotResponse(userMessage);
        cout << "Chatbot: " << chatbotResponse << endl;

        // Log conversation
        logFile << "[" << getCurrentTime() << "] You: " << userMessage << endl;
        logFile << "[" << getCurrentTime() << "] Chatbot: " << chatbotResponse << endl;
    }

    logFile.close();
    cout << "Chat logged to 'chat_log.txt'. Thank you for chatting!" << endl;
    return 0;
}
