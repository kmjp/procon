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

int fourXtremes(int a, int b, int c, int d) {
	return max({a,b,c,d})-min({a,b,c,d});
}


int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << fourXtremes(a, b, d, c) << "\n";
    return 0;
}