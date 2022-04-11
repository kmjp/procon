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
    string minimizeResult(string expression) {
		string A,B;
		int i;
		int N=expression.size();
		FOR(i,N) if(expression[i]=='+') {
			A=expression.substr(0,i);
			B=expression.substr(i+1);
		}
		cout<<A<<" "<<B<<endl;
		ll mi=1LL<<60;
		string R="("+expression+")";
		int x,y;
		FOR(x,A.size()) {
			for(y=1;y<=B.size();y++) {
				ll v=1;
				if(x) v*=atoll(A.substr(0,x).c_str());
				if(y<B.size()) v*=atoll(B.substr(y).c_str());
				v*=atoll(A.substr(x).c_str())+atoll(B.substr(0,y).c_str());
				if(v<mi) {
					mi=v;
					R=A.substr(0,x)+"("+A.substr(x)+"+"+B.substr(0,y)+")"+B.substr(y);
				}
				
			}
		}
		return R;
		
        
    }
};
