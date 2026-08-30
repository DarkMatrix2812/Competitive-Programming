#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int count = 0; count < t; count++)
    {
        int ans = 0;
        int n;
        cin >> n;
        int arr[2 * n];
        int tmp = 1;
        arr[n - 1] = n;
        arr[2 * n - 1] = n;
        for (int i = n - 1; i >= 0; i --) 
        {
            arr[i - 1] = tmp;
            arr[2 * n - 1 - i] = tmp;
            tmp += 1;
        }
        for (int i = 0; i < 2 * n; i++) 
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}