#include <iostream>

// Звичайна функція
void convertTime(int totalSeconds) {
    int years = totalSeconds / (60 * 60 * 24 * 365);
    totalSeconds %= 60 * 60 * 24 * 365;
    int months = totalSeconds / (60 * 60 * 24 * 30);
    totalSeconds %= 60 * 60 * 24 * 30;
    int days = totalSeconds / (60 * 60 * 24);
    totalSeconds %= 60 * 60 * 24;
    int hours = totalSeconds / (60 * 60);
    totalSeconds %= 60 * 60;
    int minutes = totalSeconds / 60;
    totalSeconds %= 60;
    int seconds = totalSeconds;

    std::cout << "Years: " << years << ", Months: " << months << ", Days: " << days << ", Hours: " << hours << ", Minutes: " << minutes << ", Seconds: " << seconds << std::endl;
}

// Шаблон функції
template <typename T>
void convertTimeTemplate(T totalSeconds) {
    T years = totalSeconds / (60 * 60 * 24 * 365);
    totalSeconds %= 60 * 60 * 24 * 365;
    T months = totalSeconds / (60 * 60 * 24 * 30);
    totalSeconds %= 60 * 60 * 24 * 30;
    T days = totalSeconds / (60 * 60 * 24);
    totalSeconds %= 60 * 60 * 24;
    T hours = totalSeconds / (60 * 60);
    totalSeconds %= 60 * 60;
    T minutes = totalSeconds / 60;
    totalSeconds %= 60;
    T seconds = totalSeconds;

    std::cout << "Years: " << years << ", Months: " << months << ", Days: " << days << ", Hours: " << hours << ", Minutes: " << minutes << ", Seconds: " << seconds << std::endl;
}

int main() {
    int totalSeconds;
    std::cout << "Enter the number of seconds: ";
    std::cin >> totalSeconds;
    convertTime(totalSeconds);
    convertTimeTemplate(totalSeconds);
    return 0;
}
