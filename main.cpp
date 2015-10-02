#include <iostream>
#include <ctime>
#include "array.h"
#include "Lista.h"
#include <cstdlib>
#include <ctime>
#include <sys/time.h>

using namespace std;
int aleatorio();
double duracion(struct timeval inicio , struct timeval fin);
struct timeval inicio,fin;


int main()
{
   double tiem_transc;
   struct timeval inicio,fin;
   int con=8000;
   double b,in,m,q;
   b=in=m=q=0;
Dato dato;
Lista<Dato>l,l2,l3,l4,l5,l6;
do
{
    l.inicializa();
    for(int i=0;i<MAX;i++){
        dato.a=aleatorio();
        l.insertar(l.primero(),dato);
    }
    l2=l;
    l3=l;
    l4=l;
    l5=l;
    l6=l;
/*
    gettimeofday(&inicio , NULL);
    l.burbuja();
    gettimeofday(&fin , NULL);
    b+=tiem_transc=duracion(inicio,fin);

    cout<<"tiempo con el ordenamiento de burbuja   :"<<tiem_transc<<"  microsegundos\n";

    gettimeofday(&inicio , NULL);
    l2.inserccion();
    gettimeofday(&fin , NULL);
    in+=tiem_transc=duracion(inicio,fin);

    cout<<"tiempo con el ordenamiento de inserccion:"<<tiem_transc<<" microsegundos\n";
  */
    gettimeofday(&inicio , NULL);
    l5.merge_(l.primero(),l.ultimo()-1);
    gettimeofday(&fin , NULL);
    m+=tiem_transc=duracion(inicio,fin);

    cout<<"tiempo con el ordenamiento de merge     :"<<tiem_transc<<"  microsegundos\n";

    gettimeofday(&inicio , NULL);
    l4.quicksort(l.primero(),l.ultimo()-1);
    gettimeofday(&fin , NULL);
    q+=tiem_transc=duracion(inicio,fin);

    cout<<"tiempo con el ordenamiento de quicksort :"<<tiem_transc<<"  microsegundos\n";
    con--;
}while(con!=0);

cout<<"promedio bubble      :"<<b/8000<< " "<<b <<" tiempo "<<endl;
cout<<"promedio inserccion  :"<<in/8000<< " "<<in <<" tiempo "<<endl;
cout<<"promedio merge       :"<<m/8000<< " "<<m<<" tiempo "<<endl;
cout<<"promedio quick       :"<<q/8000<< " "<<q <<" tiempo "<<endl;
    return 0;
}

int aleatorio(){
    int x;
 srand(time(NULL)*rand());
 x=rand()%MAX+1;

return x;}


double duracion(struct timeval inicio , struct timeval fin) {
        double x_ms , y_ms , diff;

        x_ms = (double)inicio.tv_sec*1000000 + (double)inicio.tv_usec;
        y_ms = (double)fin.tv_sec*1000000 + (double)fin.tv_usec;

        diff = (double)y_ms - (double)x_ms;

      return diff;
}



