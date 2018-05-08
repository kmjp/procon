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

struct SplitMix64 {
    unsigned long long nextInt() {
        unsigned long long z = (x += 0x9E3779B97F4A7C15ULL);
        z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
        z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
        return z ^ (z >> 31);
    }
    
    int random() {
        return 1 + (nextInt() >> 33);
    }
    
    unsigned long long x;
};

ll V[1<<23];

void init(const vector< vector<int> >& A) {
}

int query(int K) {
	return V[K&((1<<23)-1)];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
    int N, M, Q; 
    SplitMix64 rng;
    
    cin >> N >> M >> Q >> rng.x;
    
    vector< vector<int> > A(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = rng.random();
            V[i|j]^=A[i][j];
        }
    }
    FOR(i,23) FOR(x,1<<23) if(x&(1<<i)) V[x]^=V[x^(1<<i)];
    
    
    unsigned long long hashSol = 0;
    
    for (int i = 1; i <= Q; i++) {
        hashSol ^= (unsigned long long)i * query(rng.random());
    }
    
    cout << hashSol << endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
