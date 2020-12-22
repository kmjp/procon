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
    string reformatNumber(string number) {
		string S;
		FORR(c,number) {
			if(c>='0'&&c<='9') S+=c;
		}
		cout<<S<<endl;
		
		int N=S.size();
		int i;
		string R;
		if(N%3==0) {
			FOR(i,N) {
				if(i%3==0&&i) R+="-";
				R+=S[i];
			}
		}
		else if(N%3==2) {
			FOR(i,N) {
				if(i%3==0&&i) R+="-";
				R+=S[i];
			}
		}
		else if(N%3==1) {
			string T=S.substr(0,N-4);
			FOR(i,T.size()) {
				if(i%3==0&&i) R+="-";
				R+=T[i];
			}
			if(T.size()) R+="-";
			R+=S.substr(N-4,2);
			R+="-"+S.substr(N-2,2);
		}
		return R;
		
        
    }
};

