#include "stdafx.h"
#include "LongLongLong.h"

int main()
{
	try
	{
		LongLongLong a("2222235");
		std::cout << a.NumberLength() << std::endl;
		LongLongLong b("22222222222222222222222222245");
		std::cout << b.NumberLength() << std::endl;
		std::cout << (b * a) << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
    return 0;
}

