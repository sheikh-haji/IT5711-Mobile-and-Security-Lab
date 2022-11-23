#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int a, long long int b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

long long int powerVal(long long int m, long long int n, long long int MOD) {
    long long int a = m;
    for (long long int i = 0; i < n-1; i++)
        m = ((m % MOD) * (a % MOD)) % MOD;
    return m % MOD;
}

class RSA {
    long long int p;
    long long int q;
    long long int n;
    long long int phi;
    long long int k = 2;

    long long int e;
    long long int d;

public:
    RSA(long long int p, long long int q){
        n = p * q;
        phi = (p - 1) * (q - 1);

        e = 2;
        for (; e < phi; e++)
            if (gcd(phi, e) == 1)
                break;

        d = 2;
        while ((e * d) % phi != 1)
            d++;

        cout << "Prikey: " << e << endl;
        cout << "Pubkey: " << d << endl;
    }

    vector<int> encrypt(string msg){
        vector<int> arr;

        for (int i:msg){
          int j=i-'a';
          arr.push_back(powerVal(j, e, n) % n);
        }


        return arr;
    }

    vector<int> decrypt(vector<int> msg){
        vector<int> arr;

        for (int i : msg){
            arr.push_back(powerVal(i, d, n) % n);
        }


        return arr;
    }
};

int main()
{
    int p, q;

    cout << "Enter prime number 1 : ";
    cin >> p;

    cout << "Enter prime number 2 : ";
    cin >> q;

    RSA ob = RSA(p, q);

    string msg;
    cout << "Enter a message = ";
    cin >> msg;

    vector<int> cip = ob.encrypt(msg);
    vector<int> pln = ob.decrypt(cip);

    for(int i = 0; i < msg.size(); ++i){
        cout << cip[i] << ' ';
    }
    cout << endl;

    for(int i = 0; i < msg.size(); ++i){
        cout <<(char)(pln[i]+'a');
    }

    return 0;
}
