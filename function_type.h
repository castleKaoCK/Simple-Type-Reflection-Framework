#ifndef __FUNCTION_TYPE
#define __FUNCTION_TYPE

//因为数组的元素不能为void、引用或函数，所以根据是否能够转化为
//数组元素来判断 T 的类型是否为函数。再将void和引用类型特化来
//这两种排除情况。

template<typename T>
class IsFunctionT{
private:
	typedef	char	One;
	typedef	struct { char a[2]; }	Two;
	template<typename U> static One test(...);
	template<typename U> static Two test(U (*)[1]);
public:
	enum { Yes = sizeof(IsFunctionT<T>::test<T>(0)) == 1};
	enum { No  = !Yes };
};



template<typename T>
class IsFunctionT< T& >{	//偏特化引用
public:
	enum{ Yes = 0 };
	enum{ No  = !Yes};
};

template<>
class IsFunctionT<void>{	//全特化void
public:
	enum{ Yes = 0 };
	enum{ No  = !Yes};
};

template<>
class IsFunctionT<void const>{	//全特化void const
public:
	enum{ Yes = 0 };
	enum{ No  = !Yes};
};

template<>
class IsFunctionT<void volatile>{	//全特化void volatile
public:
	enum{ Yes = 0 };
	enum{ No  = !Yes};
};

template<>
class IsFunctionT<void const volatile>{	//全特化void const volatile
public:
	enum{ Yes = 0 };
	enum{ No  = !Yes};
};

#endif	//__FUNCTION_TYPE
