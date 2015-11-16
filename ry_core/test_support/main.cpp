#include "stdafx_ry_core_test.h"

int main(int argc, char** argv)
{
	int result;

	if (PathFileExists(_T("ry_core_testdir.txt")))
	{
		::testing::InitGoogleTest(&argc, argv);
		result = RUN_ALL_TESTS();
	}
	else
	{
		printf_s("Please run the test case in right directory.\n");
		result = -1;
	}
	return result;
}