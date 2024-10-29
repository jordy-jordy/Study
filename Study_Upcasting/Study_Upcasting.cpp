#include <iostream>
#include <vector>

class Animal {
public:
    virtual void speak() const {
        std::cout << "Animal sound!" << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Meow!" << std::endl;
    }
};

void animalSpeak(const Animal& animal) {
    animal.speak();
}

int main() {
    Dog dog;
    Cat cat;
    std::vector<Animal*> animals = { &dog, &cat };  // 명시적으로 Animal* 포인터로 선언

    for (Animal* animal : animals) {  // auto 대신 Animal*을 사용
        animal->speak();  // 각 객체에 맞는 speak() 호출
    }



    return 0;
}
