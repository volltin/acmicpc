Lucas 定理

Lucas定理用来求C（a,b）mod p的值,其中p为素数。

Lucas\(a,b,q\)=C\(a%q,b%q\)\*Lucas\(a/p,b/p,p\);

Lucas\(a,0,q\)=0;

通过这个定理就可以很方便的把大数的组合转化成小数。但其中还是要求C\(a%q,b%q\)%p，所以这里引入逆元来求。

【定义】若整数a,b,p, 满足a·b≡1\(mod p\).则称a 为b 模p 的乘法逆元, 即a=b- 1mod p.其中, p 是模数。

应用到组合数中来就是:

 a!/\[b!\*\(a-b\)!\] % p == a! \* \[b!\*\(a-b\)!\]-1 %p

C\(n,m\)=C\(n-1,m-1\)+C\(n-1,m\)

快速计算组合数对MOD取余：

C\(n, m\)%MOD = \(m!%MOD\)\*\(n!%MOD\*\(m-n\)!%MOD\)^\(MOD-2\)%MOD。需要用到快速幂取模。

```cpp
#include <cstdio>    
#include <iostream>    
#include <cmath>    
#include <cstring>    
#include <algorithm>    
using namespace std;    
#define maxn 100010    
typedef long long LL;    
LL m,n,p;    
LL Pow(LL a,LL b,LL mod)    
{    
    LL ans=1;    
    while(b)    
    {    
        if(b&1)   ans=(ans*a)%mod;    
        b/=2;    
        a=(a*a)%mod;    
    }    
    return ans;    
}    
LL C(LL n,LL m)    
{    
    if(n<m)    
        return 0;    
    LL ans=1;    
    for(int i=1;i<=m;i++)    
    {    
        ans=ans*(((n-m+i)%p)*Pow(i,p-2,p)%p)%p;    
    }    
    return ans;    
}    
LL Lucas(LL n,LL m)    
{    
    if(m==0)    
        return 1;    
    return (Lucas(n/p,m/p)*C(n%p,m%p))%p;    
}    
int main()    
{    
    int t;    
    scanf("%d",&t);    
    while(t--)    
    {    
        scanf("%lld%lld%lld",&n,&m,&p);    
        printf("%lld\n",Lucas(n,m));    
    }    
    return 0;    
}   
```



