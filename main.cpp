#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

using namespace std;
struct Problem {
    string id_problem;
    string speciality;
    int ora_sosire;
    int priority;
    int durata;
    bool operator> (const Problem& other) const {
        return this->priority > other.priority;
    }
};
struct Doctor {
    string id_doctor;
    int nr_spec;
    vector<string> specialities;
    int available_time = 9;

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
        //inFile >> pb.ora_sosire;
        inFile >> pb.durata;
        inFile >> pb.priority;
    }
    multiset<Problem, greater<Problem>> sorted_problems(p.begin(), p.end());

    inFile >> no_doctors;
    vector<Doctor>d(no_doctors);
    for(auto &dr : d){
        inFile >> dr.id_doctor;
        inFile >> dr.nr_spec;
        for (int i = 1; i <= dr.nr_spec; i++) {
            string spec;
            inFile >> spec;
            dr.specialities.emplace_back(spec);
        }
    }
    
    for (const Problem& pb : sorted_problems) {
        bool visited = false;
        for (Doctor& dr : d) {
            if (find(dr.specialities.begin(), dr.specialities.end(), pb.speciality) != dr.specialities.end() && dr.available_time <= 17) {
                cout << dr.id_doctor << " " << pb.id_problem << '\n';
                dr.available_time += pb.durata;
                visited = true;
                break;
            }
        }

        if (!visited) {
            cout << "Nu exista doctor disponibil pentru problema " << pb.id_problem << endl;
        }
    }


    inFile.close();
    return 0;
}