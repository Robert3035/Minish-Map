#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    ifstream fin;
    fin.open("input");
    ofstream fout;
    fout.open("outfile");
    vector<int> nums;
    vector<int> flip;
    int num, it;
    //make map with int keys and values
    unordered_map<int, int> numit;

    //add numbers from the input file to vector
    while(fin >> num){
        nums.push_back(num);
    }
    //go through every number in nums
    for(int i = 0; i < nums.size(); i++){
        //if number is not in map, add it
        if(numit.find(nums[i]) == numit.end()){
            numit.insert(pair<int, int>(nums[i], 1));
        }
        //if number is in map, add one to the key's value
        else
        numit[nums[i]]++;
    }
    for(auto const &elem : numit){
        flip.push_back(elem.first);
        flip.push_back(elem.second);
    }
    for(int i = flip.size() - 1; i > 0; i -= 2){
        fout << flip[i-1] << " " << flip[i] << endl;
    }
}