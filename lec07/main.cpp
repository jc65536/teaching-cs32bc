#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal {
public:
    Animal(string name, int age) : name(name), age(age) {
    }

    string name;
    int age;

    void eat(string food) {
        cout << "Eating " << food << endl;
    }

    virtual void make_noise() {
        cout << "Animal noises" << endl;
    }

    ~Animal() {
    }
};

// private here says "Only Dog knows that a Dog is an Animal"
class Dog : public Animal {
public:
    Dog(string name, int age, string breed) : Animal(name, age), breed(breed) {
    }

    string breed;

    void bark() {

    }

    void make_noise() override {
        cout << "Woof" << endl;
    }

    ~Dog() {
    }
};

class Bird : public Animal {
public:
    Bird(string name, int age) : Animal(name, age) {
    }
};

int f(double d1, double d2) {
    //
}

int f(int i1, int i2) {
    //
}

f(1, 2);

// class Cat {
// public:
//     Animal inner;

//     Cat(string name, int age): inner(name, age) {
//     }

//     void make_noise() {
//         cout << "meow" << endl;
//     }
// };

// feed can take an abstract type Animal because it's not creating an Animal
void feed(Animal &a, const string &food) {
    cout << "Feeding..." << endl;
    a.eat(food);
    a.make_noise();
}

// Does not know that Dog is an Animal
int main() {
    Dog d("bob", 4, "husky");
    Bird b("carl", 2);
    feed(d, "bone");
    feed(b, "fish");
}
