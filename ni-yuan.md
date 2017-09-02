# 逆元

下面均指求 $$a$$ 关于 $$M$$ 的逆元 $$inv(a)$$

**一、M 为质数，费马小定理：**

$$a^(M-1) === 1 \mod M$$

$$a * a^(M-2) === 1 \mod M$$

$$inv(a) := a^{(M-2)}$$



**二、M 不为质数，但是 $$gcd(a, M) = 1$$，用扩展欧几里得（注意处理正负）：**

$$ax + My \equiv gcd(a, M)\equiv 1$$

$$ax \equiv 1 \mod M$$

$$inv(a) := x$$



**三、递推法，O(n) 得到 1!, 2!, …, n! 逆元：**

$$n! * inv(n!) \equiv 1 \mod M$$

$$(n-1)! * n * inv(n!) === 1 \mod M$$

$$inv((n-1)!) := (n * inv(n!)) \% M$$



**四、递推法，O(n) 得到 1 - n 逆元：**

要求 M 为奇质数

$$inv(1) := 1$$

$$inv(i) := (M - M / i) * inv(M \% i) \% M$$

证明如下：

两边同时乘 i：

$$1 \equiv i * inv(i) \equiv (Mi - [M / i] * i) * inv(M \% i) \mod M$$

而$$ (Mi - [M / i] * i) === M \% i \mod M$$



**五、inv 函数是积性函数**

积性函数f：$$a, b$$ 互素，那么  $$f(a * b) = f(a) * f(b)$$

此处甚至不需要 a, b 互素（同余式相乘可证）

$$exgcd$$ 先求出所有素数逆元 $$inv(pi)$$，预处理的时间复杂度是 $$O(n / logn * logn) = O(n)$$

然后用唯一分解的方法求任意数逆元

$$inv(n) := \prod{inv(pi)^{a_i}}$$



**六、计算组合数，Lucas 定理：**

**M 为素数**

记 $$p = M，n=sp + q , m=tp + r (q, r <= p)$$

$$C(n, m) = C(sp + q, tp + r) = C(s, t) * C(q, r) \mod p$$

即：$$C(n,m) \% p = C(n/p, m/p) * C(n\%p, m\%p) \% p$$

递归计算，$$m/p = 0$$ 的时候就是终点。

计算一个 $$Lucas$$ 的时间复杂度为：$$O(\log_p{n} * p)$$，适合用于 p 不大的情况。



**M 不为素数**

对 M 进行唯一分解。

**若质因子次数均不超过1**，计算 $$Lucas(n, m, p)$$ 得到同余方程组，利用中国剩余定理进行合并。

例如：$$C(n, m) % (2 * 3)$$ -> 同余方程组：
$$
x \equiv Lucas(n, m, 2) \mod 2
\\
x \equiv Lucas(n, m, 3) \mod 3
$$
**若质因子次数超过1**，将 $$p^t$$ 看为一个整体带入中国剩余定理的方程组，下面讲如何计算 $$Lucas(n, m, p^t)$$。
