#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int inverseModuloWithEuclid(int a, int n) {
  int x = 1, y = 0, r = n, R = a;
  if(n == 1) cout << "0";
  while(R > 1) {
    int q = r / R;

    int tmp1,tmp2;
    tmp1 = y;
    y = x;
    x = tmp1 - q * x;
    tmp2 = r;
    r = R;
    R = tmp2 - q * R;
  }
  if(R > 1) cout << "khong ton tai";
  else if( x <= 0) return x + n;
  else return x;
  return -1;
}

int main() {
    int n,m = 1;
    cout << "Nhap so phan tu cua he: "; cin >> n;
    int s[n], a[n];
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0;i < n; i++) {
        m *= s[i];
    }
    //cout << m;
    int M[n];
    for(int i = 0; i < n; i++) {
        M[i] = m / s[i];
    }
    int y[n];
    for(int i = 0; i < n; i++) {
        y[i] = inverseModuloWithEuclid(M[i], s[i]);
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
        res += a[i] * M[i] * y[i];
    }
    // for(int i = 0; i < n; i++) {
    //     cout << a[i] << " ";
    // }
    cout << "He phuong trinh co gia tri: " << res % m << endl;
}