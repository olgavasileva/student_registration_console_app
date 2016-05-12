#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void modifystudent();
void disp();
void displaysingle();
int getgenderchoice();
int getstudychoice();

string switchgender();
void newRecord();
int quit();
void displayall();
void search();
void deleteStudent();
string filename;



/*******************************      set filename    *******************************/
string setfilename(){
    cout << "Enter a filename to read/write from it, for ex: record.txt :" << endl;
    cin.get();
    getline(cin, filename);
    return filename;
}


/*******************************      main menu    *******************************/
int getchoice() {
int choice;
cout << "1. Add Records" << endl;
cout << "2. List Records" << endl;
cout << "3. Modify Records" << endl;
cout << "4. Delete Records" << endl;
cout << "5. Exit" << endl;
cout << "Select Your Choice :=>" << endl;
cin >> choice;
return choice;
}


/*******************************        main       *******************************/
int main() {
int choice = getchoice();

    switch (choice){
    case 1:
        newRecord();
        break;
    case 2:
        disp();
        break;
    case 3:
        modifystudent();
        break;
    case 4:
        deleteStudent();
        break;
    case 5:
        quit();
        break;
    default:
        getchoice();
        break;
        cin.get();
    }
}


/*******************************      switch for gender    *******************************/
string switchgender(){
    string gender;
   int genderId = getgenderchoice();
switch (genderId){
case 1:
    gender = "Female";
    break;
case 2:
    gender = "Male";
    break;
default:
    gender = switchgender();
    break;
}
return gender;
}


/*******************************      switch for year    *******************************/
string switchyear(){
    string year;
int yearId = getstudychoice();
switch (yearId){
case 1:
    year = "Freshman";
    break;
case 2:
    year = "Sophomore";
    break;
case 3:
    year = "Junior";
    break;
case 4:
    year = "Senior";
    break;
default:
    year = switchyear();
    break;
}
return year;
}

/*******************************      menu for year    *******************************/
int getstudychoice(){
int yearId;
cout << endl;
cout << "Enter the new student's year of study number:" << endl;
cout << "1. Freshman " << endl;
cout << "2. Sophomore" << endl;
cout << "3. Junior" << endl;
cout << "4. Senior" << endl;
cin >> yearId;
return yearId;
}


/*******************************      menu for gender    *******************************/
int getgenderchoice(){
//Gender
    int genderId;
cout << endl;
cout << "Enter the new student's gender:" << endl;
cout << "1. Female " << endl;
cout << "2. Male" << endl;
cin >> genderId;
return genderId;
}



/*******************************      new record    *******************************/
void newRecord()
{
    int i = 0;
    string name;
    string id;
    string idFromFile;
    string year;
    string gender;
    bool error = true;
    bool isRecordExist = false;
    bool isContainChar = false;

   filename = (filename.empty())? setfilename() : filename;
   ofstream newRec(filename, ios::app);
   ifstream studentRecord(filename);
    cout << "Enter the new student's id (9 digits long)" << endl;

    //Running the validation for the ID
    while (error == true){
        error = false;
        i = 0;
        cin >> id;

        //Check if id is 9 digits
        if (!(id.length() == 9)){
            cout << "ERROR: Student ID has to be 9 digits long." << endl;
            error = true;
        }

        //Check if id is used already
        while (studentRecord >> idFromFile){
            if (idFromFile == id)
                isRecordExist = true;
        }

        if (isRecordExist == true){
            cout << "ERROR: Student id exists." << endl;
            error = true;
        }

        //Check if there are chars in ID
        while (i < id.length()){
            if (!isdigit(id[i]))
                isContainChar = true;
            i++;
        }

        if (isContainChar == true){
            cout << "ERROR: Student ID contains characters." << endl;
            isContainChar = false;
            error = true;
        }
        if (error == true)
             newRecord();
    }


    //Student name
    cout << endl;
    cout << "Enter the new student's first and last name" << endl;
    cin.get();
    getline(cin, name);
    year = switchyear();
    gender = switchgender();


    cout << endl;
    cout << "Student record was added" << endl;
    cout << "-------------------------------" << endl;
    cout << id << ' ' << name << ' ' << year << ' ' << gender << ' ' << endl;
    cout << endl;
    newRec << id << ' ' << name << ' ' << year << ' ' << gender << ' ' << endl;
    newRec.close();
    main();

}



/*******************************   Display a Student by ID   *******************************/
void displaysingle(){

    string name, lastname;
    string id;
    string year;
    string gender;
       filename = filename.empty()? setfilename() :filename;
    ifstream student(filename); //File to read from
    string inputID;
    char c;
    bool found = false;

    cout << "Enter ID of a student you would like to display or (q) for main menu" << endl;
    cin >> inputID;
   if (inputID == "q")
           main();
   else{
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "Student: " << endl;
    while (student >> id >> name >> lastname>> year >> gender){
        if (inputID == id){
            cout << id << ' ' << name << lastname<< ' ' << year << ' ' << gender << ' ' << endl;
            found = true;
        }
    }
    student.close();
    if (found == false){
        cout << "No Record Found" << endl;
        displaysingle();
    }
    cout << "---------------------------" << endl;
    cout << "Display another record? (y/n)";
    cin >> c;
            switch(c){
                case 'y':
                    displaysingle();
                    break;
                case 'n':
                    main();
                    break;
            default:
                main();
                break;

            }
}}

/*******************************   modify menu   *******************************/
int modification(){
    int choice;
    cout << endl;
    cout << "What would you like to change?" << endl;
    cout << "1. Name and Lastname " << endl;
    cout << "2. Year" << endl;
    cout << "3. Gender" << endl;
    cin >> choice;
    return choice;


}


/*******************************   modify Student   *******************************/
void modifystudent(){
    string name, lastname, newname, newlastname;
    string id;
    string year, newyear;

    string gender, newgender;
       filename = filename.empty()? setfilename() :filename;
    ifstream filein(filename.c_str());
    ifstream newRec(filename.c_str());
    ofstream fileout("temp.txt"); //Temporary file
    string inputID;
    char c = 'y';
    bool confirm = false;
    bool found = false;
    int result, choice;

    cout << "Enter ID of a student you would like to modify or (q) for main menu" << endl;
    cin >> inputID;
    if (inputID == "q")
        main();
    else{
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "Modifying student: " << endl;
    while (newRec >> id >> name >> lastname>> year >> gender){
        if (inputID == id){
            cout << id << ' ' << name << ' ' << lastname << ' ' << year << ' ' << gender << ' ' << endl;
            found = true;
        }
    }
    newRec.close();
    if (found == false){
        cout << "No such record" << endl;
        modifystudent();
    }

    while (c == 'y'){
   choice = modification();

   switch(choice){
       case 1:
           cout << "Enter new first and last name" << endl;
           cin.get();
           getline(cin, newname);
            break;
       case 2:
       newyear = switchyear();
            break;
       case 3:
        newgender = switchgender();
        break;
       default:
       modification();
           break;
   }

   cout << "Please type (y/n) if you'd like to change more info about this Student: " << endl;
   cin >> c;
    }
    name = (!newname.empty())? newname : name;
    year = (!newyear.empty())? newyear : year;
    gender = (!newgender.empty())? newgender : gender;
    cout << "---------------------------" << endl;
    cout << "Please type (y/n) to confirm changes to: " << endl;

    cout << inputID << ' ' <<name << ' ' << year << ' ' << gender << ' ' << endl;
    cin >> c;

    switch(c){
        case 'y':
            confirm = true;
            break;
        case 'n':
            confirm = false;
            modifystudent();
            break;
    }


    if (confirm == true){
        if (!filein || !fileout)
            cout << "Error opening files!" << endl;
        while (filein >> id >> name >> lastname >> year >> gender)
        {
            if (id == inputID){
                name = (!newname.empty())? newname : name;
                year = (!newyear.empty())? newyear : year;
                gender = (!newgender.empty())? newgender : gender;

                fileout << id << ' ' <<name << ' ' << year << ' ' << gender << ' ' << endl;

            }
            else
                fileout << id << ' ' << name << ' ' << lastname << ' ' << year << ' ' << gender << ' ' << endl;
        }

        filein.close();
        fileout.close();
        remove(filename.c_str());
        result = rename("temp.txt", filename.c_str());
        if (result == 0)
            cout << "Successfully changed the student info!" << endl;
        else
            cout << "Error deleting file" << endl;
        cout << endl;
    }
    main();
}}


/*******************************   Delete a student by student ID   *******************************/
void deleteStudent()
{
    string name, lastname;
    string id;
    string year;
filename = filename.empty()? setfilename() :filename;
    string gender;
    ifstream filein(filename.c_str()); //File to read from
    ifstream newRec(filename.c_str()); //File to read from
    ofstream fileout("temp.txt"); //Temporary file
    string inputID;
    char c;
    bool confirm = false;
    bool found = false;

    int result;

    cout << "Enter ID of a student you would like to delete or (q) for main menu" << endl;
    cin >> inputID;
    if (inputID == "q")
        main();
    else{
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "Deleting student: " << endl;
    while (newRec >> id >> name >> lastname>> year >> gender){
        if (inputID == id){
            cout << id << ' ' << name << ' ' << lastname << ' ' << year << ' ' << gender << ' ' << endl;
            found = true;
        }
    }
    newRec.close();
    if (found == false){
        cout << "No such record" << endl;
        deleteStudent();
    }
    cout << "---------------------------" << endl;
    cout << "Please type \"y/n\" to confirm: " << endl;
    cin >> c;

    switch(c){
        case 'y':
            confirm = true;
            break;
        case 'n':
            confirm = false;
            deleteStudent();
            break;
    }


    if (confirm == true){
        if (!filein || !fileout)
            cout << "Error opening files!" << endl;
        while (filein >> id >> name >> lastname >> year >> gender)
        {
            if (id == inputID){
                ;
            }
            else
                fileout << id << ' ' << name << ' ' << lastname << ' ' << year << ' ' << gender << ' ' << endl;
        }

        filein.close();
        fileout.close();
        remove(filename.c_str());
        result = rename("temp.txt", filename.c_str());
        if (result == 0)
            cout << "Successfully deleted the student !" << endl;
        else
            cout << "Error deleting file" << endl;
        cout << endl;
    }
    main();
}}


/*******************************   Display all student records   *******************************/
void displayall(){
    ifstream studentRecords(filename);
    string id;
    string name, lastname;
    string year;
    string gender;

    cout << endl;
    cout << "All Students" << endl;
    cout << "ID" << "        " << "Name" << "           " << "Year" << ' ' << "Gender" << endl;
    cout << "----------------------------------------" << endl;

    while (studentRecords >> id >> name >> lastname >> year >> gender){
    cout << id << ' ' << name << ' ' << lastname << ' ' << year << ' ' << gender << endl;}
    cout << "----------------------------------------" << endl;

    cout << endl;
    studentRecords.close();
    main();
}


/*******************************   Display menu   *******************************/
void disp(){
    filename = filename.empty()? setfilename() :filename;
    cout << endl;
    cout << "1. Display all Records." << endl;
    cout << "2. Display individual Record." << endl;
    int choice3;
     cin >> choice3;
    switch (choice3){
    case 1:
        displayall();
        break;
    case 2:
        displaysingle();
        break;
        cin.get();
    }
}


/*******************************      Exit       *******************************/
int quit()
{
    char opt;
    cout << "Are you sure you'd like to exit? (y/n)" << endl;
    cin >> opt;

    if (opt =='y')
    return 0;
    else
        main();
}



