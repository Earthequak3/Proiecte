#include <iostream>
#include <conio.h>
#include <string.h>
#include <vector>
using namespace std;


class Automobil{
   float lungime;
    char model[20];

public:
   float get_l(){
        return lungime;
    }
    char *get_c(){
        return model;
    }
virtual void scriere(){};
friend istream& operator >> (istream&, Automobil&);

};
 istream& operator >> (istream&in, Automobil&a){
    cout<<"Model + Lugime\n";
   in>>a.model>>a.lungime;
   return in;
}

//MINI

class MINI : public Automobil{
   static int mini;
   float l;
    char model[20];
public:
    int get_mini(){
        return mini;

    }

    void scriere(){
cout<<*this;



    }

    friend ostream& operator << (ostream&, MINI&);
    friend istream& operator >> (istream&, MINI&);

};
    ostream& operator << (ostream& o, MINI&mimi){

        cout<<mimi.get_c()<<" "<<mimi.get_l()<<" Masini de oras de mic litraj\n";


        return o;
    }

    istream& operator >> (istream& in, MINI&mimi){
        cout<<"Model + Lugime\n";
        in>>mimi.model>>mimi.l;
        return in;
    }
    //COMPACATA

    class COMPACATA : public Automobil{
        void scriere(){
            cout<<*this;
        }
    friend ostream& operator << (ostream&, COMPACATA&);
    friend istream& operator >> (istream&, COMPACATA&);

    };
    ostream& operator << (ostream& o, COMPACATA&mimi){

        cout<<mimi.get_c()<<" "<<mimi.get_l()<<" Modelele vin sub forma de hatchback, combi sau sedan\n";


        return o;
    }

    class MONOVOLUME : public Automobil
    {

    };

   template <class T>
   class VANZARE {




            int v;
           int s;
      public:
          vector <T*> v1, v2;
          VANZARE(){
              cin>>s;
              v = 0;
              for(int i = 0; i < s; i++){
                T *k;
                cin>>*k;

                v1.push_back(k);

              }

          }
         void vand(){
              v2.push_back(v1[s]);
              v1.pop_back();
              v = v2.size();
              s = v1.size();


          }

         int get_v(){
              return v;
          }

         int get_s(){
             return s;
         }

        VANZARE<T> operator -= (T&p){

            this->v = this->v2.size();
//            p.s = p.v1.size();
            cout<<"Masini vandute "<<p.v2.size()<<"  "<<"\n";







        }





    };






int main()
{
        VANZARE <Automobil> P;

        cout<<"Numar masisini in stoc: "<<P.get_s()<<endl;

//        P.v1.begin();
        for(int i = 0; i < P.get_s();i++){

         if(strcmp("MINI",P.v1[i]->get_c())==0){
        MINI * mini = static_cast<MINI*>(P.v1[i]);
        cout<< *mini;


        }

          if(strcmp("COMPACTA",P.v1[i]->get_c())==0){
        COMPACATA * mini = static_cast<COMPACATA*>(P.v1[i]);
        cout<< *mini;


        }
        }
        cout<<"Numar de masini vandute: "<<P.get_v()<<endl;

        P.vand();
        cout<<"Se vinde o masina\n";
        cout<<"Numar masisini in stoc: "<<P.get_s()<<endl;

        for(int i = 0; i < P.get_s();i++){

         if(strcmp("MINI",P.v1[i]->get_c())==0){
        MINI * mini = static_cast<MINI*>(P.v1[i]);
        cout<< *mini;


        }

          if(strcmp("COMPACTA",P.v1[i]->get_c())==0){
        COMPACATA * mini = static_cast<COMPACATA*>(P.v1[i]);
        cout<< *mini;


        }
        }
        cout<<"Numar de masini vandute: "<<P.get_v()<<endl;

         for(int i = 0; i < P.get_v();i++){

         if(strcmp("MINI",P.v2[i]->get_c())==0){
        MINI * mini = static_cast<MINI*>(P.v2[i]);
        cout<< *mini;


        }

          if(strcmp("COMPACTA",P.v2[i]->get_c())==0){
        COMPACATA * mini = static_cast<COMPACATA*>(P.v2[i]);
        cout<< *mini;


        }
        }






return 0;



}
