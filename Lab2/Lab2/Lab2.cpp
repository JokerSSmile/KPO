#include "stdafx.h"
#include "LongLongLong.h"

int main()
{
	try
	{
		LongLongLong a("2222235");
		LongLongLong b("22222222222222222222222222245");
		std::cout << (a - b) << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
    return 0;
}

