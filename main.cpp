#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct Problem {
    string id_problem;
    string speciality;
};
struct Doctor {
    string id_doctor;
    string speciality;
    bool visited = false;
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
    for (const Problem& pb : p)
    {
       
            auto ans = find_if(d.begin(), d.end(), [=](Doctor& dr) {
                return dr.visited == false && pb.speciality == dr.speciality;
                });
            if (ans != d.end()) {
                ans->visited = true;
                cout << ans->id_doctor<<" "<< pb.id_problem << '\n';
            }

     
    }
    inFile.close();
    return 0;
}