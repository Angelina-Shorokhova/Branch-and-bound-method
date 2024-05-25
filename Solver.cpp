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
    if(el_w>=K) return 0;
    int num1=num+1;
    while ((num1<n)&&(w[num1]+el_w<=K)){
      el_w+=w[num1];
      el_v+=v[num1];
      num1+=1;
    }
    if(num1<n)
    el_v+=(K-el_w)*v[num1]/w[num1];
    return el_v;
}


Solver::Solver(string f_name): Parser(f_name){
vector<elem> tree={};
vector<elem>::iterator it;
int t_w=0,t_v=0,great_val=0,ind2;
elem t,t2;
t=create(t_v,t_w,-1,0);
tree.push_back(t);
while(tree.size()>0){
   t=tree[0];
   tree.erase(tree.begin());
   ind2=t.ind+1;
   if(t.ind==-1) ind2=0;
   t2=create(t.v+v[ind2],t.w+w[ind2],ind2,upper_bound(t.v+v[ind2],t.w+w[ind2],ind2));
   if((t2.v>great_val)&&(t2.w<=K)) great_val=t2.v;
   if(t2.ub>great_val) tree.push_back(t2);
   t2.w=t.w;
   t2.v=t.v;
   t2.ub=upper_bound(t_v,t_w,ind2);
   if(t2.ub>great_val) tree.push_back(t2);
}

/* it=tree.begin();
cout<<"t_v= "<<it->v<<endl;
cout<<"t_w= "<<it->w<<endl;
cout<<"num= "<<it->ind<<endl;
cout<<"ub= "<<it->ub<<endl;
*/

cout<<"sum value="<<great_val<<endl;


}
