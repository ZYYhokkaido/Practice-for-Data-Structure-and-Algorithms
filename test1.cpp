
#include <vector>
using namespace std;

/*


*/
template <class T>
class Array2D : public vector<vector<T>> // public vector
{
private:
    int nx, ny;

public:
    Array2D(int nx, int ny)
    {
        this->nx = nx;
        this->ny = ny;
        //对
        //是不是很懵，我的数据呢？我在哪，我是谁？我要干嘛？
        /*
      
        */

        //TODO 把所有数字都初始化为 0
        for (int i = 0; i < nx; ++i)
        {
            vector<int> v;               //一维数组  这一步不太懂  我想想先   我不懂的是为啥可以这样定义 为啥可以用vector？ 哈？为啥不行  这不是相当于在定义int的时候在里面用int来定义吗？
            for (int j = 0; j < ny; ++j) //我怎么感觉这是哲学问题...  hhh
            {
                v.push_back(0);
            }
            this->push_back(v); //这个类型才能push进去
        }

        /*我想想
        比如 nx=2, ny=5
        那vector v每次都是  0 0 0 0 0
        往this里面push两次，不就是：
        0 0 0 0 0    (这一行实际上是vector<T>，有5个元素)
        0 0 0 0 0
        了嘛
        这样就是二维数组了

        因为this这个vector（它是一个vector）包含的类型是vector<T>  这个理解   
        所以要给它加元素的话这个元素就必须是vector<T>
        你看看上面的例子
        */

        for (j = 0; j++; j < ny)
        {
            this->push_back(0); //这样也不对噢，this装的是vector<int>，不能push int类型  哈？  "this装的是vector<int>"这句话啥意思？ 还是不太懂 我发现了 看上面

            //hint： 用push_back()
            //hint: 做一个临时vector，往里面push_back ny个0，然后把这个vector push_back到this里面，做nx次
        }

        for (i = 0; i++; i < nx)
        {
            this->
        }

        //类似这样，这个函数是把东西放到vector里面
        //嗯，你先写完。 多尝试，别怕
    }
    T get(int i, int j)
    {
        return this->att;
    }

    void set(int i, int j, T d)
    {
        this->array[i][j] = d;
    }

    void resize(int nx, int ny)
    {
    }

}

int
main()
{
    vector<int> v = {3, 4, 5};
    v.push_back(2);
    v.push_back(6);

    for (int n : v)
    {              //what is this int n:v  ok for n in v   就是循环嘛，跟python写法差不多的吧这个，c++也有这种写法
        cout << n; //3 4 5 2 6
    }

    cout << v[2]; //5
}