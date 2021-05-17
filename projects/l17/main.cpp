#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>


class person
{
public:
    std::string name;
    std::string surname;
    std::string email;
    std::string phone;

    person() {}
    virtual ~person() {}

    void setName(const std::string& nm) {this->name = nm; }
    void setSurname(const std::string& nm) {this->surname = nm; }
    void setemail(const std::string& nm) {this->email = nm; }
    void setphone(const std::string& nm) {this->phone = nm; }

    const std::string& getName() {return this->name; }
    const std::string& getSurname() {return this->surname; }
    const std::string& getemail() {return this->email; }
    const std::string& getphone() {return this->phone; }
};

class subject
{
public:
    std::string name;
    std::vector<person> teachers;

    subject(){}
    ~subject(){}

    void setName(const std::string nm) {this->name = nm; }
    std::string& getName() {return this->name; }

    void addTeacher(const person nm) {this->teachers.push_back(nm); }
    void popTeacher() {return this->teachers.pop_back(); }
};

class student : public person
{
public:
    int64_t specialty;
    std::map<std::string, unsigned short int> grades;

    student(){}
    ~student() override {}

    const int64_t& getSpeciaty() {return this->specialty;}
    void setSpeciaty(const int64_t& nm) {this->specialty = nm;}
    
    void setGrade(std::string nm, unsigned short int gr) { this->grades[nm] = gr; }
    auto getGrade(std::string nm, unsigned short int gr) { return this->grades[nm]; }
};

class teacher : public person
{
public:
    int64_t specialty;
    subject vsubject;

    const int64_t& getSpeciaty() {return this->specialty;}
    void setSpeciaty(const int64_t& nm) {this->specialty = nm;}
    
    const subject& getSubject() {return this->vsubject;}
    void setSubject(const subject& nm) {this->vsubject = nm;}
};

class depatrament
{
public:
    int64_t id;
    person dean;
    std::vector<int64_t> specialties;

    const int64_t& getId() {return this->id;}
    void setId(const int64_t& nm) {this->id = nm;}
    
    const person& getDean() {return this->dean;}
    void setDean(const person& nm) {this->dean = nm;}

    void addSpec(const int64_t& nm) {this->specialties.push_back(nm); }
    void popSpec() {return this->specialties.pop_back(); }
    void delSpec(const int64_t& nm) {for (int i = 0; i < this->specialties.size(); i++)
    {
        if ((this->specialties[i]) == nm)
        {
            this->specialties.erase(this->specialties.begin()+i);
            return;
        }
    }}
};

int main(int argc, char *argv[]){

    std::cout << "Hello world!" << std::endl;

}