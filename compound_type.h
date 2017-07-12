#ifndef __COMPOUND_TYPE
#define __COMPOUND_TYPE

#include"function_type.h"

/*
 *	用于判断组合类型的基本模板
 */
template<typename T>
class CompoundT{
public:
	enum{ 	IsPtrT = 0, 	//是否为指针
			IsRefT = 0, 	//是否为引用
			IsArrayT = 0,	//是否为数组
		  	IsFuncT = IsFunctionT<T>::Yes, 	//是否为函数
			IsPtrMemT = 0	//是否为成员指针
			};

	typedef	T	BaseT;		//用于构造模板参数类型T的直接类型
	typedef	T	BottomT;	//用于构造T的原始类型
	typedef	CompoundT<void>	ClassT;	//对于成员指针类型，这是成员所属类的类型
};
/**************************************************************************/


/********************************************
 *	以下为判断具体组合类型的偏特化版本
 ********************************************/



/*
 *	引用类型
 */
template<typename T>
class CompoundT < T& >{
public:
	enum{ 	IsPtrT = 0, 	
			IsRefT = 1, 	//引用类型
			IsArrayT = 0,	
		  	IsFuncT = 0, 	
			IsPtrMemT = 0	
			};

	typedef	T	BaseT;		
	typedef	typename CompoundT < T >::BottomT	BottomT;
	typedef	CompoundT<void>	ClassT;	
};
/********************************************************************/

/*
 *	指针类型
 */

template<typename T>
class CompoundT < T* >{
public:
	enum{ 	IsPtrT = 1, 	//指针类型
			IsRefT = 0, 	
			IsArrayT = 0,	
		  	IsFuncT = 0, 	
			IsPtrMemT = 0	
			};

	typedef	T	BaseT;		
	typedef	typename CompoundT<T>::BottomT	BottomT;
	typedef	CompoundT<void>	ClassT;	
};
/*********************************************************************/

/*
 *	数组类型
 */
template<typename T, size_t N>
class CompoundT < T[N] >{	//针对数组的偏特化
public:
	enum{ 	IsPtrT = 0, 	
			IsRefT = 0, 	
			IsArrayT = 1,	//数组类型	
		  	IsFuncT = 0, 	
			IsPtrMemT = 0	
			};

	typedef	T	BaseT;		
	typedef	typename CompoundT<T>::BottomT	BottomT;
	typedef	CompoundT<void>	ClassT;	
};


template<typename T>
class CompoundT < T[ ] >{	//针对空数组的偏特化
public:
	enum{ 	IsPtrT = 0, 	
			IsRefT = 0, 	
			IsArrayT = 1,	//数组类型	
		  	IsFuncT = 0, 	
			IsPtrMemT = 0	
			};

	typedef	T	BaseT;		
	typedef	typename CompoundT<T>::BottomT	BottomT;
	typedef	CompoundT<void>	ClassT;	
};
/**********************************************************************/

/*
 *成员指针类型
 */
template<typename T, typename C>
class CompoundT < T C::*  >{	//针对成员指针的偏特化
public:
	enum{ 	IsPtrT = 0, 	
			IsRefT = 0, 	
			IsArrayT = 0,	
		  	IsFuncT = 0, 	
			IsPtrMemT = 1	//成员指针类型	
			};

	typedef	T	BaseT;		
	typedef	typename CompoundT<T>::BottomT	BottomT;
	typedef	C	ClassT;		//成员所属类的类型
};
/***********************************************************************/

#endif	//__COMPOUND_TYPE
