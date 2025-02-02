



## vector

参考：[C++:STL常用函数模块总结(vector)](https://blog.csdn.net/IAMoldpan/article/details/78174423)


### 0. 初始化

```cpp
//#include <vector>
using namespace std; 

// 初始化一个int类型的空vector
vector<int> nums;

// 初始化一个包含3个int数据的vector，数据为0
vector<int> nums (3,0); 

// 通过指针复制
vector<int> copynums (nums.begin(),nums.end());

// 通过复制函数复制
vector<int> copynums (nums)
```



### 1. 容量，调整容量

```cpp
// 当前vector的容量
length = vector.size()

// 容器为空返回True，容器非空返回False
flag = nums.empty()

// 调整vector的容量
new_length = vector.resize(n,val);
```


### 2. 添加元素，插入元素

```
// 向vector中添加元素
nums.push_back(0);

// 在指定位置插入元素
vector<int> myvector (3,100);
// 100 100 100
vector<int>::iterator it;
it = myvector.begin();
it = myvector.insert ( it , 200 );
// 200 100 100 100
myvector.insert (it,2,300);
// 300 300 200 100 100 100

// "it" 不再有效, 设置一个新的:
it = myvector.begin();

vector<int> anothervector (2,400);
myvector.insert (it+2,anothervector.begin(),anothervector.end());
// 300 300 400 400 200 100 100 100
int myarray [] = { 501,502,503 };
myvector.insert (myvector.begin(), myarray, myarray+3);
// 501 502 503 300 300 400 400 200 100 100 100
```


### 3. 删除

```cpp
// 删除vector中最后一个元素
nums.pop_back();

// 移除元素，给的是指针
nums.erase(const_iterator position); //特定位置的
nums.erase(const_iterator first, const_iterator last); //一段范围内

// 清除所有元素，容量归为0
nums.clear()

```


### 4. 排序

```cpp
// 对nums进行排序
sort(nums.begin(),nums.end());

// 对vector中的元素进行逆序
reverse(nums.begin(), nums.end());
```


### 5. 头尾

```cpp
// begin()和end()返回指针

// front()和back()返回元素
```


## unorder_map

参考：[]()


### 1. 插入键值对

```cpp
unordered_map<int, string> myMap;
myMap.insert({1, "apple"});         // 插入键值对
myMap.insert_or_assign(2, "banana");  // 插入或者更新键值对
```



### 2. 查找

```cpp
auto it = myMap.find(1);
if (it != myMap.end()) {
    cout << "Found: " << it->second << endl;  // 输出 "apple"
}

```


### 3. 通过键访问元素

```cpp
cout << myMap[1];  // 访问键为1的值
myMap[3] = "grape"; // 插入新键值对
```


### 4. 删除元素

```cpp
myMap.erase(1);  // 删除键为1的元素
```


### 5. 检查是否存在某个键

```cpp
if (myMap.count(2)) {
    cout << "Key 2 exists!" << endl;
}
```


### 6. 大小和清空

```cpp
cout << "Size: " << myMap.size() << endl;
cout << "Is Empty: " << myMap.empty() << endl;
myMap.clear();  // 清空所有元素
```


## unorder_set

参考：[]()

### 1. 插入元素

```cpp
unordered_set<int> mySet;
mySet.insert(1);   // 插入元素1
mySet.insert(2);   // 插入元素2
```

### 2. 查找元素

```cpp
# find(value)，若不存在则返回end()
auto it = mySet.find(1);
if (it != mySet.end()) {
    cout << "Found!" << endl;
}
```

### 3. 删除元素

```cpp
mySet.erase(1);  // 删除元素1
```

### 4. 检查元素是否存在

```cpp
if (mySet.count(2)) {
    cout << "2 is in the set" << endl;
}
```

### 5. 大小和清空

```cpp
cout << "Size: " << mySet.size() << endl;
cout << "Is Empty: " << mySet.empty() << endl;
mySet.clear();  // 清空所有元素
```
