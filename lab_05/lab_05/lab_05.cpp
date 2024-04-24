#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Student {
public:
    std::string surname;
    std::string name;
    std::string home_address;
    std::string phone;
    std::string birth_date;

    Student(std::string surname, std::string name, std::string home_address, std::string phone, std::string birth_date)
        : surname(surname), name(name), home_address(home_address), phone(phone), birth_date(birth_date) {}
};

class StudentJournal : public Student {
public:
    std::vector<int> grades;
    std::string course;

    StudentJournal(std::string surname, std::string name, std::string home_address, std::string phone, std::string birth_date, std::vector<int> grades, std::string course)
        : Student(surname, name, home_address, phone, birth_date), grades(grades), course(course) {}

    void add_grade(int grade) {
        grades.push_back(grade);
    }

    void remove_grade(int grade) {
        grades.erase(std::remove(grades.begin(), grades.end(), grade), grades.end());
    }

    void display_info() {
        std::cout << "Surname: " << surname << ", Name: " << name << ", Home Address: " << home_address << ", Phone: " << phone << ", Birth Date: " << birth_date << ", Grades: ";
        for (int grade : grades) {
            std::cout << grade << " ";
        }
        std::cout << ", Course: " << course << std::endl;
    }
};

int main() {
    std::vector<StudentJournal> students;
    int num_students;
    std::cout << "Enter the number of students: ";
    std::cin >> num_students;

    for (int i = 0; i < num_students; i++) {
        std::string surname, name, home_address, phone, birth_date, course;
        std::vector<int> grades;
        int num_grades;

        std::cout << "Enter student's surname: ";
        std::cin >> surname;
        std::cout << "Enter student's name: ";
        std::cin >> name;
        std::cout << "Enter student's home address: ";
        std::cin >> home_address;
        std::cout << "Enter student's phone: ";
        std::cin >> phone;
        std::cout << "Enter student's birth date: ";
        std::cin >> birth_date;
        std::cout << "Enter student's course: ";
        std::cin >> course;
        std::cout << "Enter the number of grades: ";
        std::cin >> num_grades;

        for (int j = 0; j < num_grades; j++) {
            int grade;
            std::cout << "Enter grade " << j + 1 << ": ";
            std::cin >> grade;
            grades.push_back(grade);
        }

        students.push_back(StudentJournal(surname, name, home_address, phone, birth_date, grades, course));
    }

    for (auto& student : students) {
        student.display_info();
    }

    return 0;
}
