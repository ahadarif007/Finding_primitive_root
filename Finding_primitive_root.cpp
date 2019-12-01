#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1) return false;
    for (int i = 2; i < n; i++) if (n % i == 0) return false;
    return true;
}

int powmod (int a, int b, int p) {
    int result = 1;
    while (b)
        if (b & 1) result = int (result * 1ll * a % p),  --b;
        else a = int (a * 1ll * a % p),  b >>= 1;
    return result;
}

int PrimitiveRootGenerator (int p) {
    if(isPrime(p)==true)
    {
      vector<int> fact;
    int phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (int result=2; result<=p; ++result) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (result, phi / fact[i], p) != 1;
        if (ok)  return result;
    }
    return -1;
    }
    else return -1;

}


int main()
{
    int p;
    cout<<"Enter A prime Number to find it's primitive root:";

    cin>> p;
    if(PrimitiveRootGenerator(p)!=-1)
    {
      cout<<"Primitive root of "<<p<<" is: "<<PrimitiveRootGenerator(p)<<endl;
    }
    else
        cout<<"number is not prime or valid primitive root is not possible for this particular number"<<endl;
}
