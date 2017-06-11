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

unsigned long long B[50000000/64+1];
template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,17> bt;


struct RandGen {
	int x, y, z;

	int nextInt() {
		int t = x ^ (x << 11);
		x = y;
		y = z;
		z ^= (z >> 19) ^ t ^ (t >> 8);
		return z;
	}

	int random(int N) {
		return nextInt() % N;
	}
};

void init(int N, int M) {
}

void flipPosition(int poz) {
	unsigned long long m=1ULL<<(poz&63);
	if(B[poz>>6] & m) {
		bt.add((poz>>10)+1,-1);
	}
	else {
		bt.add((poz>>10)+1,+1);
	}
	B[poz>>6] ^= m;
}

int getCount(int st, int fn) {
	int ret=0;
	
	if(fn-st<=128) {
		while(st<=fn) {
			if(B[st>>6]&(1ULL<<(st&63))) ret++;
			st++;
		}
	}
	else {
		while(st&63) {
			if(B[st>>6]&(1ULL<<(st&63))) ret++;
			st++;
		}
		while((fn&63)!=63) {
			if(B[fn>>6]&(1ULL<<(fn&63))) ret++;
			fn--;
		}
		if(fn-st<=2048) {
			while(st<=fn) {
				ret+=__builtin_popcountll(B[st>>6]);
				st+=64;
			}
		}
		else {
			while(st&1023) {
				ret+=__builtin_popcountll(B[st>>6]);
				st+=64;
			}
			while((fn&1023)!=1023) {
				ret+=__builtin_popcountll(B[fn>>6]);
				fn-=64;
			}
			if(st<fn) ret+=bt((fn+1)>>10)-bt((st>>10));
		}
	}
	
	return ret;
}

int main() {
	int N, M;
	RandGen rng;
	cin >> N >> M >> rng.x >> rng.y >> rng.z;

	init(N, M);

	long long hashSol = 0;

	for (long long i = 0; i < M; i++) {
		if (rng.random(2) == 0) {
			const int poz = rng.random(N);
			flipPosition(poz);
		}
		else {
			int st = rng.random(N), fn = rng.random(N);
			if (st > fn) {
				swap(st, fn);
			}
			hashSol ^= i * getCount(st, fn);
		}
	}

	cout << hashSol << "\n";
}
