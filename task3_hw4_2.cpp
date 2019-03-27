#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;


class Snowman{
    int m_ball;
    int m_weight;
    int m_lastBallFrom;
    int m_iter;
public:
     Snowman()
    {
        m_ball = 0;
        m_weight =0;
        m_lastBallFrom = 0;
        m_iter = 0;
    }
    Snowman(int ball, int weight, int lastBallFrom, int iter)
    {
        m_ball = ball;
        m_weight = weight;
        m_lastBallFrom = lastBallFrom;
        m_iter = iter;
    }

    int getWeight()
    {
        return m_weight;
    }
    int getLastBall()
    {
        return m_ball;
    }
    int getLastBallFrom()
    {
        return m_lastBallFrom;
    }
    int getIter()
    {
        return m_iter;
    }
};


int main()
{
    vector<Snowman> snowmen;
   Snowman zeroSnowMan;
    snowmen.push_back(zeroSnowMan);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        int m;
        cin >> m;
        if(p == 0)
        {
            Snowman current(m, m, 0, 0);
            snowmen.push_back(current);
            cout << "w = " << m << endl;
        } else
        {
            int w = snowmen[p].getWeight();
            cout << "w " << w << endl;
            if(m != 0)
            {
                Snowman current(m, w + m, 0, p);
                snowmen.push_back(current);
                cout << "w + m = " << w + m << endl;
            }
            if(m == 0)
            {
                int lastBallFrom = snowmen[p].getLastBallFrom();
                cout << "last ball from: " << lastBallFrom << endl;
                if(lastBallFrom == 0)
                {
                    int lastBallToRemove = snowmen[p].getLastBall();
                    int iter = snowmen[p].getIter();
                    cout << "iter = " << iter << endl;
                    int m_ball = snowmen[iter].getLastBall();
                    cout << "last m_ball = " << m_ball << endl;
                    Snowman current(m_ball, w - lastBallToRemove, iter, p);
                    snowmen.push_back(current);
                } else
                {
                    int lastBallToRemove = snowmen[p].getLastBall();
                    int lastBall = snowmen[p].getLastBallFrom();
                    int lastball_from = snowmen[lastBall].getLastBallFrom();
                    int m_ball = snowmen[lastball_from - 1].getLastBall();
                    cout << "last m_ball = "<< m_ball << endl;
                    cout << "w - lastBallToRemove = " << w - lastBallToRemove << endl;

                    Snowman current(m_ball, w - lastBallToRemove, lastball_from - 1, p);
                    snowmen.push_back(current);


                }

            }
        }
    }

   long sum = 0;
   for(int i = 0; i <= n; i++)
   {
        sum+= snowmen[i].getWeight();
   }
    cout << sum;
    return 0;
}
