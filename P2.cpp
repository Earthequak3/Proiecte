#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

void submatrice(long int n,long int lin,long int col,float a[50][50],float b[50][50])
{
    int i,j,c=0,l=1;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if(j!=col&&i!=lin)
            {
                c++;
                if(c==n)
                {
                    c=1;
                    l++;
                }
                b[l][c]=a[i][j];
            }
}

float det(float a[50][50],long int n)
{


    long int part,i,s=0;
    float b[50][50];
    if(n==1)
    {
        s=a[1][1];
    }
    if(n==2)
    {
        s=a[1][1]*a[2][2]-a[1][2]*a[2][1];
    }
    else
    {
        for(i=1; i<=n; i++)
        {
            submatrice(n,1,i,a,b);
            s+=a[1][i]*pow(-1,i+1)*det(b,n-1);
        }
    }
    return s;
}


class Complex
{
    float im,re;
public:
    float get_re()
    {
        return re;
    }
    float get_im()
    {
        return im;
    }
    friend istream& operator >> (istream&, Complex&); //supraincarcare >>
    friend ostream& operator << (ostream&, Complex&); //supraincarcare <<
    Complex operator = (Complex&);
    Complex(float re = 0,float im =0)
    {
        this ->re = re;
        this ->im = im;
    }
    ~Complex()
    {
        this ->re =0;
        this ->im =0;
    }
    Complex(const Complex &ob)
    {
        this ->re = ob.re;
        this ->im = ob.im;
    }

};

class matrice: public Complex
{
//        Complex**v;
public:
    Complex**v;

    virtual void citire() = 0;
    virtual void scriere()= 0;



};

//MATRICE OARECARE

class matrice_oarecare: public matrice
{
    int linii;
    int coloane;
public:

    matrice_oarecare(int l,int c)
    {
        this->coloane = c;
        this->linii = l;

        v = new Complex*[this->linii];
        for(int i = 0; i < this->linii; i++)
            v[i] = new Complex[this->coloane];
    }

    friend istream& operator >> (istream&, matrice_oarecare&); //supraincarcare >>
    friend ostream& operator << (ostream&, matrice_oarecare&); //supraincarcare <<
    matrice_oarecare operator = (matrice_oarecare&);
    ~matrice_oarecare()
    {
        cout<<"Destructor apelat\n";
        delete v;
    }

    void citire()
    {

        cin>>*(this);

    }

    void scriere()
    {

        cout<<*(this);



    }

    matrice_oarecare (const matrice_oarecare& a);

};

//MATRICE PATRATICA

class matrice_patratica:public matrice
{
    int dim;
public:
    matrice_patratica(int n)
    {
        this->dim = n;
        v = new Complex*[this->dim];
        for(int i = 0; i < this->dim; i++)
            v[i] = new Complex[this->dim];
    }
    ~matrice_patratica()
    {
        delete v;
        cout<<"destructor apelat\n";
    }

    friend istream& operator >> (istream&, matrice_patratica&); //supraincarcare >>
    friend ostream& operator << (ostream&, matrice_patratica&); //supraincarcare <<
    matrice_patratica operator = (matrice_patratica&);
    void citire()
    {
        cin>>*(this);
    }
    void scriere()
    {
        cout<<*(this);

        if(this->dim == 2)
        {
cout<<((this->v[0][0].get_re()*this->v[1][1].get_re() - this->v[0][0].get_im()*this->v[1][1].get_im()) - (this->v[0][1].get_re()*this->v[1][0].get_re() - this->v[0][1].get_im()*this->v[1][0].get_im()));
cout<<" + "<<((this->v[0][0].get_re()*this->v[1][1].get_im() + this->v[0][0].get_im()*this->v[1][1].get_re()) - (this->v[0][1].get_re()*this->v[1][0].get_im()
                                                                                                                 + this->v[0][1].get_im()*this->v[1][0].get_re()))<<"i\n";


    }
    }
};

istream& operator >>(istream& in,matrice_patratica& a)
{

    for(int i = 0; i < a.dim; i++)
    {
        for(int j = 0 ; j< a.dim; j++)
        {
            in>>a.v[i][j];
        }
    }
    return in;
}
ostream& operator <<(ostream& out,matrice_patratica& a)
{
    for(int i = 0; i < a.dim; i++)
    {
        for(int j=0; j<a.dim; j++)
        {
            out<<a.v[i][j]<<"    ";
        }
        out<<"\n\n";
    }
    return out;
}

matrice_patratica matrice_patratica::operator=(matrice_patratica&ob)
{
    int i,j;
    for(i=0; i<this->dim; i++)
    {
        for(j=0; j<this->dim; j++)
        {
            this->v[i][j]=ob.v[i][j];
        }
    }

}


istream& operator >>(istream& in,matrice_oarecare& a)
{

    for(int i = 0; i < a.linii; i++)
    {
        for(int j = 0 ; j< a.coloane; j++)
        {
            in>>a.v[i][j];
        }
    }
    return in;
}
ostream& operator <<(ostream& out,matrice_oarecare& a)
{
    for(int i = 0; i < a.linii; i++)
    {
        for(int j=0; j<a.coloane; j++)
        {
            out<<a.v[i][j]<<"    ";
        }
        out<<"\n\n";
    }
    return out;
}

matrice_oarecare matrice_oarecare::operator=(matrice_oarecare&ob)
{
    int i,j;
    for(i=0; i<this->linii; i++)
    {
        for(j=0; j<this->coloane; j++)
        {
            this->v[i][j]=ob.v[i][j];
        }
    }

}

istream& operator >>(istream& in, Complex& a)
{
    cout<<"Introduceti partea reala, apoi cea imaginara:\n";
    in>>a.re>>a.im;
    return in;
}
ostream& operator <<(ostream& out, Complex& a)
{
    if(a.get_re() == 0 && a.get_im()!=0)
    {
        cout<<a.get_im()<<"i";
        return out;
    }
    if(a.get_im() == 0 && a.get_re() != 0)
    {
        cout<<a.get_re();
        return out;
    }
    if(a.get_im() == 0 && a.get_re()== 0)
    {
        cout<<a.get_re()<<"";
        return out;
    }
    cout<<a.get_re()<<" + "<<a.get_im()<<"i";
    return out;
}


Complex Complex::operator=(Complex&a)
{
    this->re = a.re;
    this->im = a.im;
}

int main()
{

//    Complex a,b,c;
//    cin>>a;
//    Complex h(a);
//    c = b;
//    cout<<a<<b<<c<<h;
//    matrice_oarecare a(2,2);
//    matrice_oarecare b(2,1);
//    matrice_oarecare c(2,1);
//
//
//    b.citire();
////    b.scriere();
//
//    c = b;
//    c.scriere();

matrice_patratica a(2);
a.citire();
a.scriere();






    return 0;
}

