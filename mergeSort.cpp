#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int mod = 1000000007;
const int N = 1e5 + 10;

void mergeTwoSorted(vector<int> &toSort, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    
    while (left <= mid && right <= high)
    {
        if (toSort[left] < toSort[right])
        {
            temp.push_back(toSort[left]);
            left++;
        }
        else
        {
            temp.push_back(toSort[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(toSort[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(toSort[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        toSort[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &toSort, int low, int high)
{
    if (high - low == 0)
    {
        return;
    }

    int mid = (low + high) / 2;

    mergeSort(toSort, low, mid);
    mergeSort(toSort, mid + 1, high);
    mergeTwoSorted(toSort, low, mid, high);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> toSort(n);

    for (int &i : toSort)
    {
        cin >> i;
    }

    mergeSort(toSort, 0, n - 1);

    for (int &i : toSort)
    {
        cout << i << " ";
    }
    cout << endl;
}
