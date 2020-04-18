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



class Solution {
public:
    int findMinFibonacciNumbers(int k) {
		vector<ll> V;
		V.push_back(1);
		V.push_back(1);
		int i;
        FOR(i,50) V.push_back(V.back()+V[V.size()-2]);
        cout<<V.back()<<endl;
        
        int ret=0;
        reverse(ALL(V));
        FORR(v,V) {
			while(k>=v) k-=v, ret++;
		}
        return ret;
    }
};

