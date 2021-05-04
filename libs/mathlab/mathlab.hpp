#include <cmath>
#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

#ifndef TEMPLATES
#define TEMPLATES

namespace ag
{

    template <typename T>
    class vector
    {
    private:
        T x, y, z;

    public:
        vector() : x(0), y(0), z(0) {}
        vector(const T &x, const T &y, const T &z) : x(x), y(y), z(z) {}

        vector(const T &x, const T &y) : x(x), y(y), z(0) {}

        const T &getX() { return this->x; }
        const T &getY() { return this->y; }
        const T &getZ() { return this->z; }

        const T &getX() const { return this->x; }
        const T &getY() const { return this->y; }
        const T &getZ() const { return this->z; }

        void setX(const T &x) { this->x = x; }
        void setY(const T &y) { this->y = y; }
        void setZ(const T &z) { this->z = z; }

        T length() { return T(sqrt(this->x * this->x + this->y * this->y)); }

        vector<T> operator+(const vector<T> &v) { return vector<T>(this->x + v.x, this->y + v.y, this->z + v.z); }

        vector<T> operator-(const vector<T> &v) { return vector<T>(this->x - v.x, this->y - v.y, this->z - v.z); }

        vector<T> &operator+=(const vector<T> &v)
        {
            this->x += v.x;
            this->y += v.y;
            this->z += v.z;

            return *this;
        }

        vector<T> &operator-=(const vector<T> &v)
        {
            this->x -= v.x;
            this->y -= v.y;
            this->z -= v.z;

            return *this;
        }

        vector<T> &operator*(const T &v) { return vector<T>(this->x * v, this->y * v, this->z * v); }

        T operator*(const vector<T> &v) { return this->x * v.x + this->y * v.y + this->z * v.z; }

        friend std::ostream &operator<<(std::ostream &os, const vector<int> &v);
        friend std::ostream &operator<<(std::ostream &os, const vector<double> &v);
        friend std::ostream &operator<<(std::ostream &os, const vector<float> &v);
        friend std::ostream &operator<<(std::ostream &os, const vector<long> &v);
        friend std::ostream &operator<<(std::ostream &os, const vector<long long> &v);
        friend std::ostream &operator<<(std::ostream &os, const vector<long double> &v);

        ~vector() {}
    };

    std::ostream &operator<<(std::ostream &os, const vector<int> &v)
    {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }
    std::ostream &operator<<(std::ostream &os, const vector<float> &v)
    {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }
    std::ostream &operator<<(std::ostream &os, const vector<double> &v)
    {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }
    std::ostream &operator<<(std::ostream &os, const vector<long> &v)
    {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }
    std::ostream &operator<<(std::ostream &os, const vector<long long> &v)
    {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }
    std::ostream &operator<<(std::ostream &os, const vector<long double> &v)
    {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }

    template <typename T>
    class shape_p
    {
    public:
        shape_p() {}
        shape_p(std::initializer_list<T> values)
        {
            for (auto i = 0; i < values.size(); i++)
            {
                points.append(values[i]);
            }
        }
        ~shape_p() { points.clear(); }

        std::vector<T> &getPoints() { return this->points; }
        const std::vector<T> &getPoints() const { return this->points; }

        friend std::ostream &operator<<(std::ostream &os, const shape_p<int> &v);
        friend std::ostream &operator<<(std::ostream &os, const shape_p<double> &v);
        friend std::ostream &operator<<(std::ostream &os, const shape_p<float> &v);
        friend std::ostream &operator<<(std::ostream &os, const shape_p<long> &v);
        friend std::ostream &operator<<(std::ostream &os, const shape_p<long long> &v);
        friend std::ostream &operator<<(std::ostream &os, const shape_p<long double> &v);

    private:
        std::vector<T> points;
    };

    template <typename T>
    class point
    {
    private:
        T x, y, z;

    public:
        point() : x(0), y(0), z(0) {}
        point(const T &x, const T &y, const T &z) : x(x), y(y), z(z) {}
        ~point() {}

        const T &getX() { return this->x; }
        const T &getY() { return this->y; }
        const T &getZ() { return this->z; }

        const T &getX() const { return this->x; }
        const T &getY() const { return this->y; }
        const T &getZ() const { return this->z; }

        void setX(const T &X) { this->x = X; }
        void setY(const T &Y) { this->y = Y; }
        void setZ(const T &Z) { this->z = Z; }

        void move(T &x, T &y, T &z)
        {
            this->setX(this->getX() + x);
            this->setY(this->getY() + y);
            this->setZ(this->getZ() + z);
        }

        point<T> operator+(const vector<T> &v) { return point<T>(this->x + v.getX(), this->y + v.getY(), this->z + v.getZ()); }

        point<T> operator-(const vector<T> &v) { return point<T>(this->x - v.getX(), this->y - v.getY(), this->z - v.getZ()); }

        point<T> &operator+=(const vector<T> &v)
        {
            this->x += v.getX();
            this->y += v.getY();
            this->z += v.getZ();

            return *this;
        }

        point<T> &operator-=(const vector<T> &v)
        {
            this->x -= v.getX();
            this->y -= v.getY();
            this->z -= v.getZ();

            return *this;
        }

        friend std::ostream &operator<<(std::ostream &os, const point<int> &v);
        friend std::ostream &operator<<(std::ostream &os, const point<double> &v);
        friend std::ostream &operator<<(std::ostream &os, const point<float> &v);
        friend std::ostream &operator<<(std::ostream &os, const point<long> &v);
        friend std::ostream &operator<<(std::ostream &os, const point<long long> &v);
        friend std::ostream &operator<<(std::ostream &os, const point<long double> &v);
    };

    template <typename T>
    class shape : public point<T>
    {
    private:
        T r_x = 0, r_y = 0, r_z = 0;

    public:
        shape() : point<T>(0, 0, 0) {}
        shape(const T &x, const T &y, const T &z) : point<T>(x, y, z) {}
        ~shape() {}

        void setRotationX(T &x) { this->r_x = x; }
        void setRotationY(T &y) { this->r_y = y; }
        void setRotationZ(T &z) { this->r_z = z; }

        void setRotationXYZ(T &x, T &y, T &z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        const T &getRotationX(T &x) { return this->r_x; }
        const T &getRotationY(T &y) { return this->r_y; }
        const T &getRotationZ(T &z) { return this->r_z; }

        const T &getRotationX(T &x) const { return this->r_x; }
        const T &getRotationY(T &y) const { return this->r_y; }
        const T &getRotationZ(T &z) const { return this->r_z; }

        void rotate(T &x, T &y, T &z)
        {
            this->r_x += x;
            this->r_y += y;
            this->r_z += z;
        }

        friend std::ostream &operator<<(std::ostream &os, const shape<int> &v);
        friend std::ostream &operator<<(std::ostream &os, const shape<double> &v);
        friend std::ostream &operator<<(std::ostream &os, const shape<float> &v);
        friend std::ostream &operator<<(std::ostream &os, const shape<long> &v);
        friend std::ostream &operator<<(std::ostream &os, const shape<long long> &v);
        friend std::ostream &operator<<(std::ostream &os, const shape<long double> &v);
    };

    std::ostream &operator<<(std::ostream &os, const point<int> &v)
    {
        os << "point(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
        return os;
    }
    std::ostream &operator<<(std::ostream &os, const point<float> &v)
    {
        os << "point(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
        return os;
    }
    std::ostream &operator<<(std::ostream &os, const point<double> &v)
    {
        os << "point(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
        return os;
    }
    std::ostream &operator<<(std::ostream &os, const point<long> &v)
    {
        os << "point(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
        return os;
    }
    std::ostream &operator<<(std::ostream &os, const point<long long> &v)
    {
        os << "point(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
        return os;
    }
    std::ostream &operator<<(std::ostream &os, const point<long double> &v)
    {
        os << "point(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
        return os;
    }

    std::ostream &operator<<(std::ostream &os, const shape<int> &v)
    {
        os << "shape(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
        return os;
    }
    std::ostream &operator<<(std::ostream &os, const shape<float> &v)
    {
        os << "shape(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
        return os;
    }
    std::ostream &operator<<(std::ostream &os, const shape<double> &v)
    {
        os << "shape(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
        return os;
    }
    std::ostream &operator<<(std::ostream &os, const shape<long> &v)
    {
        os << "shape(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
        return os;
    }
    std::ostream &operator<<(std::ostream &os, const shape<long long> &v)
    {
        os << "shape(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
        return os;
    }
    std::ostream &operator<<(std::ostream &os, const shape<long double> &v)
    {
        os << "shape(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
        return os;
    }

    template <typename T>
    class square : public shape<T>
    {
    private:
        T s_x, s_y, s_z;

        bool Foo(const T &px, const T &py, const T &pz)
        {
            T x = this->getX();
            T y = this->getY();
            T z = this->getZ();
            return ((px < x + this->s_x / 2) && (px > x - this->s_x / 2)) && ((py < y + this->s_y / 2) && (py > y - this->s_y / 2)) && ((pz < z + this->s_z / 2) && (pz > z - this->s_z / 2));
        }

    public:
        const T &getSizeX() { return this->s_x; }
        const T &getSizeY() { return this->s_y; }
        const T &getSizeZ() { return this->s_z; }
        const vector<T> getSize() { return vector<T>(this->s_x, this->s_y, this->s_z); }

        const T &getSizeX() const { return this->s_x; }
        const T &getSizeY() const { return this->s_y; }
        const T &getSizeZ() const { return this->s_z; }
        const vector<T> getSize() const { return vector<T>(this->s_x, this->s_y, this->s_z); }

        square<T>& setSizeX(const T &x) { this->s_x = x; }
        square<T>& setSizeY(const T &y) { this->s_y = y; }
        square<T>& setSizeZ(const T &z) { this->s_z = z; }
        square<T>& setSize(const T &x, const T &y, const T &z)
        {
            this->s_x = x;
            this->s_y = y;
            this->s_z = z;
            
            return *this;
        }
        square<T>& setSize(vector<T> v)
        {
            this->s_x = v.getX();
            this->s_y = v.getY();
            this->s_z = v.getZ();

            return *this;
        }

        square<T>& reSize(const T &x, const T &y, const T &z)
        {
            this->s_x += x;
            this->s_y += y;
            this->s_z += z;

            return *this;
        }
        square<T>& reSize(vector<T> v)
        {
            this->s_x += v.getX();
            this->s_y += v.getY();
            this->s_z += v.getZ();

            return *this;
        }

        bool operator()(const T &x, const T &y, const T &z) { return this->Foo(x, y, z); }

        square(const T &size_x, const T &size_y, const T &size_z) : shape<T>(),
                                                                    s_x(size_x), s_y(size_y), s_z(size_z)
        {
        }

        square(const T &size_x, const T &size_y, const T &size_z, const T &coord_x, const T &coord_y, const T &coord_z) : shape<T>(coord_x, coord_y, coord_z),
                                                                                                                          s_x(size_x), s_y(size_y), s_z(size_z) {}
    };

    template <typename T>
    class sphere : public shape<T>
    {
    private:
        T radius;

        bool Foo(const T &px, const T &py, const T &pz)
        {
            T x = this->getX();
            T y = this->getY();
            T z = this->getZ();
            return (abs(px) < this->radius) && (abs(py) < this->radius) && (abs(pz) < this->radius);
        }

    public:
        sphere(const T &r) : shape<T>(),
                             radius(r) {}

        sphere(const T &r, const T &coord_x, const T &coord_y, const T &coord_z) : shape<T>(coord_x, coord_y, coord_z),
                                                                                   radius(r) {}

        const T& getRadius() { return this->radius; }
        sphere<T>& setRadius(const T &r) { this->radius = r; return *this; }

        bool operator()(const T &x, const T &y, const T &z) { return this->Foo(x, y, z); }
    };

}

#endif