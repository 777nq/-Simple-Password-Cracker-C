#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

bool is_password_cracked(const std::string& password, const std::string& guess) {
    return password == guess;
}

std::string generate_random_password(int length) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int max_index = sizeof(charset) - 1;

    std::string password;
    for (int i = 0; i < length; ++i) {
        int random_index = rand() % max_index;
        password += charset[random_index];
    }
    return password;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    std::string password;
    int password_length;

    std::cout << "Enter the password: ";
    std::cin >> password;

    password_length = password.length();

    std::cout << "Attempting to crack the password...\n\n";

    std::string guess;
    int attempts = 0;

    while (!is_password_cracked(password, guess)) {
        guess = generate_random_password(password_length);
        std::cout << "Attempt " << attempts + 1 << ": " << guess << "\n";
        ++attempts;
    }

    std::cout << "\nPassword cracked!\n";
    std::cout << "Original password: " << password << "\n";
    std::cout << "Attempts made: " << attempts << "\n";

    return 0;
}
