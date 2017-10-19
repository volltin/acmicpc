```cpp
typedef long long LL;
//求a^p mod m
//CQBZOJ 1156 AC
LL pow_mod(LL a, LL p, LL m)
{
    if (a >= m) a %= m;
    if (a == 0) return 0;
    if (p == 0) return 1;
    if (p == 1) return a%m;
    LL t = pow_mod(a, p/2, m);
    if (p&1) return (a*t%m*t)%m;
    else return (t*t)%m;
}
 
//最大公约数
//CQBZOJ 1480 AC
LL gcd(LL a, LL b)
{
    LL t;
    while(b)
    {
        t = a%b;
        a = b;
        b = t;
    }
    return a;
}
 
//扩展欧几里得
//CQBZOJ 2011 AC
void exgcd(LL a, LL b, LL &d, LL &x, LL &y)
{
    if (!b) {d = a; x = 1; y = 0;}
    else{exgcd(b, a%b, d, y, x); y -= x*(a/b);}
}
 
//判断一个数是否是质数
//CQBZOJ 2689 AC
bool is_prime(LL n)
{
    if (n == 1) return false;
    if (n == 2) return true;
    if (!n&1) return false; //注意 (!n&1)
    int m = sqrt(n+0.5);
    for (int i=2; i<=m; i++)
        if (n%i == 0) return false;
    return true;
}
 
//组合数C(n,m)
//CQBZOJ 2713 AC
LL C(LL n, LL k)
{
    if (k > n/2) k = n-k;
    LL ans = 1;
    for (int i=1; i<=k; i++)
        ans = ans * (n-k+i) / i;
    return ans;
}
 
//求逆元
//CQBZOJ 2011 AC
LL inverse(LL a, LL m)
{
    //ax ≡ 1 MOD b => ax + by = 1 [gcd(a,b) must be 1]
    LL d, x, y;
    exgcd(a, m, d, x, y);
    if (d != 1) return -1;
    return (x + m) % m;
}
 
//求逆元2 <要求m是质数>
//CQBZOJ 2011 AC
LL inverse2(LL a, LL m)
{
    if (!is_prime(m)) return -1;
    return pow_mod(a, m-2, m);
}
 
//求C(n,k)%MOD 要求都存在逆元
//CQBZOJ 2011 AC
LL C_MOD(LL n, LL k, LL MOD)
{
    LL ans = 1;
    if (k > n/2) k = n-k;
    for (int i=1; i<=k; i++)
    {
        ans *= (n-k+i);
        ans %= MOD;
        ans *= inverse(i, MOD);
        ans %= MOD;
    }
    return ans;
}
 
//单个数的欧拉函数值
//CQBZOJ 2710 AC
LL phi(LL n)
{
    int m = sqrt(n +0.5);
    LL ans = n;
    for (int i=2; i<=m; i++)
    {
        if (n == 1) break;
        if (n%i == 0)
        {
            ans /= i;
            ans *= (i-1);
        }
        while (n%i == 0)
            n /= i;
    }
    if (n > 1)
        ans /= n, ans *= (n-1);
    return ans;
}
 
//欧拉函数类似筛法
//CQBZOJ 2710 AC
//n = 10^7 100ms
//n = 5*10^7 600ms
void phi_table(int n, int* PHI)
{
    for (int i=2; i<=n; i++) PHI[i] = 0;
    PHI[1] = 1;
    for (int i=2; i<=n; i++) if (!PHI[i])
    {
        for (int j=i; j<=n; j+=i)
        {
            if (!PHI[j]) PHI[j] = j;
            PHI[j] = PHI[j] / i * (i-1);
        }
    }
}
 
//利用素数表辅助欧拉表
//by syk
void phi_prime_table(int n, int* prime, int* phi, bool* vis)
{
    int Pcnt = 0;
    phi[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(!vis[i])
        {
            prime[++Pcnt] = i;
            phi[i] = i-
        }
        for(int j = 1; j <= Pcnt && i * prime[j] <= n; j++)
        {
            vis[i * prime[j]] = true;
            if(i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}
 
#define MAXN 2000000
int PRIME[MAXN+10], PHI[MAXN+10];
bool VIS[MAXN+10];
 
int main()
{
    int n;
    phi_prime_table(MAXN, PRIME, PHI, VIS);
    //phi_table(MAXN, PHI);
    while(~scanf("%d", &n))
    {
        if (n == 0) break;
        if (n <= MAXN)
            printf("%d\n", PHI[n]);
        else
            printf("%d\n", phi(n));
    }
}
```



