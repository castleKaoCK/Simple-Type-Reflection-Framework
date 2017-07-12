all:test
.PHONY :all
test:type_test.cpp class_type.h compound_type.h enum_type.h function_type.h fundamental_type.h type.h
	g++ type_test.cpp -std=c++11 -o test
