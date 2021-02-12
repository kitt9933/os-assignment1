// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <iomanip>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student *student  = new Student;
    double average;

    // Sequence of user input -> store in fields of `student`

    student->id = promptInt("Please enter the student's id number: ", 0, 999999999);
    

    student->f_name = new char[128];
    std:: cout << "Please enter the student's first name: ";
    std:: cin >> student->f_name;

    student->l_name = new char[128];
    std:: cout << "Please enter the student's last name: ";
    std:: cin >> student->l_name;

    student->n_assignments = promptInt("Please enter how many assignments were graded: ", 1, 134217728);

    std::cout << "\n";
    student->grades = new double[student->n_assignments];

    for(int i = 0; i < student->n_assignments; i ++){
        std::string msg = "Please enter grade for assigment" + std::to_string(i) + ": ";
        
        student->grades[i] = promptDouble(msg, 0, 1000);
    }
    
    // Call `CalculateStudentAverage(???, ???)`
    double *avg;
    calculateStudentAverage(student, avg);
    // Output `average`
    
    std::cout << "Student: " << student->f_name  << " "<< student->l_name << " [" << student->id << "]\n";
    std::cout << std::fixed << std::setprecision(1);
    std ::cout << "  Average grade: " << *avg << std::endl;
    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    
    // Code to prompt user for an int
    
    while(1){
        int inValue;
        std:: cout << message;
        std::cin >> inValue;
        if((inValue > max) || (inValue < min)){

            std::cout << "Sorry, I cannot understand your answer\n";
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }
        else{
                 return inValue;   
        }
        
    }   
    
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
    double inValue;
    // Code to prompt user for an int
    std:: cout << message;
    std::cin >> inValue;
    while(1){
        if((inValue > max) || (inValue < min)){

            std::cout << "Sorry, I cannot understand your answer\n";
        }
        else{
            return inValue;
        }
    }
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
   
    // Code to calculate and store average grade
    double total = 0;
    Student *stu = (Student*)object;
    for(int i = 0; i < stu->n_assignments; i++){
        total += stu->grades[i];

    }
    double result = total / stu->n_assignments;
    //std::cout << result;

    *avg = result;
}
