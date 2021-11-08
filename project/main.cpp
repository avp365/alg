#include <iostream>
#include <math.h>
using namespace std;

class Paint
{

private:
    int w, h, i, j;
    string **map;

public:
    Paint(int w, int h) : w(w), h(h)
    {

        map = new string *[h];

        for (i = 0; i < h; i++)
        {
            map[i] = new string[w];
        }
    }

    void spell()
    {

        for (i = 0; i < h; i++)
        {
            for (j = 0; j < w; j++)
            {

                map[i][j] =  j/(i+1) == 1  ? "#" : "*";
            }
        }
    }

    void spell09()
    {

        for (i = 0; i < h; i++)
        {
            for (j = 0; j < w; j++)
            {

                map[i][j] =  (i + 10 <= j) ||  (i >= j + 10)  ? "#" : "*";
            }
        }
    }

    void spell08()
    {

        for (i = 0; i < h; i++)
        {
            for (j = 0; j < w; j++)
            {

                map[i][j] = i < 1 || j < 1? "#" : "*";
            }
        }
    }


    void spell07()
    {

        for (i = 0; i < h; i++)
        {
            for (j = 0; j < w; j++)
            {

                map[i][j] = i < 15 || j < 15? "*" : "#";
            }
        }
    }

    void spell06()
    {

        for (i = 0; i < h; i++)
        {
            for (j = 0; j < w; j++)
            {

                map[i][j] = i < 10 || j < 10? "#" : "*";
            }
        }
    }

    void spell05()
    {

        for (i = 0; i < h; i++)
        {
            for (j = 0; j < w; j++)
            {

                map[i][j] = i == (j) / 2 ? "#" : "*";
            }
        }
    }

    void spell04()
    {

        for (i = 0; i < h; i++)
        {
            for (j = 0; j < w; j++)
            {

                map[i][j] = j <= w + 4 - i ? "#" : "*";
            }
        }
    }

    void spell03()
    {

        for (i = 0; i < h; i++)
        {
            for (j = 0; j < w; j++)
            {

                map[i][j] = j == w - 1 - i ? "#" : "*";
            }
        }
    }

    void spell02()
    {

        for (i = 0; i < h; i++)
        {
            for (j = 0; j < w; j++)
            {

                map[i][j] = j == i ? "#" : "*";
            }
        }
    }

    void spell01()
    {

        for (i = 0; i < h; i++)
        {
            for (j = 0; j < w; j++)
            {

                map[i][j] = j > i ? "#" : "*";
            }
        }
    }

    void fillBox()
    {

        for (i = 0; i < h; i++)
        {
            for (j = 0; j < w; j++)
            {
                map[i][j] = "\033[1;31mx";
            }
        }
    }

    void fillLine()
    {

        for (j = 0; j < w; j++)
        {
            map[0][j] = "\033[1;31mx";
        }
    }

    void fillLineRecursion(int j)
    {
        if (j >= w)
        {
            return;
        }

        map[0][j] = "\033[1;31mx";

        fillLineRecursion(j + 1);
    }

    void output()
    {
        cout << "\x1B[2J\x1B[H";
        for (i = 0; i < h; i++)
        {
            for (j = 0; j < w; j++)
            {
                cout << map[i][j] << " ";
            }

            cout << "\n";
        }
    }
};

int main()
{

    Paint Paint(25, 25);
    Paint.spell();
    Paint.output();
}