
#include <iostream>
#include <vector>
#include <math.h>

 //Mihalcea Cosmin, Grupa 133, SG2

 using namespace std;


 class pereche
{

 public:

     int grad;
    double coef;
    friend class polinom;
    friend istream& operator >> (istream&, pereche&);//Supra incarcarea >>
    friend ostream& operator << (ostream&, pereche&);//supra incarcarea <<


 };

 class polinom
{

     vector<pereche> P;

 public:

     friend istream& operator >> (istream&, polinom&);
    friend ostream& operator << (ostream&, polinom&);
    polinom operator * (polinom&);
    polinom operator + (polinom&);
    polinom operator - (polinom&);
    friend int evaluare (polinom&,int a);



 };

 istream& operator >> (istream& in, pereche& a)//fct de supraincarcare pt citirea perechilor
{
    cout<<"Introduceti gradul si coeficientul:\n";
    in>>a.grad>>a.coef;
    return in;

 }

 ostream& operator << (ostream& out, pereche& p)//fct de supraincarcare pt scrierea perechilor
{
    if(p.coef != 0)
    {
        if(p.coef != 1 && p.grad > 0 )
        {
            out<<p.coef;

             out<<"*";
        }
        if(p.grad > 1)
        {

             out<<"x^";
            out<<p.grad;
            out<<" + ";
        }
        else if(p.grad == 1)
        {

             out<<"x";

             out<<" + ";
        }
        if(p.grad == 0)
        {

             out<<p.coef;

         }
    }
    return out;
}

 istream& operator >> (istream& in, polinom& pa)//supraincarcarea >> la polinoame
{
    pereche a;
    in>>a;
    if(a.coef!=0)
        pa.P.push_back(a);

     do
    {

         in>>a;
        if(a.coef!=0)
            pa.P.push_back(a);

     }
    while(a.grad);

     return in;
}

 ostream& operator << (ostream& out, polinom& pa)//supraincarcarea << la polinoame
{
    for(int i=0; i<pa.P.size(); i++)
    {
        out<<pa.P[i];
    }

     return out;
}

 polinom polinom::operator + (polinom& a)//Adunare
{
    polinom suma;

     int i=0, j=0;

     while(i<a.P.size() || j<this->P.size())
    {
        pereche p1, p2;

         if(i<a.P.size())
            p1 = a.P[i];
        if(j<this->P.size())
            p2 = this->P[j];

         if(p1.grad == p2.grad)
        {
            suma.P.push_back({p1.grad, p1.coef+p2.coef});
            i++;
            j++;
        }
        else if(p1.grad>p2.grad)
        {
            suma.P.push_back(p1);
            i++;
        }
        else
        {
            suma.P.push_back(p2);
            j++;
        }
    }


     return suma;

 }

 polinom polinom::operator - (polinom &a)//Scaderea polin
{
    polinom diferenta;

     int i=0, j=0;

     while(i<a.P.size() || j<this->P.size())
    {

         pereche p1, p2;

         if(i<a.P.size())
            p1 = this->P[i];
        if(j<this->P.size())
            p2 = a.P[j];

         if(p1.grad == p2.grad)
        {
            diferenta.P.push_back({p1.grad, p1.coef - p2.coef});
            i++;
            j++;
        }
        else if(p1.grad>p2.grad)
        {
            diferenta.P.push_back({p1.grad,-p1.coef});
            i++;
        }
        else
        {
            diferenta.P.push_back(p2);
            j++;
        }
    }



     return diferenta;
}



 polinom polinom::operator * (polinom& a)//Produsul polinoamelor;
{
    polinom produs;



     for(int i=0; i<a.P.size(); i++)
    {
        pereche p1 = a.P[i];
        polinom produs_aux;


         for(int j=0; j<this->P.size(); j++)
        {
            pereche p2 = this->P[j];

             produs_aux.P.push_back({p1.grad+p2.grad,p1.coef*p2.coef});
        }

         produs = produs + produs_aux;
    }

     return produs;
//
//    return a = produs;



 }


 int main()
{
    polinom p, q, k,d;
    cin>>p>>q;
    k =  p + q;
    d =  p - q;
    cout<<k;
    cout<<"\n"<<d;

     cout<<"\n"<<evaluare(p,3);



     return 0;
}

 int evaluare(polinom &p,int a)//Evaluare;
{

     int val = 0;
    for(int i=0; i < p.P.size(); i++)
    {
        val = val + (pow(a,p.P[i].grad)*p.P[i].coef);
    }
    return val;
    return 0;
}
