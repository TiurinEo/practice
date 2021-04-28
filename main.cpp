#include <iostream>
#include <vector>
#include "plant.h"
using namespace std;
vector<double>
input_m(double k){
    vector<double> result(k);
    for (int i=0;i<k;i++){
        cout<<"M"<<i<<"=";cin>>result[i];
    }
    return result;
}
vector<double>
input_a(double k){
 vector<double> result(k);
    for (int i=0;i<k;i++){
        cout<<"a"<<i<<"=";cin>>result[i];
    }
    return result;
}
vector<double>
input_b(double k){
 vector<double> result(k);
    for (int i=0;i<k;i++){
        cout<<"b"<<i<<"=";cin>>result[i];
    }
    return result;
}
vector<double>
input_g(double k){
 vector<double> result(k);
    for (int i=0;i<k;i++){
        cout<<"g"<<i<<"=";cin>>result[i];
    }
    return result;
}
void
input(double& N, double& k,vector<double>& in_channel,vector<double>& a,vector<double>& b, vector<double>& g ){
    cout<<"N=";cin>>N;
    cout<<"k=";cin>>k;
    in_channel=input_m(k);
    a=input_a(k);
    b=input_b(k);
    g=input_g(k);
}
vector<double>
find_tep1(vector<vector<double>> x,vector<double> a){
    double N=x[0].size();
    vector<double> result(N);
    for (int i=0;i<x.size();i++){
            double summ=0;
        for (int j=0;j<N;j++){
            summ+=x[i][j];
        }
    result[i]=(a[i]*summ)/N;
    }
    return result;
}
vector<double>
find_tep2(vector<vector<double>> x,vector<double> b,vector<double> g){
    double N=x[0].size();
    vector <double> result(N);
    for (int i=0;i<x.size();i++){
        double summ=0;
        for (int j=0;j<N;j++){
            summ=summ+((x[i][j]-g[i])*(x[i][j]-g[i]));
        }
        result[i]=(b[i]*summ)/N;
    }
    return result;
}

vector<double> in_channel,b,g;
vector<double> a;
double N,k;
int main()
{

   input(N,k,in_channel,a,b,g);
    Plant plant;
    plant_init(plant);
    vector<vector<double>> x(k,vector <double> (N));
    cout<<"nomer kanala";
    for (size_t i=0;i<k;i++){
            cout<<endl<<i;
        for (size_t j=0;j<N;j++){
            x[i][j]=plant_measure(in_channel[i],plant);
            cout<<"   x["<<j<<"]"<<x[i][j]<<'\t';
        }
        cout<<endl;
    }
vector<double> tep1(k),tep2(k);
tep1=find_tep1(x,a);
tep2=find_tep2(x,b,g);
for (int i=0;i<k;i++){
    cout<<"tep1["<<i<<"]="<<tep1[i]<<endl;
    cout<<"tep2["<<i<<"]="<<tep2[i]<<endl;
}

}


