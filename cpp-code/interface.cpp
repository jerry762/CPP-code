#include <iostream>
#include <string>
#include <typeinfo>
#include <list>

using namespace std;

/**
 * @brief This is a animal abstract class
 *
 */
class Animal
{
private:
    string m_color;
    string m_gender;

protected:
    double m_height;
    double m_weight;

public:
    Animal(double height, double weight, string color, string gender);
    ~Animal() = default;
    virtual void feedingHabit() const = 0;
    virtual void sound() const = 0;
    string getColor() const;
    string getGender() const;
    double getHeight() const;
    double getWeight() const;
    void setHeight(double height);
    void setWeight(double weight);
};

Animal::Animal(double height, double weight, string color, string gender) : m_height(height), m_weight(weight), m_color(color), m_gender(gender)
{
    cout << "Animal's object created !" << endl;
}

string Animal::getColor() const
{
    return m_color;
}

string Animal::getGender() const
{
    return m_gender;
}

double Animal::getHeight() const
{
    return m_height;
}

double Animal::getWeight() const
{
    return m_weight;
}

void Animal::setHeight(double height)
{
    m_height = height;
}

void Animal::setWeight(double weight)
{
    m_weight = weight;
}

/**
 * @brief This is a cat concrete class
 *
 */
class Cat : public Animal
{
private:
    string m_breed;

public:
    Cat(double height, double weight, string color, string gender, string breed);
    ~Cat() = default;
    virtual void feedingHabit() const override;
    virtual void sound() const override;
    friend ostream &operator<<(ostream &out, const Cat &cat);
};

Cat::Cat(double height, double weight, string color, string gender, string breed)
    : Animal(height, weight, color, gender), m_breed(breed)
{
    cout << "Cat's object created !" << endl;
}

void Cat::feedingHabit() const
{
    cout << "Carnivorous" << endl;
}

void Cat::sound() const
{
    cout << "Meow~ Meow~" << endl;
}

ostream &operator<<(ostream &out, const Cat &cat)
{
    out << typeid(cat).name() << endl;

    return out;
}

/**
 * @brief This is a dog concrete class
 *
 */
class Dog : public Animal
{
private:
    string m_breed;

public:
    Dog(double height, double weight, string color, string gender, string breed);
    ~Dog() = default;
    virtual void feedingHabit() const override;
    virtual void sound() const override;
    friend ostream &operator<<(ostream &out, const Dog &dog);
};

Dog::Dog(double height, double weight, string color, string gender, string breed)
    : Animal(height, weight, color, gender), m_breed(breed)
{
    cout << "Dog's object created !" << endl;
}

void Dog::feedingHabit() const
{
    cout << "Carnivorous" << endl;
}

void Dog::sound() const
{
    cout << "Bark! Bark!" << endl;
}

ostream &operator<<(ostream &out, const Dog &dog)
{
    out << typeid(dog).name() << endl;

    return out;
}

/**
 * @brief This is a sheep concrete class
 *
 */
class Sheep : public Animal
{
private:
    string m_breed;

public:
    Sheep(double height, double weight, string color, string gender, string breed);
    ~Sheep() = default;
    virtual void feedingHabit() const override;
    virtual void sound() const override;
    friend ostream &operator<<(ostream &out, const Sheep &sheep);
};

Sheep::Sheep(double height, double weight, string color, string gender, string breed)
    : Animal(height, weight, color, gender), m_breed(breed)
{
    cout << "Sheep's object created !" << endl;
}

void Sheep::feedingHabit() const
{
    cout << "herbivorous" << endl;
}

void Sheep::sound() const
{
    cout << "Baa~ Baa~" << endl;
}

ostream &operator<<(ostream &out, const Sheep &sheep)
{
    out << typeid(sheep).name() << endl;

    return out;
}

int main()
{
    Cat cat(4, 6, "blue", "female", "British");
    Dog dog(24, 12, "black", "male", "Germany");
    Sheep sheep(100, 100, "white", "female", "New Zealand");

    // cout << cat << dog << sheep;

    list<Animal *> list{&cat, &dog, &sheep};

    for (const Animal *i : list)
        i->sound();

    // cat.feedingHabit();
    // cat.sound();

    // dog.feedingHabit();
    // dog.sound();

    // sheep.feedingHabit();
    // sheep.sound();

    return 0;
}
