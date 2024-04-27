#include "Solver.h"
#include <iostream>

using namespace std;



Solver::elem Solver::create(int v1,int w1,int ind1,int ub1){
    elem* tmp=new elem;
    tmp->v=v1;
    tmp->w=w1;
    tmp->ind=ind1;
    tmp->ub=ub1;
    return *tmp;
} 

bool Solver::compare(const Solver::elem f, const Solver::elem s){
    return (f.ub)>(s.ub);
}

double Solver::max_price(int first){
    double max=-1;
    for(int i=first;i<n;i++){
        if(v[i]/w[i]>max){
          max=v[i]/w[i];
        } 
    }
    return max;
}

double Solver::upper_bound(int el_v,int el_w,int num){
    return el_v+ (K-el_w)*max_price(num);
}


Solver::Solver(string f_name): Parser(f_name){
list<elem> tree={};
list<elem>::iterator it;
int t_w=0,t_v=0;
Solver::elem t;
t=create(t_v,t_w,0,upper_bound(t_v,t_w,0));
tree.push_back(t);
for(int i=0;i<n;i++){
  tree.sort(compare);
  tree.pop_front();
  t=create(t_v,t_w,i+1,upper_bound(t_v,t_w,i));
  if(t_w<K) tree.push_back(t);
  else t.ub=0;
  t_v+=v[i];
  t_w+=w[i];
  t=create(t_v,t_w,i+2,upper_bound(t_v,t_w,i));
  if(t_w<K) tree.push_back(t);
  else t.ub=0;
}
tree.sort(compare);
it=tree.begin();
cout<<"t_v= "<<it->v<<endl;
cout<<"t_w= "<<it->w<<endl;
cout<<"num= "<<it->ind<<endl;
cout<<"ub= "<<it->ub<<endl;
for (it=tree.begin();it!=tree.end();it++)
  cout<<it->v<<" ";
cout<<endl;




}