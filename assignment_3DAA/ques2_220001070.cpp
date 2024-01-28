#include<bits./stdc++.h>
using namespace std;

int maxSubarraySum(vector<int>& arr, int low, int high) {
    if (low == high) {
        return arr[low];
    }
    int mid = (low + high) / 2;
    int leftMax = maxSubarraySum(arr, low, mid);
    int rightMax = maxSubarraySum(arr, mid + 1, high);
    int leftCrossingMax = INT_MIN, rightCrossingMax = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; --i) {
        sum += arr[i];
        if (sum > leftCrossingMax) {
            leftCrossingMax = sum;
        }
    }
    sum = 0;
    for (int i = mid + 1; i <= high; ++i) {
        sum += arr[i];
        if (sum > rightCrossingMax) {
            rightCrossingMax = sum;
        }
    }
    return max({leftMax, rightMax, leftCrossingMax + rightCrossingMax});
}

int maxSubarraySum(vector<int>& arr) {
    return maxSubarraySum(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {10,-20,3,4,5,-1,-1,12,-3,1};

    int result = maxSubarraySum(arr);

    cout << "The largest possible sum of a subsequence is: " << result << endl;

    return 0;
}
