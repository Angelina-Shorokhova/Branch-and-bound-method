#include "Parser.h"
#include <iostream>
#include <ctime>
#include <math.h>
#include <list>
using namespace std;

class Solver: public  Parser{
public:
struct elem{
 int v;
 int w;
 int ind;
 int ub;
};
elem create(int v1,int w1,int ind1,int ub1);
bool compare(const elem f, const elem s);
double max_price(int first);
double upper_bound(int el_v,int el_w,int num);
Solver(string f_name);
};