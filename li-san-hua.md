# 离散化

相当于一个从给定数据输入到 0……n - 1 的完全hash。

```cpp
//将输入的数据存入uni中，注意数组uni会被破坏。
//函数r(x)获取输入数据x对应的编号
//uni[k]获取编号为k的输入数据
//注意编号从0开始
std::vector<int> uni;
inline int r(int k){
        return lower_bound(uni.begin(),uni.end(),k)-uni.begin();
}

int main(){
    //...input
    sort(uni.begin(),uni.end());
    uni.erase(unique(uni.begin(),uni.end()),uni.end());
}
```



