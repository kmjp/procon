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

class ProductOfNumbers {
public:
	vector<pair<int,int>> V;
    ProductOfNumbers() {
        V.clear();
    }
    
    void add(int num) {
		if(V.empty() || V.back().first!=num) V.push_back({num,0});
		V.back().second++;
    }
    
    int getProduct(int k) {
		ll ret=1;
		int i,j;
		for(i=V.size()-1;i>=0;i--) {
			if(k<=0) break;
			if(V[i].first==0) {
				ret=0;
				break;
			}
			if(V[i].first==1) {
				k-=V[i].second;
				continue;
			}
			FOR(j,V[i].second) {
				if(k<=0) break;
				ret*=V[i].first;
				k--;
			}
			if(ret>=1LL<<32) {
				ret=0;
				break;
			}
		}
        return ret;
    }
};

