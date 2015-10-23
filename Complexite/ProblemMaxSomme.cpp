#include <iostream>
#include <vector>
#include <stdio.h>
#include "ProblemMaxSomme.h"
#define N 10

using namespace std;


vector<int> Somme;



ProblemMaxSomme::ProblemMaxSomme(std::vector<int> tab)
{
    //ctor
    for(int i =0;i<tab.size();i++)
    {
        t.push_back(tab[i]);
    }

}

ProblemMaxSomme::~ProblemMaxSomme()
{
    //dtor
}


int ProblemMaxSomme::algo1()

{
    int res = 0;

    for (int i = 0; i < t.size(); i++)
    {
        int s = t[i];
        for (int j = i; j < t.size(); j++)
        {
            if (i != j)
                s += t[j];

            if (s > res)
            {
                res = s;
            }
        }
    }
    return res;
}

int ProblemMaxSomme::algo2()
{

    int sum=0;
    int res=0;
    int s;

    for (int i = 0; i < t.size(); i++)
    {
        sum += t[i];
        Somme.push_back(sum);
       // res = sum;
    }

    for (int i = 0; i < t.size(); i++)
    {
        for (int j = i; j< t.size(); j++)
        {
            if (i==0)
            {
                s = Somme[j];
            }
            else
            {
                s = Somme[j] - Somme[i-1];
            }

            if(s>res)
            {
                res=s;

            }
               // cout<<"S i,j= "<<res<<endl;
        }
    }
    return res;
}

int ProblemMaxSomme::max3(int a,int b,int c)
{
        int x = max(a,b);

        return max(x,c);
}

int ProblemMaxSomme::algo3(int a,int b)
{
            if (a>b){
                return 0;
            }
            if (a==b){
                if (t[a] > 0)
                {
                    return t[a];
                }
                else
                {
                    return 0;
                }
            }

        int c=(a+b)/2;
        int amax=0;
        int somme=0;
        int i = c;
        while (i >= a){
            somme = somme + t[i];
            amax = max(amax,somme);
            i = i-1;
        }
        int bmax=0;
        somme=0;
        i = c + 1;
        while (i <= b){
            somme = somme + t[i];
            bmax = max(bmax,somme);
            i = i+1;
        }
    return max3(amax+bmax,algo3(a,c),algo3(c+1,b));
}

int ProblemMaxSomme::algo4()
{
int a=0;
int b=0;
int i=0;
while(i<t.size()){
    b= max(b + t[i],0);
    a= max(a,b);
    i=i+1;
    }
    return a;

}

void ProblemMaxSomme::afficherTableau()
{
    for(int i =0; i<t.size();i++)
    {
        cout << "tNEW[" << i << "] = "<< t[i] << endl;
    }
}
