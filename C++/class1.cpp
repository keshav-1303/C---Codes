#include <bits/stdc++.h>
using namespace std;

class Hero{

    public:
        string name;
        int health;
        char level;

        void print(){
            cout << "Name:" << this->name << " , ";
            cout << "Health:" << this->health << " , ";
            cout << "Level:" << this->level << "\n";
            cout << endl;
        }

        int gethealth(){
            return health;
        }

        char getlevel(){
            return level;
        }

        string getname(){
            return name;
        }

        void sethealth(int h){
            health = h;
        }

        void setlevel(char ch){
            level = ch;
        }

        void setname(string name){
            this->name = name;
        }

        ~Hero(){
            cout << "Destructor called...\n";
        }

};

int main(){
	
    Hero *h1 = new Hero;
    h1->setname("Keshav");
    h1->sethealth(56);
    h1->setlevel('D');
    cout << "Hero 1 characteristics...\n";    h1->print();

    Hero h2(*h1);
    cout << "Hero 2 characteristics...\n";    h2.print();

    h1->name[0] = 'C';
    cout << "Now characteristics are...\n";
    h1->print();
    h2.print();

    delete h1;  //used bec h1 is created dynamically
    
	return 0;
}