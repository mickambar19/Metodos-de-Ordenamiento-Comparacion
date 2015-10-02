#ifndef LISTA_H
#define LISTA_H
#include "leerentero.h"
#include <string>
#include<iostream>
#define MAX 70000
using namespace std;
typedef int p;
template <class T>
class Lista
{
    public:
        T elem[MAX];
        p pos;
        int conta;
    public:
        Lista();
        void inicializa();
        void anula();
        p primero();
        p ultimo();
        p anterior(p pos);
        p siguiente(p pos);
        p localiza(T e);
        T recupera(p a);
        void insertar(p pos,T e);
        void elimina(p pos);
        bool vacia();
        bool llena();
        void burbuja();
        p busquedaBinaria(T e);
        void imprimir(T e);
        void imprimirlista();
        void seleccion();
        void inserccion();
        void shell();
        void quicksort(int izq, int der);
        void merge_(int izq,int der);
        void mergesort(int izq,int centro,int der);
        };

    template<class T>
Lista<T>::Lista()
    {inicializa();}
    template<class T>
void Lista<T>::inicializa()
    { conta=-1;}
    template<class T>
bool Lista<T>::vacia()
    { if(conta==-1)
            return true;
        else
            return false;}

    template<class T>
bool Lista<T>::llena()
    {if(conta==MAX-1)
            return true;
        else
            return false;}
    template<class T>
p Lista<T>::primero(){
        pos=0;
        return pos;
    }

   template<class T>
p Lista<T>::ultimo(){
        pos=conta+1;
        return pos;
    }

    template<class T>
p Lista<T>:: anterior(p pos){
        pos=pos-1;
        return pos;
    }

    template<class T>
p Lista<T>:: siguiente(p pos){
        pos=pos+1;
        return pos;
    }

    template<class T>
p Lista<T>:: localiza(T e){
        for(int i=0;i<=conta;i++){
        if(elem[i]==e){return i;}
       }
       return -1;}


    template<class T>
T Lista<T>:: recupera(p a){
        T e;
        if(a>=primero()&& a<=ultimo())
            e=elem[a];
        return e;
    }

    template<class T>
void Lista<T>::insertar(p pos,T e)
    { int i;
        if(pos>=primero()&& pos<=ultimo()&& !llena()){//conta -1
            for(i=ultimo();i>pos;i--){
                elem[i]=elem[i-1];
           }
       elem[pos]=e;
       conta+=1;
    }}
    template<class T>
void Lista<T>::elimina(p pos)
    {     if(vacia()==0 && pos>=primero() && pos<=ultimo()){
               for(int i=pos-1;i<=ultimo();i++)
                    { elem[i]=elem[i+1];}
                    conta--;
                }}
    template<class T>
void Lista<T>::imprimir(T e)
    {
        cout<<e<<" - ";
        }
    template<class T>
void Lista<T>::imprimirlista()
    { if(vacia()==0){
        int i;
       for(i=0;i<=conta;i++)
        {
            cout<<elem[i]<<" - ";
        }
       cout<<endl;
    }}
    template<class T>
void Lista<T>::anula()
    {
        conta=-1;
    }
    template<class T>
void Lista<T>::burbuja()
{
    T aux;
    int h,g,d=conta;
    for(h=conta;h>0;h--)
    {
        for(g=0;g<h;g++)
        {
            if(elem[g+1]<elem[g])
            {
                aux=elem[g];
                elem[g]=elem[g+1];
                elem[g+1]=aux;
                d-=1;
            }
        }
        if(d==conta)
        {
            break;
            d=conta;
        }
    }
}
        template<class T>
p Lista<T>::busquedaBinaria(T e)
    {
        int i=primero(),j=ultimo();
        int medio;
        while(i<=j)
        {   medio=(i+j)/2;
            if( elem[medio]==e)
            {return medio;}
            if(e<elem[medio])
            {j=medio-1;}
            else
           {i=medio+1;}
        } return -1;
    }
       template<class T>
void Lista<T>::seleccion()
    {     int menor, g, h;
          T aux;
          g=0;
          while(g<conta){
             h=g+1;
             menor=g;
            while(h<=conta){
               if(elem[h]<elem[menor]){
               menor=h;}
               h++;}
               if(menor!=g){
                 aux=elem[g];
                 elem[g]=elem[menor];
                 elem[menor]=aux;
                }
            g++;}}
       template<class T>
void Lista<T>::inserccion(){
    int j,i;
    T llave;
    for(j=1;j<=ultimo();j++)
    {
        llave=elem[j];
        i=j-1;
        while(i>=0 && llave<elem[i])
        {
            elem[i+1]=elem[i];
            i--;
        }
        elem[i+1]=llave;
    }
}
    template<class T>
void Lista<T>::shell(){
                int i, j, inc;
                T temp;
                for(inc = 1 ; inc<conta;inc=inc*3+1);
                    while (inc > 0)
                    { for (i=inc; i < conta; i++){
                   j = i;
                   temp = elem[i];
                   while ((j >= inc) && (temp<elem[j-inc] ))
                    { elem[j] = elem[j - inc];
                    j = j - inc; }
                    elem[j] = temp;
                    }inc/= 2;
                    }
                }
    template<class T>
void Lista<T>::quicksort(int izq, int der){
              int g,h,medio;
              T pivote,aux;
              medio=(izq+der)/2;
              pivote=elem[medio];
              g=izq;
              h=der;
              while(g<=h){
                while(elem[g]<pivote)g++;
                while(pivote<elem[h])h--;
                if(g<=h){
                        aux=elem[g];
                        elem[g]=elem[h];
                        elem[h]=aux;
                    g++;
                    h--;
                }
              }
              if(izq<h)quicksort(izq,h);
              if(g<der)quicksort(g,der);
              }


template<class T>
void Lista<T>:: merge_( int izq, int der){
    if (izq < der)
        /* este if comprueba el caso base que es cuando la partición
pasada no tiene elementos. */
    {
        /* dividimos a la mitad el subarray [elem[izq],...,elem[der]] */
        int centro = (izq + der) / 2;
        /* aplicamos la recursión en ambas mitades */
        merge_( izq, centro);
        merge_( centro + 1, der);
        /* a este punto ambas mitades deberían estar ordenadas por
lo que las intercalamos para unirlas en una sola
secuencia ordenada. */
        mergesort(izq, centro + 1, der);
    }
}

template<class T>
void Lista<T>::mergesort (int izq, int centro, int der)
{
    T tmp[MAX];
    /* mis particiones serán [izq,...,centro-1] y
[centro,...,der] */
    /* contadores para la primera mitad, la segunda y para la
intercalacion respectivamente. */
    int ap = izq, bp = centro, cp = izq;
    while ((ap < centro) && (bp <= der))
    {
        if (elem[ap] <=elem[bp])
        {
            tmp[cp] = elem[ap];
            ap++;
        }
        else{
            tmp[cp] = elem[bp];
            bp++;
        }
        cp++;
    }

    /* terminamos de intercalar, ahora metemos los elementos
restantes de la lista que aún no ha terminado de ser
procesada. */
    while (ap < centro)
    {
        tmp[cp] = elem[ap];
        cp++;ap++;
    }
    while (bp <= der)
    {
        tmp[cp] = elem[bp];
        cp++;bp++;
    }
    /* ahora que tenemos la intercalación finalizada en tmp, la
pasamos a el arreglo principal */
    for (ap = izq; ap <= der; ap++)
        elem[ap] = tmp[ap];
}

#endif // LISTA_H
