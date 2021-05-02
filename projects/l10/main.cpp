#include <iostream>
#include <string>
#include <memory>

class Entity
{
private:
    std::string name;

public:
    const std::string &getName() const { return name; }
    std::string &getName() { return name; }

    Entity(const std::string &name) : name(name)
    {
        std::cout << "Entity " << name << " created!" << std::endl;
    };

    Entity() : name("Unknown")
    {
        std::cout << "Entity " << name << " created!" << std::endl;
    };

    ~Entity()
    {
        std::cout << "Entity " << name << " deleted!" << std::endl;
    };
};

int main(int argc, char *argv[])
{
    void *p1 = nullptr;

    std::cout << "Null pointer = " << p1 << std::endl;

    int a = 123;
    int *a_ptr = &a;
    std::cout << "a = " << a << std::endl;

    std::cout << "Pointer a_ptr (" << a_ptr << ") with value " << *a_ptr << std::endl;

    int *b = new int[8];
    for (int i = 0; i < 8; i++)
        b[i] = i;
    std::cout << "Pointer to array (" << b << ") with value " << *b << std::endl;

    int *b_init = b;
    std::cout << "Incremented pointer to array (" << ++b << ") with value " << *b << std::endl;
    std::cout << "Difference = " << (b - b_init) * sizeof(int) << "bytes" << std::endl;

    b = b_init;
    std::cout << "Proof that a[i] = i[a] = *(a+i)" << std::endl;
    std::cout << "b[2] = " << b[2] << std::endl;
    std::cout << "2[b] = " << 2 [b] << std::endl;

    delete[] b;

    std::cout << "Raw pointer" << std::endl;
    Entity *e0 = new Entity("E0");
    delete e0;

    std::cout << "Raw pointer to object in stack in scoupe" << std::endl;
    Entity *e1;
    {
        Entity e2 = Entity("E2");
        e1 = &e2;
        std::cout << e1->getName() << std::endl;
    }
    std::cout << e1->getName() << std::endl;

    std::cout << "Raw pointer in scoupe" << std::endl;
    {
        Entity *e3 = new Entity("E3");
    }
    std::cout << "E3 still isn't deleted" << std::endl;

    std::cout << "Smart unique_ptr" << std::endl;
    {
        std::unique_ptr<Entity> e4 = std::make_unique<Entity>("E4");
    }

    std::cout << "Smart shared_ptr, E6 refrences E5" << std::endl;
    std::shared_ptr<Entity> e6;
    {
        auto e5 = std::make_shared<Entity>("E5");
        e6 = e5;
    }
    std::cout << "E5 still exists at e6 variable" << std::endl;
    e6.reset();

    std::cout << "Smart weak_ptr" << std::endl;
    std::weak_ptr<Entity> e7;
    {
        auto e8 = std::make_shared<Entity>("E8");
        e7 = e8;
    }
    std::cout << (e7.expired() ? "e7 expired" : "e7 still exists") << std::endl;
}