#include <iostream>

using namespace std;


    class Complex{
        float im,re;
    public:
        float get_re(){
            return re;
        }
        float get_im(){
            return im;
        }
        friend istream& operator >> (istream&, Complex&); //supraincarcare >>
        friend ostream& operator << (ostream&, Complex&); //supraincarcare <<
        Complex operator = (Complex&);
        Complex(float re = 0,float im =0){
            this ->re = re;
            this ->im = im;
        }
        ~Complex(){
            this ->re =0;
            this ->im =0;
        }
      Complex(const Complex &ob)
{
 this ->re = ob.re;
 this ->im = ob.im;
}

    };

    class matrice: public Complex{
//        Complex**v;
    public:
        Complex**v;

        virtual void citire(matrice&) = 0;
        virtual void scriere()= 0;



    };

    class matrice_oarecare: public matrice{
        int linii;
        int coloane;
    public:

        matrice_oarecare(int l,int c){
            this->coloane = c;
            this->linii = l;

            v = new Complex*[linii];
            for(int i = 0; i < linii;i++)
                v[i] = new Complex[coloane];
        }

        friend istream& operator >> (istream&, matrice_oarecare&); //supraincarcare >>
        friend ostream& operator << (ostream&, matrice_oarecare&); //supraincarcare <<
        matrice_oarecare operator = (matrice_oarecare&);
        void citire(matrice&a){
            matrice_oarecare b;
            cin>>a;
        }
        void scriere(){

        }






    };

    istream& operator >>(istream& in,matrice_oarecare& a){

        for(int i = 0; i < a.linii;i++){
            for(int j = 0 ; j< a.coloane; j++){
                in>>a.v[i][j];
            }
        }
        return in;
    }
    ostream& operator <<(ostream& out,matrice_oarecare& a){
        for(int i = 0; i < a.linii; i++){
            for(int j=0;j<a.coloane;j++){
                out<<a.v[i][j]<<" ";
            }
            out<<"\n";
        }
        return out;
    }





    istream& operator >>(istream& in, Complex& a){
        cout<<"Introduceti partea reala, apoi cea imaginara:\n";
        in>>a.re>>a.im;
        return in;
    }
    ostream& operator <<(ostream& out, Complex& a){
        if(a.get_re() == 0 && a.get_im()!=0){
            cout<<a.get_im()<<"i";
            return out;
        }
        if(a.get_im() == 0 && a.get_re() != 0){
            cout<<a.get_re();
            return out;
        }
        if(a.get_im() == 0 && a.get_re()== 0){
            cout<<a.get_re()<<"";
            return out;
        }
        cout<<a.get_re()<<" + "<<a.get_im()<<"i";
        return out;
    }


    Complex Complex::operator=(Complex&a){
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
    matrice_oarecare a(2,2);
    cin>>a;
    cout<<a;




    return 0;
}
