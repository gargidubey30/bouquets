#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int>&v,int day, int m, int k)
{    
    int n=v.size();
    int cnt = 0;
    int nob = 0;

    // count the number of bouquets
    for (int i = 0; i < n ; i++)
    {
        if (v[i] <= day)
        {
            cnt++;
        }
        else
        {
            nob += (cnt / k);
            cnt=0;
        }
    }
    // when loop ends check once more that bouquet can be formed or not
     nob += (cnt / k);
      return nob >= m;
  
}

///////////brute force 
// int minimumdaysToMbouquets(vector<int>v,int m, int k){
//      long long val = m * 1ll * k * 1ll;
//     int n = v.size(); //size of the array
//     if (val > n) return -1; //impossible case.

//     int mini = INT_MAX, maxi = INT_MIN;
//     for (int i = 0; i < n; i++) {
//         mini = min(mini, v[i]);
//         maxi = max(maxi, v[i]);
//     }
     
//      for(int i=mini; i<=maxi; i++){
        
//        if( possible(v,i,m,k))
//          return i;
       

//       }
//      return -1;
// }

//////////////////////binary search
int minimumdaysToMbouquets(vector<int>v,int m, int k){
     long long val = m * 1ll * k * 1ll;
    int n = v.size(); //size of the array
    if (val > n) return -1; //impossible case.

    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, v[i]);
        maxi = max(maxi, v[i]);
    }
     //apply binary search:
    int low = mini, high = maxi;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (possible(v, mid, m, k)) {
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return low;
}


int main()
{
vector<int> v = {7,7,7,7,13,11,12,7};
  int m=2, k=3;
   int n = v.size();
    int ans = minimumdaysToMbouquets(v,m,k);
  
     if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";  
   return 0;

}











