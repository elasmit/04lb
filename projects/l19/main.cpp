#include <iostream>

class image
{
private:
    size_t x, y;
    void* content = nullptr;

public:
    image(void* cnt) : content(cnt) {

    }

    image(image* cnt) : content(cnt->get_content()) {

    }

    ~image(){

    }

    void* get_content(){ return this->content; }

    virtual void read() = 0;     
    virtual void save() = 0; 
    virtual void show() = 0; 
    virtual void info() = 0; 

    
    bool operator==(image& b){
        return this->get_content() == b.get_content();
    }
};

class png : public image
{
public:
    png(void* loc) : image(loc){}
    ~png() {}

    void read(){ std::cout << "Reading png image" << std::endl; }
    void save(){ std::cout << "Saving png image" << std::endl; }
    void show(){ std::cout << "Showing png image" << std::endl; }
    void info(){ std::cout << "Info about png image" << std::endl; }

    png& operator+(image& b){
        std::cout << "Adding png images" << std::endl;
    }
};

class jpg : public image
{
public:
    jpg(void* loc) : image(loc){}
    ~jpg() {}

    void read(){ std::cout << "Reading jpg image" << std::endl; }
    void save(){ std::cout << "Saving jpg image" << std::endl; }
    void show(){ std::cout << "Showing jpg image" << std::endl; }
    void info(){ std::cout << "Info about jpg image" << std::endl; }

    jpg& operator+(image& b){
        std::cout << "Adding jpg images" << std::endl;
    }
};

class bmp : public image
{
public:
    bmp(void* loc) : image(loc){}
    ~bmp() {}

    void read(){ std::cout << "Reading bmp image" << std::endl; }
    void save(){ std::cout << "Saving bmp image" << std::endl; }
    void show(){ std::cout << "Showing bmp image" << std::endl; }
    void info(){ std::cout << "Info about bmp image" << std::endl; }

    bmp& operator+(image& b){
        std::cout << "Adding bmp images" << std::endl;
    }
};

class creatorBase {
public:
    virtual image* operator()(void* loc) = 0;

    image* create(void* loc){
        return this->operator()(loc);
    }
};

class createPng : public creatorBase
{
public:
    png* operator()(void* loc){
        png* tmp = new png(loc);
        return tmp;       
    }
};

class createJpg : public creatorBase
{
public:
    jpg* operator()(void* loc){
        jpg* tmp = new jpg(loc);
        return tmp;       
    }
};

class createBmp : public creatorBase
{
public:
    bmp* operator()(void* loc){
        bmp* tmp = new bmp(loc);
        return tmp;       
    }
};

int main(int argc, char *argv[]){

    creatorBase* jpgBuild = new createJpg();
    image* jpgImage = jpgBuild->operator()((void*)0);

    jpgImage->save();
    jpgImage->read();
    jpgImage->show();
    jpgImage->info();

    std::cout << ((*jpgImage) == (*jpgImage)) << std::endl;
    std::cout << (*((jpg*)(jpgImage)) + *((jpg*)(jpgImage))).get_content() << std::endl;
}