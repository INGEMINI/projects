#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Class to represent a user
class User {
public:
    string name;
    int age;
    float height;  // in meters
    float weight;  // in kilograms

    User(string n, int a, float h, float w) : name(n), age(a), height(h), weight(w) {}

    // Calculate BMI
    float calculateBMI() const {
        return weight / (height * height);
    }

    // Display user information
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Height: " << height << " meters" << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "BMI: " << calculateBMI() << endl;
    }
};

// Class to represent a workout
class Workout {
public:
    string type;    // e.g., Running, Swimming, etc.
    float duration; // in minutes
    float calories; // calories burned during the workout

    Workout(string t, float d, float c) : type(t), duration(d), calories(c) {}

    // Display workout information
    void displayWorkout() {
        cout << "Workout Type: " << type << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Calories Burned: " << calories << " kcal" << endl;
    }
};

// Function to log user data to a file
void logToFile(const User& user, const vector<Workout>& workouts) {
    ofstream userFile("user_data.txt", ios::app);
    if (!userFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    userFile << "Name: " << user.name << endl;
    userFile << "Age: " << user.age << endl;
    userFile << "Height: " << user.height << " meters" << endl;
    userFile << "Weight: " << user.weight << " kg" << endl;
    userFile << "BMI: " << user.calculateBMI() << endl;

    userFile << "\nWorkouts:\n";
    for (const auto& workout : workouts) {
        userFile << "Workout Type: " << workout.type << endl;
        userFile << "Duration: " << workout.duration << " minutes" << endl;
        userFile << "Calories Burned: " << workout.calories << " kcal" << endl;
    }
    userFile << "-----------------------------\n";
    userFile.close();
}

// Function to get user input for a workout
Workout getWorkoutInput() {
    string type;
    float duration, calories;

    cout << "Enter workout type (e.g., Running, Swimming): ";
    cin >> type;
    cin.ignore();
    cout << "Enter workout duration (in minutes): ";
    cin >> duration;
    cin.ignore();
    cout << "Enter calories burned: ";
    cin >> calories;
    cin.ignore();
    return Workout(type, duration, calories);
}

int main() {
    string name;
    int age;
    float height, weight;

    // Input user details
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your height (in meters): ";
    cin >> height;
    cout << "Enter your weight (in kg): ";
    cin >> weight;

    // Create a User object
    User user(name, age, height, weight);

    // Display user information and BMI
    user.displayInfo();

    // Log user information to a file
    vector<Workout> workouts;
    char addMore = 'y';

    while (addMore == 'y' || addMore == 'Y') {
        // Get workout details
        workouts.push_back(getWorkoutInput());

        cout << "Do you want to log another workout? (y/n): ";
        cin >> addMore;
    }

    // Log all data to file
    logToFile(user, workouts);

    cout << "Data logged successfully!" << endl;
    return 0;
}
