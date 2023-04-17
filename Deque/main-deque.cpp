#include "mylib.h"


int main() {
    ofstream fr1("Kietekai.txt");
    ofstream fr2("Vargsiukai.txt");
    deque<Student> students, kietekai, vargsiukai;
    string firstName, lastName, line;
    int grade, finalExamGrade, gradeAmount, fileSize;
    double timeT, timeB , timeC, timeA;
    int option3, option2;
    cout<<"If you want to create a file type 1 if you don't type 2: ";
    cin>>option2;
    cout<<"If you want to read from a file type 2 or type 1 if you want to do it manually: ";
    cin>>option3;
    switch(option3){
        case 1:
                cout << "Enter the first and last name of the student (type 'done done' when finished):\n";
                try {
                    while (cin >> firstName >> lastName) {
                        if (firstName == "done" && lastName == "done") {
                            break;
                        }
                        if (cin.fail()) {
                            throw runtime_error("Invalid input");
                        }
                        Student student = {firstName, lastName};
                        cout<<"Do you want to enter grades manually?(y/n)";
                        string input;
                        cin>>input;
                        if(input == "y"){
                            cout << "Enter grades for " << student.firstName << ' ' << student.lastName << " (type '-1' when finished):\n";
                            while (cin >> grade) {
                                if (grade == -1) {
                                    break;
                                }
                                if (cin.fail()) {
                                    throw runtime_error("Invalid input");
                                }
                                if(grade <= 10 && grade > 0){
                                   student.grades.push_back(grade);
                                }
                                else{
                                    cout<<"Enter the number between 1 and 10. Try again: ";
                                }

                            }
                            cout << "Enter final exam grade for " << student.firstName << ' ' << student.lastName << ":\n";
                            if (!(cin >> finalExamGrade)) {
                                throw runtime_error("Invalid input");
                            }
                            if(finalExamGrade <= 10 && finalExamGrade > 0){
                                cout << "Enter the first and last name of the student (type 'done done' when finished):\n";
                                student.finalExamGrade = finalExamGrade;
                                students.push_back(student);
                            }
                            else{
                                cout<<"Final exam grade can only be between 1 and 10. Try again: "; cin >> finalExamGrade;
                                cout << "Enter the first and last name of the student (type 'done done' when finished):\n";
                            }
                        }
                        if(input == "n"){
                            int number;
                            srand(time(NULL));
                            cout<<"How many grades do you want to generate?"; cin>>number;
                            randomGradeGenerator(number,student);
                            students.push_back(student);
                            cout << "Enter the first and last name of the student (type 'done done' when finished):\n";
                        }
                    }
                }catch (const exception& e) {
                    cerr << "Error: " << e.what() << endl;
                    return 1;
                }
                break;
        case 2:
            if(option2 == 1){
                cout << "Enter the file size and the amount of grades \n";
                cin >> fileSize >> gradeAmount;
                Timer b;
                createFile(fileSize, gradeAmount);
                timeB = b.elapsed();
            }
            ifstream fd("students.txt");
            Timer t;
            string header;
            getline(fd, header);

            while (getline(fd, line)) {
                stringstream ss(line);
                ss >> firstName >> lastName;
                Student student;
                student.firstName = firstName;
                student.lastName = lastName;

                int grade;
                while (ss >> grade) {
                    student.grades.push_back(grade);
                }

                student.finalExamGrade = grade;
                student.grades.pop_back();
                student.median = calculateMedian(student)*0.4+student.finalExamGrade*0.6;
                student.average = calculateAverage(student)*0.4+student.finalExamGrade*0.6;
                students.push_back(student);

            }
            timeT = t.elapsed();
            break;
    }

            cout<< "Type 1 if you want Final (Med.) or type 2 for Final (Avg.) \n";
            int option4;
            cin >> option4;
            cout<< "Type 1 if you want to use strategy 1 or type 2 for strategy 2 \n";
            int option5;
            cin>>option5;
            if(option5 == 1){
                Timer a;
                Timer c;
                switch(option4){
                case 1:
                    sort(students.begin(), students.end(), compareStudentsMED);
                    timeC = c.elapsed();
                    for (int i = students.size(); i > 0; i--) {
                        if(students[i-1].median < 5){
                            vargsiukai.push_back(students[i-1]);
                            students.pop_back();
                        }
                        else{
                            break;
                        }
                    }
                    timeA = a.elapsed();
                    break;

                case 2:
                    sort(students.begin(), students.end(), compareStudentsAVG);
                    timeC = c.elapsed();
                    for (int i = students.size() ; i > 0; i--) {
                        if(students[i-1].average < 5){
                            vargsiukai.push_back(students[i-1]);
                            students.pop_back();
                        }
                        else{
                            break;
                        }
                    }
                    timeA = a.elapsed();
                    break;

                default:
                    cout << "Invalid input";
                    break;
            }
            switch(option4){
                case 1:

                    fr1 << fixed << setw(20) << "Name" << setw(20) << "LastName" << setw(25) << "Final (Med.)\n";
                    fr1 <<"--------------------------------------------------------------------------------------------\n";
                    fr2 << fixed << setw(20) << "Name" << setw(20) << "LastName" << setw(25) << "Final (Med.)\n";
                    fr2 <<"--------------------------------------------------------------------------------------------\n";
                    for (auto& student : students) {
                            fr1 << fixed << setw(20) << student.firstName << setw(20) << student.lastName;
                            fr1 << fixed << setw(20) << setprecision(1)<< student.median << '\n';
                    }
                    for (auto& student : vargsiukai) {
                            fr2 << fixed << setw(20) << student.firstName << setw(20) << student.lastName;
                            fr2 << fixed << setw(20) << setprecision(1)<< student.median << '\n';
                    }
                    cout<<"Creating a fille took " << timeB <<" seconds\n";
                    cout<<"Reading from fille took " << timeT <<" seconds\n";
                    cout<<"Sorting took " << timeC <<" seconds\n";
                    cout<<"Printing out the answers took " << timeA <<" seconds\n";
                    cout<<"The program took "<<timeA + timeT +timeB<<" seconds to execute\n";
                    break;

                case 2:
                    fr1 << fixed << setw(20) << "Name" << setw(20) << "LastName" << setw(25) << "Final (Avg.)\n";
                    fr1 <<"--------------------------------------------------------------------------------------------\n";
                    fr2 << fixed << setw(20) << "Name" << setw(20) << "LastName" << setw(25) << "Final (Avg.)\n";
                    fr2 <<"--------------------------------------------------------------------------------------------\n";
                    for (auto& student : students) {
                            fr1 << fixed << setw(20) << student.firstName << setw(20) << student.lastName;
                            fr1 << fixed << setw(20) << setprecision(1)<< student.average << '\n';
                    }
                    for (auto& student : vargsiukai) {
                            fr2 << fixed << setw(20) << student.firstName << setw(20) << student.lastName;
                            fr2 << fixed << setw(20) << setprecision(1)<< student.average << '\n';
                    }
                    cout<<"Creating a fille took " << timeB <<" seconds\n";
                    cout<<"Reading from fille took " << timeT <<" seconds\n";
                    cout<<"Sorting took " << timeC <<" seconds\n";
                    cout<<"Printing out the answers took " << timeA  <<" second\n";
                    cout<<"The program took "<<timeA + timeT + timeB<<" seconds to execute\n";
                    break;

                default:
                    cout << "Invalid input";
                    break;
            }

        }
        else if(option5 == 2){
            Timer a;
            Timer c;
            switch(option4){
                case 1:
                    sort(students.begin(), students.end(), compareStudentsMED);
                    timeC = c.elapsed();
                    for (auto& i : students) {
                        if(i.median >= 5.0){
                            kietekai.push_back(i);
                        }
                        else{
                            vargsiukai.push_back(i);
                        }
                    }
                    a.elapsed();
                    break;

                case 2:
                    sort(students.begin(), students.end(), compareStudentsAVG);
                    timeC = c.elapsed();
                    for (auto& i : students) {
                        if(i.average >= 5.0){
                            kietekai.push_back(i);
                        }
                        else{
                            vargsiukai.push_back(i);
                        }
                    }
                    a.elapsed();
                    break;

                default:
                    cout << "Invalid input";
                    break;
            }
        switch(option4){
                case 1:

                    fr1 << fixed << setw(20) << "Name" << setw(20) << "LastName" << setw(25) << "Final (Med.)\n";
                    fr1 <<"--------------------------------------------------------------------------------------------\n";
                    fr2 << fixed << setw(20) << "Name" << setw(20) << "LastName" << setw(25) << "Final (Med.)\n";
                    fr2 <<"--------------------------------------------------------------------------------------------\n";
                    for (auto& student : kietekai) {
                            fr1 << fixed << setw(20) << student.firstName << setw(20) << student.lastName;
                            fr1 << fixed << setw(20) << setprecision(1)<< student.median << '\n';
                    }
                    for (auto& student : vargsiukai) {
                            fr2 << fixed << setw(20) << student.firstName << setw(20) << student.lastName;
                            fr2 << fixed << setw(20) << setprecision(1)<< student.median << '\n';
                    }
                    cout<<"Creating a fille took " << timeB <<" seconds\n";
                    cout<<"Reading from fille took " << timeT <<" seconds\n";
                    cout<<"Sorting took " << timeC <<" seconds\n";
                    cout<<"Printing out the answers took " << timeA <<" seconds\n";
                    cout<<"The program took "<<timeA + timeT +timeB<<" seconds to execute\n";
                    break;

                case 2:
                    fr1 << fixed << setw(20) << "Name" << setw(20) << "LastName" << setw(25) << "Final (Avg.)\n";
                    fr1 <<"--------------------------------------------------------------------------------------------\n";
                    fr2 << fixed << setw(20) << "Name" << setw(20) << "LastName" << setw(25) << "Final (Avg.)\n";
                    fr2 <<"--------------------------------------------------------------------------------------------\n";
                    for (auto& student : kietekai) {
                            fr1 << fixed << setw(20) << student.firstName << setw(20) << student.lastName;
                            fr1 << fixed << setw(20) << setprecision(1)<< student.average << '\n';
                    }
                    for (auto& student : vargsiukai) {
                            fr2 << fixed << setw(20) << student.firstName << setw(20) << student.lastName;
                            fr2 << fixed << setw(20) << setprecision(1)<< student.average << '\n';
                    }
                    cout<<"Creating a fille took " << timeB <<" seconds\n";
                    cout<<"Reading from fille took " << timeT <<" seconds\n";
                    cout<<"Sorting took " << timeC <<" seconds\n";
                    cout<<"Printing out the answers took " << timeA <<" second\n";
                    cout<<"The program took "<<timeA + timeT + timeB<<" seconds to execute\n";
                    break;

                default:
                    cout << "Invalid input";
                    break;
            }
        }
        else{
            cout<<"Invalid input";
        }







    return 0;
}



