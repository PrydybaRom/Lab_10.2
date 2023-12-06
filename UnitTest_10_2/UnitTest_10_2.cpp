#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10_2.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest102
{
	TEST_CLASS(UnitTest102)
	{
	public:
		
		TEST_METHOD(TestMaxSpacesCount)
		{
			char fname[] = "102";  

			
			std::ofstream testFile(fname);
			testFile << "Text with four    space";
			testFile.close();

			
			int result = MaxSpacesCount(fname);

			int expected = 4;

			
			Assert::AreEqual(expected, result);
		}
	};
}
