#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int banknotes(int A, int B, int S, int N) {
    ll BN=1LL*B*N;
    if((S-BN)%(A-B)) return -1;
    ll a=(S-BN)/(A-B);
    if(a<0 || a>N) return -1;
    return (S-BN)/(A-B);
}



int main() {
    int A, B, S, N;
    cin >> A >> B >> S >> N;
    cout << banknotes(A, B, S, N) << "\n";
    return 0;
}
