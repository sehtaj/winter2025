#include <string>

class Student {
private:
    std::string name;
    double cgpa;
    bool isCgpaValid(double cgpa);


public:
    Student();
    Student(const std::string& name, double cgpa);

    std::string getName() const;

    void setName(const std::string& newName);
};