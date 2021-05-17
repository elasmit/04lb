#include <iostream>
#include <string>

template<typename T>
struct coords {
    T x, y, z;

    coords& operator+=(const coords& cd)
    {
        this->x = cd.x;
        this->y = cd.y;
        this->z = cd.z;

        return *this;
    }
};

template<typename T>
coords<T> make_cords(T x = 0, T y = 0, T z = 0)
{
    coords<T> tmp;
    tmp.x = x; 
    tmp.y = y; 
    tmp.z = z; 

    return tmp;
}

class animal
{
private:
    std::string type;
    coords<double> cordinates;
public:
    animal(std::string type){
        this->type = type;
    };
    ~animal(){

    }

    void changeCoords(const coords<double>& cd)
    {
        this->cordinates += cd;
    }

    const std::string& gettype();
    void settype(const std::string& in);
    virtual void move(const coords<double>& step) = 0;
};

class bird : public animal
{
private:
    int wings_length;

public:
    bird(int wl) : animal("Bird"), wings_length(wl) {

    }

    ~bird(){

    };

    void move(const coords<double>& step)
    {
        std::cout << "Fly!" << std::endl;
        this->changeCoords(step);
    }
};

class human : public animal
{
private:
    int age, heigth;

public:
/*
 * @param a age
 * @param heigh heingh
 *
*/
    human(int a, int heigth) : animal("human"), age(a), heigth(heigth) {

    }

    virtual ~human(){

    };

    void update_age()
    {
        (this->age)++;
    }

    void move(const coords<double>& step)
    {
        std::cout << "Walk and talk!" << std::endl;
        this->changeCoords(step);
    }
};

class fish : public animal
{
private:
    std::string spice;

public:
/*
 * @param a age
 * @param heigh heingh
 *
*/
    fish(std::string spice) : animal("fish"), spice(spice) {

    }

    ~fish(){

    };

    void move(const coords<double>& step)
    {
        std::cout << "Pulb!" << std::endl;
        this->changeCoords(step);
    }
};

void do_something(animal& a)
{
    a.move(make_cords<double>());
}

int main(int argc, char *argv[]){

    auto am = bird(12);
    do_something(am);

    auto an = human(12, 135);
    do_something(an);

    auto ah = fish(std::string("Hi"));
    do_something(ah);

}