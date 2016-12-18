#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define LLD "%lld"
using namespace std;
typedef long long LL;
// for
#define rep(i,a,b) for(int i=a, _##i=(b); i<=_##i; ++i)
#define per(i,a,b) for(int i=a, _##i=(b); i>=_##i; --i)
// array
#define ran(a,l,n) a+l,a+l+n
#define clr(a,v) memset(a, v, sizeof(a));
// vector
#define vran(a) a.begin(),a.end()
#define repv(i,v) for(int i=0;i<(v).size();i++)
#define pb push_back
// pair 
typedef pair<int,int> pii;
#define mp make_pair
#define fi first
#define se second
// read & write
#define IOS_ONLY ios_base::sync_with_stdio(0)
template<class T>
inline void read(T& num) {
    bool start=false,neg=false;
    char c;
    num=0;
    while((c=getchar())!=EOF) {
        if(c=='-') start=neg=true;
        else if(c>='0' && c<='9') {
            start=true;
            num=num*10+c-'0';
        } else if(start) break;
    }
    if(neg) num=-num;
}
// const number
const int MOD = int(1e9)+7;
const int maxn = (int)1.01e5;
const int maxm = (int)1.01e5;
/* template end */

int a[maxn];
int n;

int main() {
	int T = 1;
	//read(T);
	rep(kase,1,T){
		read(n);

	}
}