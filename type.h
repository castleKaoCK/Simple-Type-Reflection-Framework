#ifndef __TYPE_H
#define __TYPE_H

#include<iostream>
#include"fundamental_type.h"
#include"function_type.h"
#include"compound_type.h"
#include"enum_type.h"
#include"class_type.h"

using namespace std;

template<typename T>
class Type{
public:
	enum { 	IsFundaT = IsFundaT<T>::Yes,
			IsPtrT   = CompoundT<T>::IsPtrT,
			IsRefT   = CompoundT<T>::IsRefT,
			IsArrayT = CompoundT<T>::IsArrayT,
			IsFuncT  = CompoundT<T>::IsFuncT,
			IsPtrMemT= CompoundT<T>::IsPtrMemT,
			IsEnumT  = IsEnumT<T>::Yes,
			IsClassT = IsClassT<T>::Yes
			};
};



//检查传递进来的模板实参的类型
template<typename T>
void __check_type(){
	if(Type<T>::IsFundaT){
		cout<<"\t\tIsFundaT   基本类型"<<endl;
	}
	if(Type<T>::IsPtrT){
		cout<<"\t\tIsPtrT     指针类型"<<endl;
	}
	if(Type<T>::IsRefT){
		cout<<"\t\tIsRefT     引用类型"<<endl;
	}
	if(Type<T>::IsArrayT){
		cout<<"\t\tIsArrayT   数组类型"<<endl;
	}
	if(Type<T>::IsFuncT){
		cout<<"\t\tIsFuncT    函数类型"<<endl;
	}
	if(Type<T>::IsPtrMemT){
		cout<<"\t\tIsPtrMemT  成员指针类型"<<endl;
	}
	if(Type<T>::IsEnumT){
		cout<<"\t\tIsEnumT    枚举类型"<<endl;
	}
	if(Type<T>::IsClassT){
		cout<<"\t\tIsClassT   类类型"<<endl;
	}
}

//检查传递进来的函数调用实参的类型
template<typename T>
void check_type(T){
	__check_type<T>();

	//对于指针类型，检查他们所引用的类型
	if(Type<T>::IsPtrT || Type<T>::IsPtrMemT){
		__check_type<typename CompoundT<T>::BaseT >();
	}
}



#endif	//__TYPE_H
