#include <iostream>
using namespace std;

int count = 0;

void Add_student(int rArr[], string nArr[], double mArr[])
{
    cout << "Enter the roll No of student : ";
    cin >> rArr[count];
    cout << "Enter the Name of student : ";
    cin >> nArr[count];
    cout << "Enter the marks of student : ";
    cin >> mArr[count];
    count++;
}

void display(int rArr[], string nArr[], double mArr[])
{
    int i = 0;
    while (i < count)
    {
        cout << "----------------------------------------------------------------------------------|" << endl;
        cout << "- Sr.No - \t\tRoll # - \t\tName - \t\t\tMarks -" << endl;
        cout << "     " << i + 1 << " - \t\t" << rArr[i] << " - \t\t\t" << nArr[i] << " - \t\t" << mArr[i] << "   |" << endl;
        cout << "----------------------------------------------------------------------------------|" << endl;
        i++;
    }
}

void search(int rArr[], string nArr[], double mArr[])
{
    int Search = 0;

    int roll;
    cout << "Enter the Roll # of student to chcek details : ";
    cin >> roll;
    while (Search <= count)
    {
        if (roll == rArr[Search])
        {
            cout << "Roll no of the Student : " << rArr[Search] << endl;
            cout << "Name of the Student : " << nArr[Search] << endl;
            cout << "Marks of the Student : " << mArr[Search] << endl;
            return;
        }
        else if (roll != rArr[Search])
        {
            Search++;
        }
    }
    cout << "Student Record Not Found : " << endl;
}

void update(int rArr[], string nArr[], double mArr[])
{
    int upd = 0;

    int roll;
    cout << "Enter the Roll # of student to update details : ";
    cin >> roll;
    while (upd <= count)
    {
        if (roll == rArr[upd])
        {
            cout << "Enter new Roll no of the Student : " ;
            cin >> rArr[upd];
            cout << "Enter the name of the Student : " ;
            cin >> nArr[upd];
            cout << "Enter the marks of the Student : " ;
            cin >> mArr[upd];
            
            return;
        }
        else if (roll != rArr[upd])
        {
            upd++;
        }
    }
    cout << "Student Record Not Found : " << endl;
}

void del(int rArr[], string nArr[], double mArr[])
{
    int del = 0;
    int roll;
    cout << "Enter the Roll # of student to delete his details : ";
    cin >> roll;
    while (del < count)
    {
        if (roll == rArr[del])
        {
            for (int i=0 ; i<count-1 ; i++)
            {
                rArr[i] = rArr[i + 1];
                nArr[i] = nArr[i + 1];
                mArr[i] = mArr[i + 1];
                del++;
            }
            count--;
            cout << "Record Deleted Successfully " << endl;
            return;
        }
        else if (roll != rArr[del])
        {
            del++;
        }
    }
    cout << "Student Record Not Found : " << endl;
}

int main()
{
    cout << "---------------------------- Welcome to Student Registration System ------------------|" << endl;
    int *RArr = new int[100];
    string *NArr = new string[100];
    double *MArr = new double[100];
    int choice;
    do
    {
        cout << "Select From the Following Options..... \n1. Add Student (Enter 1) :  \n2. Display Students (Enter 2) : \n3. Search Students (Enter 3) : \n4. Update Student Details (Enter 4) : \n5. Delete Student (Enter 5) : \n6. Exit the system (Enter 6) : \nWhats Your Choice  " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            Add_student(RArr, NArr, MArr);
            break;
        case 2:
            if (count == 0)
            {
                cout << "The record is empty " << endl;
            }
            else
            {
                display(RArr, NArr, MArr);
            }
            break;
        case 3:
            if (count == 0)
            {
                cout << "The record is empty " << endl;
            }
            else
            {
                search(RArr, NArr, MArr);
            }
            break;
        case 4:
            if (count == 0)
            {
                cout << "The record is empty " << endl;
            }
            else
            {
                update(RArr, NArr, MArr);
            }
            break;
        case 5:
            if (count == 0)
            {
                cout << "The record is empty " << endl;
            }
            else
            {
                del(RArr, NArr, MArr);
            }
            break;
        case 6:
            break;
        default:
            break;
        }
    } while (choice != 6);
    delete[] RArr;
    delete[] NArr;
    delete[] MArr;
}