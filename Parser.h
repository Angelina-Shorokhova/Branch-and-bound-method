#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

class Parser{
protected:
ifstream file;
public:   
int n, K;
int* v;
int* w;
Parser(string f_name);

~Parser();
 
};