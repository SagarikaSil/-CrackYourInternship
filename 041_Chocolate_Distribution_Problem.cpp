// Chocolate Distribution Problem

// Given an array of n integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that: 
// 1.Each student gets one packet.
// 2.The difference between the number of chocolates in the packet with maximum chocolates and packet with minimum chocolates given to the students is minimum.

#include <bits/stdc++.h>
using namespace std;
 
int findMinDiff(int arr[], int n, int m)
{
    if (m == 0 || n == 0)
        return 0;
 
    sort(arr, arr + n);
 
    if (n < m)
        return -1;
 
    int min_diff = INT_MAX;
 
    for (int i = 0; i + m - 1 < n; i++) {
        int diff = arr[i + m - 1] - arr[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}
 
int main()
{
    int arr[] = { 12, 4,  7,  9,  2,  23, 25, 41, 30,
                  40, 28, 42, 30, 44, 48, 43, 50 };
    int m = 7; // Number of students
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum difference is "
         << findMinDiff(arr, n, m);
    return 0;
}