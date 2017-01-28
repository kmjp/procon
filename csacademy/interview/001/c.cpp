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

vector<string> P[13];

void generateParentheses(int N) {
	int i,j,k,l,r,x,y; string s;
	
	P[0].push_back("");
	for(i=1;i<=12;i++) {
		for(x=1;x<=i;x++) {
			FORR(r,P[x-1]) FORR(r2,P[i-x]) P[i].push_back("("+r+")"+r2);
		}
		sort(ALL(P[i]));
	}
	
	cin>>N;
	FORR(r,P[N]) cout<<r<<endl;
}


int main() {
    int N;
    cin >> N;
    generateParentheses(N);
    return 0;
}