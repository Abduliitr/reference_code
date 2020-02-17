#include <fstream>
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

bool sortinrev(const pair<int,int> &a, const pair<int,int> &b){ 
       return (a.first > b.first); 
}

int main(int argc, char** argv){

    ifstream inFile;
    
    inFile.open(argv[1]);

    ofstream outFile (argv[2]);

    if(!inFile){
        cout << "Error" << endl;
        exit(1);
    }

    int max_slices, types_of_pizza;
    inFile >> max_slices;
    inFile >> types_of_pizza;
    // inFile >> max_slices >> types_of_pizza;
    vector<pair<int,int> > A(types_of_pizza);
    for(int i=0;i<types_of_pizza;i++){
        int a;
        inFile >> a;
        A[i].first = a;
        A[i].second = i;
    }

    sort(A.begin(),A.end(), sortinrev);

    vector<int> result;

    for(int i=0;i<A.size();i++){
        if(A[i].first <= max_slices){
            result.push_back(A[i].second);
            max_slices-=A[i].first;
        }
        // else break;
    }

    sort(result.begin(),result.end());
    outFile << result.size() << "\n";

    for(int i=0;i<result.size();i++){
        outFile << result[i] << " ";
    }
    // cout << endl;

    // outFile.write(result, result.size());

    // cout.write("output.out");
    inFile.close();
    outFile.close();
}
