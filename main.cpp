#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
struct Problem {
    string id_problem;
    string speciality;
};
struct Doctor {
    string id_doctor;
    string speciality;
};

int main()
{
    ifstream inFile("input.txt");

    int no_problems, no_doctors;
    inFile >> no_problems;
    vector<Problem>p(no_problems);
    for (Problem &pb : p)
    {
        inFile >>pb.id_problem;
        inFile >> pb.speciality;
    }
    

    inFile >> no_doctors;
    vector<Doctor>d(no_doctors);
    for(Doctor &dr : d)
    {
        inFile >> dr.id_doctor;
        inFile >> dr.speciality;
    }
    bool ok;
    for (const Problem& pb : p)
    {
        ok = false;
        for (const Doctor& dr : d)
        {
            if (pb.speciality == dr.speciality)
                ok = true;
        }
        if(ok)
            cout << pb.id_problem << " " << "Acceptat" << '\n';
        else
            cout << pb.id_problem << " " << "Respins" << '\n';
    }
    inFile.close();
    return 0;
}