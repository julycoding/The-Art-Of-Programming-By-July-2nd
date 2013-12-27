#include <iostream>
#include <vector>

using namespace std;

void createCounter(vector<int>& counter, int n)
{
    vector<int> primes;
    counter.resize(n + 1, 0);
    counter[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        if (counter[i] == 0)
        {
            counter[i] = i + 1;
            primes.push_back(i);
        }

        for(size_t j = 0; j < primes.size(); j++)
        {
            if (primes[j] * i > n)
                break;

            if (i % primes[j] == 0)
            {
                int k = i;
                int l = primes[j] * primes[j]; 

                while(k % primes[j] == 0)
                {
                    l *= primes[j];
                    k /= primes[j];
                }

                counter[primes[j] * i] = counter[k] * (l - 1) / (primes[j] - 1);
                break;
            }
            else
                counter[primes[j] * i] = counter[i] * (primes[j] + 1);
        }
    }
}

int main ()
{

    int max = 5000000;
    vector<int> counter;
    createCounter(counter, max);

    for (size_t i = 0; i < counter.size(); i++)
    {
        size_t num = counter[i] - i;
        if (num < counter.size() && num > i && counter[num] == counter[i])
            cout << i << " " << num << endl;
    }

    return 0;
}
