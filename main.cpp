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
                T k;
                cin>>k;
                v1.push_back(&k);
              }

          }
         void vand(){
              v2.push_back(v1[s]);
              v1.pop_back();
              v++;
              s--;
          }

         int get_v(){
              return v;
          }

         int get_s(){
             return s;
         }












    };

//        template <class A_type> class VANZARE VANZARE <class A_type> :: operator -= (A_type&ob){
//        }




int main()
{


//Automobil *a = new Automobil ;
//
//    cin>>*a;
//        if(strcmp("MINI",a->get_c())==0){
//        MINI * mini = static_cast<MINI*>(a);
//        cout<< *mini;
//
//        }
//
//        if(strcmp("COMPACTA",a->get_c())==0){
//        COMPACATA * mini = static_cast<COMPACATA*>(a);
//        cout<< *mini;
//
//        }

        VANZARE <Automobil> P;


        P.vand();
        cout<<(*P.v2[0]);









return 0;



}
