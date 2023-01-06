#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

int FindMaxCrossingSubarray(int *A, int low, int mid, int high) {
  //double b = std::numeric_limits<double>::infinity();
  int leftSum = -1 * int(INFINITY);
  // int rightSum;
  int sum = 0;
  int maxLeft;
  int maxRight;
  for (int i = mid; i >= low; i--) {
    sum = sum + A[i];
    if (sum > leftSum) {
      leftSum = sum;
      int maxLeft = i;
    }
  }
  int rightSum = -1 * int(INFINITY);
  sum = 0;
  for (int j = mid + 1; j <= high; j++) {
    sum = sum + A[j];
    if (sum > rightSum) {
      rightSum = sum;
      int maxRight = j;
    }
  }
  return (maxLeft, maxRight, leftSum + rightSum);
}

int FindMaxSubarray(int *A, int low, int high) {
  // int mid;
  // int leftLow;
  // int leftHigh;
  // int leftSum;
  // int rightLow;
  // int rightHigh;
  // int rightSum;
  // int crossSum;
  // int crossHigh;
  // int crossLow;
  if (high == low) {
    return (low, high, A[low]); // for base case of 1 element
  } else {
    int mid = floor((low + high) / 2);
    int leftLow, leftHigh, leftSum = FindMaxSubarray(A, low, mid);

    int rightLow, rightHigh, rightSum = FindMaxSubarray(A, mid + 1, high);
    
    int crossLow, crossHigh, crossSum = FindMaxCrossingSubarray(A, low, mid, high);
  

  if (leftSum >= rightSum && leftSum >= crossSum) {
    return (leftLow, leftHigh, leftSum);
  } 
  else if (rightSum >= leftSum && rightSum >= crossSum) {
    return (rightLow, rightHigh, rightSum);
  } 
  else
    return (crossLow, crossHigh, crossSum);
  }
}

int main(){
  int n = 1;
  // int p = 0;
  // int n;
  cin >> n;   // take in amount
  int arr[n]; // create an array with space for that many elements
  for (int i = 0; i < n; i++) {
    cin >> arr[i]; // take each into the array 1 at a time
  }

  int lowF, highF, sumF = FindMaxSubarray(arr, 0, n-1);
  cout  << sumF;
}