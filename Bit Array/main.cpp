#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

static unsigned int n, s, p, q;

unsigned int f(unsigned int x) {
    unsigned int t = (unsigned long long int) x * p + q;
    return t;
}

unsigned int brent(unsigned int s) {
    unsigned int power = 1;
    unsigned int lam = 1;
    unsigned int tortoise = s;
    unsigned int hare = f(tortoise);
    unsigned int k = 0; // total number of calls
    unsigned int prev;
    
    while (tortoise != hare) {
        if (power == lam) {
            tortoise = hare;
            power *= 2;
            lam = 0;
        }
        prev = hare;
        hare = f(hare);
        lam++;
        k++;
        if (k == n) { //special case = we haven't found a cycle after n iterations of the function f
            return n;
        }
    }
    /*
    cout << "th " << tortoise << endl;
    cout << "hare " << hare << endl;;
    cout << "prev " << prev << endl;
    cout << "pow " << power << endl;
    cout << "lam " << lam << endl;
    cout << "k " << k << endl;
    */
    
    //find first repetition of length lambda
    
    unsigned int mu = 0;
    tortoise = s;
    hare = s;
    
    for (int i = 0; i < lam; i++) {
        hare = f(hare);
    }
    
    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(hare);
        mu++;
    }
    
    return mu;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> n >> s >> p >> q;
        
    unsigned int lambda = brent(s);
    
    cout << lambda << endl;
    
    //cout << s << endl << f(s) << endl << f(f(s)) << endl;
    
    return 0;
}
