#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

int main(){
    ifstream fin;
    fin.open("input");
    ofstream fout;
    fout.open("outfile");
    vector<string> info;
    int num, it, n, m;
    double cashMoney;
    string gifts, temp, name;
    getline(fin, temp);
    n = stoi(temp);

    //make map with string keys and double values
    map<string, double> paymoneywubby;

    for(int i = 0; i < n; i++){
        getline(fin, temp);
        m = stoi(temp);
        for(int j = 0; j < m; j++);{
            getline(fin, gifts);
            stringstream prices(gifts);
            info.clear();
            while(prices >> temp){
                info.push_back(temp);
            }
            if(paymoneywubby.find(info[0]) != paymoneywubby.end()){
                paymoneywubby.insert(pair<string, double>(info[0], 0));
            }
            paymoneywubby[info[0]] -= stod(info[1]);

            for(int x = 2; x < info.size(); x++){
                if(paymoneywubby.find(info[x]) != paymoneywubby.end()){
                    paymoneywubby.insert(pair<string, double>(info[x], 0));
                }
                paymoneywubby[info[x]] += (stod(info[1])/info.size() - 2);
            }
        }
        for(const auto &elem : paymoneywubby){
            fout << elem.first << " " << elem.second << endl;
        }
        fout << endl;
        paymoneywubby.clear();
    }