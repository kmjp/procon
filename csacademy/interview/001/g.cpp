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

int productOfFive(vector<int>& v) {
	vector<ll> P;
	vector<ll> M;
	int Z=0;
	FORR(r,v) {
		if(r<0) M.push_back(-r);
		if(r>0) P.push_back(r);
		if(r==0) Z++;
	}
	
	ll ma=-1LL<<60;
	if(Z) ma=0;
	sort(ALL(P));
	sort(ALL(M));
	reverse(ALL(P));
	reverse(ALL(M));
	
	if(P.size()>=5) ma=max(ma,P[0]*P[1]*P[2]*P[3]*P[4]);
	if(P.size()>=3 && M.size()>=2) ma=max(ma,P[0]*P[1]*P[2]*M[0]*M[1]);
	if(P.size()>=1 && M.size()>=4) ma=max(ma,P[0]*M[0]*M[1]*M[2]*M[3]);
	reverse(ALL(P));
	reverse(ALL(M));
	if(M.size()>=5) ma=max(ma,-M[0]*M[1]*M[2]*M[3]*M[4]);
	if(M.size()>=3 && P.size()>=2) ma=max(ma,-M[0]*M[1]*M[2]*P[0]*P[1]);
	if(M.size()>=1 && P.size()>=4) ma=max(ma,-M[0]*P[0]*P[1]*P[2]*P[3]);
	return ma;
}
int main() {
    int N;
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        v.push_back(val);
    }
    
    cout << productOfFive(v) << "\n";
    return 0;
}
