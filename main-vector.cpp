#include "mylib.h"
#include "student.h"


int main() {
    ofstream fr1("Kietekai.txt");
    ofstream fr2("Vargsiukai.txt");
    vector<Student> students, vargsiukai, kietekai;
    string firstName, lastName, line;
    int grade, finalExamGrade, gradeAmount, fileSize;
    double timeT, timeB, timeC, timeA;
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
                        Student student;
                        student.setFirstName(firstName);
                        student.setLastName(lastName);
                        cout<<"Do you want to enter grades manually?(y/n)";
                        string input;
                        cin>>input;
                        if(input == "y"){
                            cout << "Enter grades for " << student.getFirstName() << ' ' << student.getLastName() << " (type '-1' when finished):\n";
                            while (cin >> grade) {
                                if (grade == -1) {
                                    break;
                                }
                                if (cin.fail()) {
                                    throw runtime_error("Invalid input");
                                }
                                if(grade <= 10 && grade > 0){
                                   student.addGrade(grade);
                                }
                                else{
                                    cout<<"Enter the number between 1 and 10. Try again: ";
                                }

                            }
                            cout << "Enter final exam grade for " << student.getFirstName() << ' ' << student.getLastName() << ":\n";
                            if (!(cin >> finalExamGrade)) {
                                throw runtime_error("Invalid input");
                            }
                            if(finalExamGrade <= 10 && finalExamGrade > 0){
                                cout << "Enter the first and last name of the student (type 'done done' when finished):\n";
                                student.setFinalExamGrade(finalExamGrade);
                                students.push_back(student);
                            }
                            else{
                                cout<<"Final exam grade can only be between 1 and 10. Try again: "; cin >> finalExamGrade;
                                cout << "Enter the first and last name of the student (type 'done done' when finished):\n";
                            }
                            student.setMedian(calculateMedian(student)*0.4+student.getFinalExamGrade()*0.6);
                            student.setAverage(calculateAverage(student)*0.4+student.getFinalExamGrade()*0.6);
                            students.push_back(student);
                        }
                        if(input == "n"){
                            int number;
                            srand(time(NULL));
                            cout<<"How many grades do you want to generate?"; cin>>number;
                            randomGradeGenerator(number,student);
                            student.setMedian(calculateMedian(student)*0.4+student.getFinalExamGrade()*0.6);
                            student.setAverage(calculateAverage(student)*0.4+student.getFinalExamGrade()*0.6);
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
            if (option2 == 1) {
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

            Student* studentPtr;

            while (getline(fd, line)) {
                stringstream ss(line);
                ss >> firstName >> lastName;
                studentPtr = new Student(); // create a new Student object
                studentPtr->setFirstName(firstName); // set first name
                studentPtr->setLastName(lastName); // set last name

                int grade;
                while (ss >> grade) {
                    studentPtr->addGrade(grade);
                }

                studentPtr->setFinalExamGrade(grade);
                vector<int> grades = studentPtr->getGrades();
                grades.pop_back();
                studentPtr->addGrade(grade);
                studentPtr->setMedian(calculateMedian(*studentPtr)*0.4+studentPtr->getFinalExamGrade()*0.6);
                studentPtr->setAverage(calculateAverage(*studentPtr)*0.4+studentPtr->getFinalExamGrade()*0.6);
                students.push_back(*studentPtr); // add the student object to the vector
            }

            delete studentPtr; // delete the pointer after the loop

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
                        if(students[i-1].getMedian() < 5){
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
                        if(students[i-1].getAverage() < 5){
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
                            fr1 << fixed << setw(20) << student.getFirstName() << setw(20) << student.getLastName();
                            fr1 << fixed << setw(20) << setprecision(1)<< student.getMedian() << '\n';
                    }
                    for (auto& student : vargsiukai) {
                            fr2 << fixed << setw(20) << student.getFirstName() << setw(20) << student.getLastName();
                            fr2 << fixed << setw(20) << setprecision(1)<< student.getMedian() << '\n';
                    }
                    cout<<"Creating a fille took " << timeB <<" seconds\n";
                    cout<<"Reading from fille took " << timeT <<" seconds\n";
                    cout<<"Sorting took " << timeC <<" seconds\n";
                    cout<<"Printing out the answers took " << timeA - timeC<<" seconds\n";
                    cout<<"The program took "<<timeA + timeT +timeB<<" seconds to execute\n";
                    break;

                case 2:
                    fr1 << fixed << setw(20) << "Name" << setw(20) << "LastName" << setw(25) << "Final (Avg.)\n";
                    fr1 <<"--------------------------------------------------------------------------------------------\n";
                    fr2 << fixed << setw(20) << "Name" << setw(20) << "LastName" << setw(25) << "Final (Avg.)\n";
                    fr2 <<"--------------------------------------------------------------------------------------------\n";
                    for (auto& student : students) {
                            fr1 << fixed << setw(20) << student.getFirstName() << setw(20) << student.getLastName();
                            fr1 << fixed << setw(20) << setprecision(1)<< student.getAverage() << '\n';
                    }
                    for (auto& student : vargsiukai) {
                            fr2 << fixed << setw(20) << student.getFirstName() << setw(20) << student.getLastName();
                            fr2 << fixed << setw(20) << setprecision(1)<< student.getAverage() << '\n';
                    }
                    cout<<"Creating a fille took " << timeB <<" seconds\n";
                    cout<<"Reading from fille took " << timeT <<" seconds\n";
                    cout<<"Sorting took " << timeC <<" seconds\n";
                    cout<<"Printing out the answers took " << timeA - timeC <<" second\n";
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
                        if(i.getMedian() >= 5.0){
                            kietekai.push_back(i);
                        }
                        else{
                            vargsiukai.push_back(i);
                        }
                    }
                    timeA = a.elapsed();
                    break;

                case 2:
                    sort(students.begin(), students.end(), compareStudentsAVG);
                    timeC = c.elapsed();
                    for (auto& i : students) {
                        if(i.getAverage() >= 5.0){
                            kietekai.push_back(i);
                        }
                        else{
                            vargsiukai.push_back(i);
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
                    for (auto& student : kietekai) {
                            fr1 << fixed << setw(20) << student.getFirstName() << setw(20) << student.getLastName();
                            fr1 << fixed << setw(20) << setprecision(1)<< student.getMedian() << '\n';
                    }
                    for (auto& student : vargsiukai) {
                            fr2 << fixed << setw(20) << student.getFirstName() << setw(20) << student.getLastName();
                            fr2 << fixed << setw(20) << setprecision(1)<< student.getMedian() << '\n';
                    }
                    cout<<"Creating a fille took " << timeB <<" seconds\n";
                    cout<<"Reading from fille took " << timeT <<" seconds\n";
                    cout<<"Sorting took " << timeC <<" seconds\n";
                    cout<<"Printing out the answers took " << timeA - timeC <<" seconds\n";
                    cout<<"The program took "<<timeA + timeT +timeB<<" seconds to execute\n";
                    break;

                case 2:
                    fr1 << fixed << setw(20) << "Name" << setw(20) << "LastName" << setw(25) << "Final (Avg.)\n";
                    fr1 <<"--------------------------------------------------------------------------------------------\n";
                    fr2 << fixed << setw(20) << "Name" << setw(20) << "LastName" << setw(25) << "Final (Avg.)\n";
                    fr2 <<"--------------------------------------------------------------------------------------------\n";
                    for (auto& student : kietekai) {
                            fr1 << fixed << setw(20) << student.getFirstName() << setw(20) << student.getLastName();
                            fr1 << fixed << setw(20) << setprecision(1)<< student.getAverage() << '\n';
                    }
                    for (auto& student : vargsiukai) {
                            fr2 << fixed << setw(20) << student.getFirstName() << setw(20) << student.getLastName();
                            fr2 << fixed << setw(20) << setprecision(1)<< student.getAverage() << '\n';
                    }
                    cout<<"Creating a fille took " << timeB <<" seconds\n";
                    cout<<"Reading from fille took " << timeT <<" seconds\n";
                    cout<<"Sorting took " << timeC <<" seconds\n";
                    cout<<"Printing out the answers took " << timeA - timeC <<" second\n";
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


