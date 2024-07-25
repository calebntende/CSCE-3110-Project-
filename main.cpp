#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Option{
    string date;
    string act_symbol;
    string expiration;
    double strike;
    string call_put;
    double bid;
    double ask;
    double volume;
    double delta;
    double gamma;
    double theta;
    double vega;
    double rho;

};


int main() {
    fstream file;
    file.open("input.csv");

    if(!file.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }
    else{
        cout << "File opened successfully" << endl;
    }

    string line;
    vector<string>stuff;
    int count = 0;
    while(getline(file, line, ',')) {
        stuff.push_back(line);
        count++;
        if(count == 12) {
            break;
        }
    }

    // Output the contents of the stuff vector
    for(const auto& item : stuff) {
        cout << item << " ";
    }

    vector<Option>options;

    while(getline(file, line, ',')) {
        Option temp;
        temp.date = line;
        getline(file, line, ',');
        temp.act_symbol = line;
        getline(file, line, ',');
        temp.expiration = line;
        getline(file, line, ',');
        temp.strike = stod(line);
        getline(file, line, ',');
        temp.call_put = line;
        getline(file, line, ',');
        temp.bid = stod(line);
        getline(file, line, ',');
        temp.ask = stod(line);
        getline(file, line, ',');
        temp.volume = stod(line);
        getline(file, line, ',');
        temp.delta = stod(line);
        getline(file, line, ',');
        temp.gamma = stod(line);
        getline(file, line, ',');
        temp.theta = stod(line);
        getline(file, line, ',');
        temp.vega = stod(line);
        getline(file, line, '\n');
        temp.rho = stod(line);

        options.push_back(temp);    
    }

    for(const auto& option : options) {
        cout << option.date << " " << option.act_symbol << " " << option.expiration << " " << option.strike << " " << option.call_put << " " << option.bid << " " << option.ask << " " << option.volume << " " << option.delta << " " << option.gamma << " " << option.theta << " " << option.vega << " " << option.rho << endl;
    }

    cout << "The number of options are: " << options.size() << endl;

    



}