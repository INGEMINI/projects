#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include<string>
#include<random>

using namespace std;

// Structure to represent a Song
struct Song {
    string title;
    string artist;
    int duration; // in seconds

    // Constructor
    Song(string t, string a, int d) : title(t), artist(a), duration(d) {}
};

// Playlist Class
class Playlist {
private:
    vector<Song> songs;

    // Helper function to format duration
    string formatDuration(int seconds) {
        int minutes = seconds / 60;
        seconds %= 60;
        return to_string(minutes) + "m " + to_string(seconds) + "s";
    }

public:
    // Add a song to the playlist
    void addSong(const string& title, const string& artist, int duration) {
        songs.emplace_back(title, artist, duration);
        cout << "✅ Song added successfully: " << title << " by " << artist << "\n";
    }

    // Remove a song by title
    void removeSong(const string& title) {
        auto it = find_if(songs.begin(), songs.end(), [&title](const Song& song) {
            return song.title == title;
        });

        if (it != songs.end()) {
            cout << "❌ Song removed: " << it->title << " by " << it->artist << "\n";
            songs.erase(it);
        } else {
            cout << "⚠️ Song not found: " << title << "\n";
        }
    }

    // Display all songs
    void displaySongs() {
        if (songs.empty()) {
            cout << "🎵 Playlist is empty!\n";
            return;
        }

        cout << "🎶 Playlist:\n";
        cout << left << setw(30) << "Title" << setw(20) << "Artist" << "Duration\n";
        cout << string(60, '-') << "\n";

        for (const auto& song : songs) {
            cout << left << setw(30) << song.title << setw(20) << song.artist << formatDuration(song.duration) << "\n";
        }
    }

    // Shuffle the playlist
    void shuffleSongs() {
    if (songs.size() <= 1) {
        cout << "⚠️ Not enough songs to shuffle!\n";
        return;
    }

    // Use a random engine
    random_device rd;                     // Generate a random seed from hardware
    default_random_engine rng(rd());      // Initialize random engine with the seed
    shuffle(songs.begin(), songs.end(), rng); // Shuffle the songs using std::shuffle
    cout << "🔀 Playlist shuffled!\n";
}

    // Sort by artist name
    void sortByArtist() {
        sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) {
            return a.artist < b.artist;
        });
        cout << "🔤 Playlist sorted by artist!\n";
    }

    // Sort by duration
    void sortByDuration() {
        sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) {
            return a.duration < b.duration;
        });
        cout << "⏱️ Playlist sorted by duration!\n";
    }
};

// Main function
int main() {
    Playlist playlist;
    int choice;

    do {
        cout << "\n🎧 Music Playlist Organizer 🎧\n";
        cout << "1. Add Song\n";
        cout << "2. Remove Song\n";
        cout << "3. Display Songs\n";
        cout << "4. Shuffle Songs\n";
        cout << "5. Sort by Artist\n";
        cout << "6. Sort by Duration\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // Clear input buffer

        switch (choice) {
        case 1: {
            string title, artist;
            int duration;

            cout << "Enter song title: ";
            getline(cin, title);
            cout << "Enter artist name: ";
            getline(cin, artist);
            cout << "Enter song duration (in seconds): ";
            cin >> duration;

            playlist.addSong(title, artist, duration);
            break;
        }
        case 2: {
            string title;
            cout << "Enter song title to remove: ";
            getline(cin, title);

            playlist.removeSong(title);
            break;
        }
        case 3:
            playlist.displaySongs();
            break;

        case 4:
            playlist.shuffleSongs();
            break;

        case 5:
            playlist.sortByArtist();
            break;

        case 6:
            playlist.sortByDuration();
            break;

        case 7:
            cout << "👋 Exiting... Goodbye!\n";
            break;

        default:
            cout << "⚠️ Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
