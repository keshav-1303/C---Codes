#include <bits/stdc++.h>
using namespace std;

class Hero{
private:

    int health;
    char level;

public:

    Hero(){
        cout << "default constructor called...\n";
    }

    Hero(int health, char level){
        cout << "\nthis == " << this << endl;
        this->health = health;
        this->level = level;
    }

    Hero(Hero &temp){
        cout << "\nCopy Constructor called...\n";
        this->health = temp.health;
        this->level = temp.level;
    }

    int gethealth(){
        return health;
    }

    char getlevel(){
        return level;
    }

    void sethealth(int h){
        health = h;
    }

    void setlevel(char ch){
        level = ch;
    }
};

int main(){

    Hero h1;    // this is static allocation

    // cout << h1.health << endl;

    cout << h1.gethealth() << endl;
    h1.sethealth(76);
    h1.setlevel('A');

    cout<< "h1's health is " << h1.gethealth() << endl;
    cout<< "h1's level is " << h1.getlevel() << endl;

    Hero *h2 = new Hero;
    h2->sethealth(73);
    (*h2).setlevel('C');

    cout<< "\nh2's health is " << (*h2).gethealth() << endl;
    cout<< "h2's level is " << h2->getlevel() << endl;    //this can also be used

    Hero ramesh(40, 'E');
    cout << "Address of ramesh is " << &ramesh << endl;

    Hero suresh(ramesh);    // copy constructor
    cout<< "suresh's health : " << suresh.gethealth() << "  ramesh's health : " << ramesh.gethealth() << endl;
    cout<< "suresh's level : " << suresh.getlevel() << "  ramesh's level : " << ramesh.getlevel() << endl;
	
    cout << endl;
	return 0;
}