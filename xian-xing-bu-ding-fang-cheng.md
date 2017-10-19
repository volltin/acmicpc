求关于x的同余方程ax≡1 \(mod b\)的最小正整数解。

```cpp
typedef long long LL;
void exgcd(LL a, LL b, LL &d, LL &x, LL &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        d = a;
    }
    else
    {
        exgcd(b, a%b, d, y, x);
        y -= a / b * x;
    }
}
 
int main()
{
    /* 模线性方程 ax ≡ 1 (MOD b) => ax + by = gcd(a, b) */
    LL a, b, d, x, y;
    scanf("%lld%lld", &a, &b);
    exgcd(a, b, d, x, y);
    // x => (x % b + b) % b
    printf("%lld", (x % b + b) % b);
}
```



