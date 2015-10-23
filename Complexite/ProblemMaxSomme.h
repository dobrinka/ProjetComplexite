#ifndef PROBLEMMAXSOMME_H
#define PROBLEMMAXSOMME_H
#include <vector>

class ProblemMaxSomme
{
    public:
        ProblemMaxSomme(std::vector<int> tab);
        int algo1();
        int algo2();
        int max3(int a,int b,int c);
        int algo3(int a, int b);
        int algo4();
        void afficherTableau();
        virtual ~ProblemMaxSomme();
    private:
        std::vector<int> t;

};

#endif // PROBLEMMAXSOMME_H
