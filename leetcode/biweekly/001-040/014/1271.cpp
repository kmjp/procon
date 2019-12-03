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
    string toHexspeak(string num) {
		ll N=atoll(num.c_str());
		string S;
		while(N) {
			int x=N%16;
			if(x==0) S+='O';
			if(x==1) S+='I';
			if(x==10) S+='A';
			if(x==11) S+='B';
			if(x==12) S+='C';
			if(x==13) S+='D';
			if(x==14) S+='E';
			if(x==15) S+='F';
			if(x>=2 && x<=9) return "ERROR";
			N/=16;
		}
		reverse(ALL(S));
		return S;
        
    }
};

