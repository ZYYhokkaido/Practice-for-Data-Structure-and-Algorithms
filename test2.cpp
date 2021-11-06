#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

template <typename T>
class Array2D : public vector< vector<T> >
{
private:
    int nx, ny;

public:
    Array2D(int nx, int ny) : vector< vector< T > >()
    {
        this->nx = nx;
        this->ny = ny;
        for (int i = 0; i < nx; ++i)
        {
            vector<T> v(ny, 0);
            this->push_back(v);
        }
    }

    T get(int i, int j)
    {
        //return (*this)[i][j];
        return this->at(i).at(j);
    }
    void set(int i, int j, T d)
    {
        //(*this)[i][j] = d;
        this->at(i).at(j) = d;
    }
    void resize(int nx, int ny)
    {

        this->nx = nx;
        this->ny = ny;

        /*
        原先：  2 x 5
        要调整为： 3 x 7
        3 x 5
        3 x 7
        is a 
        Dog: Animal
        Dog is a Animal
        Array2D: vector<xxx>
        Array2D is a vector
        */
        //调整一维
        vector< vector< T > >::resize(nx);

        //调整二维度大小
        for (int i = 0; i < this->size(); ++i)
        {
            //(*this)[i].resize(ny);
            this->at(i).resize(ny);
        }
    }
};

void test()
{
    cout << "testing." << endl;

    //init
    Array2D<int> a2d(3, 6);

    //get, set
    assert(a2d.get(1, 2) == 0);
    a2d.set(1, 2, 999);
    assert(a2d.get(1, 2) == 999);
    a2d.set(1, 2, 666);
    assert(a2d.get(1, 2) == 666);

    //check size before resize
    assert(a2d.size() == 3);
    assert(a2d.at(0).size() == 6);

    //resize smaller
    a2d.resize(2, 5);
    assert(a2d.size() == 2);
    assert(a2d.at(0).size() == 5);
    assert(a2d.get(1, 2) == 666);

    //resize larger
    a2d.resize(4, 7);
    assert(a2d.size() == 4);
    assert(a2d.at(0).size() == 7);
    assert(a2d.get(1, 2) == 666);

    cout << "test passed." << endl;
}

//
void test2()
{
    /*
    实际上，因为Array2D继承了vector<vector<T>>，可以写成这样：
    a2d[x][y]
    有点像二维数组的意思
    */
    Array2D<int> a2d(2, 5);

    a2d.set(1, 2, 888);
    assert(a2d.get(1, 2) == 888);

    a2d[1][2] = 666;
    assert(a2d[1][2] == 666);
    assert(a2d.get(1, 2) == 666);
}


void testassert(){
    cout << "start" << endl;
    int i =1, j= 3;
    assert( (i+j)==3 );
    cout << "end" << endl;
}

int main()
{
    test();
    test2();
    testassert();
    return 0;
}