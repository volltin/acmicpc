# 快速乘和快速幂

## 快速乘（带模）

用于模数很大的情况

```cpp
// x * y % p
inline LL mulmod(LL x, LL y, LL p) {
	LL ret = 0;
	for(; y; y >>= 1) {
		if(y & 1) ret = (ret + x) % p;
		x = (x + x) % p;
	}
	return ret;
}
```

## 快速幂（带模）

提示：在模数固定的情况下，对常量取模可以得到编译器的优化。

```cpp
// with mulmod
inline LL mulmod(LL x, LL y, LL m);
inline LL powmod(LL a, LL p, LL m)
{
    LL ret = 1;
    for (; p; p >>= 1) {
        if (p & 1) ret = mulmod(ret, a, m);
        a = mulmod(a, a, m);
    }
    return ret;
}

// without mulmod
inline LL _powmod(LL a, LL p, LL m)
{
    LL ret = 1;
    for (; p; p >>= 1) {
        if (p & 1) ret = (ret * a) % m;
        a = (a * a) % m;
    }
    return ret;
}
```



