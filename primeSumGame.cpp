#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;  
  
  // generating sieve
  bool prime[200 + 1]; //'end' can be 200 max as b & d can be 100 max each
  memset(prime, true, sizeof(prime));
 
  for (int p = 2; p * p <= 200; p++){
    if (prime[p] == true){    
      for (int i = p * p; i <= 200; i += p)
        prime[i] = false;
    }
  }
  
  int nums[201], temp = 0;
  nums[0] = 0;
  for (int i = 0; i < 201; i++){
    if (prime[i]) {
      nums[i] = nums[i-1]+1;
    }
    else nums[i] = nums[i-1];
  }
  
  bool flag = true;
 
  for (int i=a; i<=b; i++){
    if (nums[i+d]-nums[i+c-1] == 0) {
      cout << "Takahashi" << endl;
      flag = false;
      break;
    }
  }
  if (flag) cout << "Aoki" << endl;  
  
  return 0;
}
