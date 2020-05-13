#include <iostream>
#include <vector>

using namespace std;

long C(long n)
{
    return (n - 1) * n / 2;
}

int main()
{
    long n, d;
    cin >> n >> d;
    vector<long> list(n);
    long ans = 0;
    for (long i = 0, j = 0; i < n; i++)
    {
        cin >> list[i];
        while (i >= 2 && (list[i] - list[j]) > d)
        {
            j++;
        }
        ans += ((i - j - 1) * (i - j) / 2);
    }

    cout << ans % 99997867;
    return 0;
}