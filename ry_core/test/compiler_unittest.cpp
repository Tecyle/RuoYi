#include "stdafx_ry_core_test.h"

TEST_F(CompilerTest, BuildCorrectCPP)
{
	FILE* fp;
	string testSrc;

	testSrc += "#include <iostream>\r\n";
	testSrc += "using namespace std;\r\n\r\n";
	testSrc += "int main()\r\n";
	testSrc += "{\r\n";
	testSrc += "\tcout << \"Hello World!\" << endl;\r\n";
	testSrc += "\treturn 0;\r\n";
	testSrc += "}\r\n";
	fopen_s(&fp, "build_correct_cpp.cpp", "w+");
	fwrite(testSrc.c_str(), testSrc.size(), 1, fp);
	fclose(fp);

	RYCppCompiler cppCompiler;
	EXPECT_TRUE(cppCompiler.Compile(_T("build_correct_cpp.cpp"), _T("build_correct_cpp.exe")));
	EXPECT_TRUE(PathFileExists(_T("build_correct_cpp.cpp")));
}