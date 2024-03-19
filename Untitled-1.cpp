#include <iostream>
#include <fstream>
using namespace std;

void init(float marks[], int n_subjects);
void ReadFile(float marks[], int n_subjects, string& name, ifstream& File);
void WriteFile(float marks[], int n_subjects, string name, ofstream& output);
void calAverage(float marks[], int n_subjects, float& sum, float& percent);
char calGrade(float totalM);

int main() {

    cout << "\t\t*GRADE CALCULATOR*\n\n\n\n";

    const int n_subjects = 5;

    float marks[n_subjects];
    init(marks, n_subjects);
    float totalM = 0;


    ofstream output("output.txt");
    ifstream File("input.txt");

    string name;

    output << "Name\t\t" << "Test1\t" << "Test2\t" << "Test3\t" << "Test4\t" << "Test5\t" << "Average\t" << "Grade\n";
    while (!File.eof())
    {
        ReadFile(marks, n_subjects, name, File);
        WriteFile(marks, n_subjects, name, output);
    }
    cout << "Required Data written to output.txt." << endl;

    File.close();
    output.close();

    return 0;
}
void init(float marks[], int n_subjects)
{
    for (int i = 0; i < n_subjects; i++)
    {
        marks[i] = 0;
    }
}
void ReadFile(float marks[], int n_subjects, string& name, ifstream& File)
{
    if (!File.is_open())
    {
        cout << "File not found nigga, or can't open it nigga. You bitch nigga";
        return;
    }
    else
    {
        File >> name;
        for (int i = 0; i < n_subjects; i++)
        {
            File >> marks[i];
        }
    }
}
void WriteFile(float marks[], int n_subjects, string name, ofstream& output)
{
    float sum = 0, avg = 0;
    calAverage(marks, n_subjects, sum, avg);

    output << name << "\t\t";
    for (int i = 0; i < n_subjects; i++)
    {
        output << marks[i] << "\t";
    }
    output << avg << '\t' << calGrade(avg) << endl;
}
void calAverage(float marks[], int n_subjects, float& sum, float& percent)
{
    for (int i = 0; i < n_subjects; i++)
    {
        sum += marks[i];
    }
    percent = (sum / n_subjects);
}
char calGrade(float totalM) {
    if (totalM >= 80) {
        return 'A';
    }
    else if (totalM >= 60) {
        return 'B';
    }
    else if (totalM >= 40) {
        return 'C';
    }
    else {
        return 'F';
    }
}