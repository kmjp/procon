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

class Cashier {
public:
	int N,M,D;
	map<int,int> P;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        N=n;
        M=1;
        D=discount;
        P.clear();
        int i;
        FOR(i,products.size()) P[products[i]]=prices[i];
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double ret=0;
        int i;
        FOR(i,product.size()) ret+=P[product[i]]*amount[i];
        if(M%N==0) {
			ret-=D*ret/100;
		}
        M++;
		return ret;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */