#include <iostream>
using namespace std;
#include <vector>
#include <algorithm> 
#include <bits/stdc++.h>
#include <unordered_map>

int main() {
ios_base::sync_with_stdio(false);
cin.tie(nullptr);

  int topindex [51];
  memset(topindex, 0, sizeof(topindex));
  int n, q;
  cin >> n  >> q;
  
  for(int i = 0; i < n; i ++){
    int c;
    cin >> c;
    if(topindex[c] == 0){
      topindex[c] = i+1;
    }
  }
  
  for(int i = 0; i < q; i ++){
    int c;
    cin >> c;
    int t = topindex[c];
    cout << t << " ";
    for(int j = 1; j < 51; j ++){
      if(topindex[j] < t){
	topindex[j] ++;
      }
    }
    topindex[c] = 1;
  }
  cout << endl;
}