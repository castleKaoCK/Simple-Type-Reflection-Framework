#ifndef	__ENUM_TYPE
#define	__ENUM_TYPE

#include"fundamental_type.h"
#include"compound_type.h"


struct SizeOverOne { char c[2]; };

template < typename T,
			bool convert_possible = !CompoundT<T>::IsFuncT &&
									!CompoundT<T>::IsArrayT >
class ConsumeUDC{
public:
	operator T() const;
};

//到函数、数组类型的转型是不允许的
template<typename T>
class ConsumeUDC <T,false>{
};

//到void类型的转型是不允许的
template<bool convert_possible>
class ConsumeUDC <void, convert_possible>{
};

char enum_check(bool);
char enum_check(char);
char enum_check(signed char);
char enum_check(unsigned char);
char enum_check(wchar_t);
char enum_check(signed short);
char enum_check(unsigned short);

char enum_check(signed int);
char enum_check(unsigned int);

char enum_check(signed long);
char enum_check(unsigned long);
#if LONGLONG_EXISTS
char enum_check(signed long long);
char enum_check(unsigned long long);
#endif	//LONGLONG_EXISTS

char enum_check(float);
char enum_check(double);
char enum_check(long double);


SizeOverOne enum_check(...);

//枚举类型可以通过向整型的隐式转型来得到区别。
template<typename T>
class IsEnumT{
public:
	enum { Yes = IsFundaT<T>::No &&
				!CompoundT<T>::IsRefT &&
				!CompoundT<T>::IsPtrT &&
				!CompoundT<T>::IsPtrMemT &&
				sizeof(enum_check(ConsumeUDC<T>())) == 1};
	enum { No = !Yes};
};

#endif	//__ENUM_TYPE

