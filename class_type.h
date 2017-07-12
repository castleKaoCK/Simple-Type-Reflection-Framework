#ifndef __CLASS_TYPE
#define __CLASS_TYPE

#include"fundamental_type.h"
#include"compound_type.h"
#include"enum_type.h"

//将之前的可推导的类型排除，即得到类类型
template<typename T>
class IsClassT{
public:
	enum { Yes = IsFundaT<T>::No &&
				IsEnumT<T>::No &&
				!CompoundT<T>::IsPtrT &&
				!CompoundT<T>::IsRefT &&
				!CompoundT<T>::IsArrayT &&
				!CompoundT<T>::IsPtrMemT &&
				!CompoundT<T>::IsFuncT
				};
	enum { No  =!Yes };
};

#endif	//__CLASS_TYPE
