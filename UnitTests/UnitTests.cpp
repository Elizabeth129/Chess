#include "pch.h"
#include "CppUnitTest.h"
#include "../Chess1/Chess1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(Checkmate)
		{
			Moves m;
			int figure[n][n] = {
						{1,2,3,0,5,0,2,1},
						{6,6,6,6,0,6,6,6},
						{0,0,0,0,0,0,0,0},
						{0,0,3,0,6,0,0,0},
						{0,0,0,0,12,0,0,0},
						{0,0,8,0,0,8,0,0},
						{12,12,12,12,0,4,12,12},
						{7,0,9,10,11,9,0,7}
			};
			Assert::AreEqual(m.CheckmateBlack(figure), true);
		}

		TEST_METHOD(Queen)
		{
			Moves m;
			int figure[n][n] = {
						{1,2,3,0,5,0,2,1},
						{6,6,6,6,0,6,6,6},
						{0,0,0,0,0,0,0,0},
						{0,0,3,0,6,0,0,0},
						{0,0,0,0,12,0,0,4},
						{0,0,8,0,0,8,0,0},
						{12,12,12,12,0,12,12,12},
						{7,0,9,10,11,9,0,7}
			};
			Assert::AreEqual(m.Queen(figure, 7, 4, 4,4 ), true);
		}

		TEST_METHOD(King)
		{
			Moves m;
			int figure[n][n] = {
						{1,2,3,0,5,0,2,1},
						{6,6,6,6,0,6,6,6},
						{0,0,0,0,0,0,0,0},
						{0,0,3,0,6,0,0,0},
						{0,0,0,0,12,0,0,4},
						{0,0,8,0,0,8,0,0},
						{12,12,12,12,0,0,12,12},
						{7,0,9,10,0,11,0,7}
			};
			Assert::AreEqual(m.King(figure, 5, 7, 5, 6), false);
		}

		TEST_METHOD(CanCastlingWhiteLong)
		{
			Moves m;
			Moves::SetCanCastlingWhiteLong(true);
			int figure[n][n] = {
						{1,0,0,0,5,0,2,1},
						{6,6,6,6,0,6,6,6},
						{0,0,0,0,0,0,0,0},
						{0,0,3,0,6,0,0,0},
						{0,0,0,0,12,0,0,4},
						{0,0,8,0,0,8,0,0},
						{12,12,12,12,0,0,12,12},
						{7,0,9,10,0,11,0,7}
			};
			Assert::AreEqual(m.CastlingWhiteLong(figure), true);
		}

		TEST_METHOD(CheckWhite)
		{
			Moves m;
			int figure[n][n] = {
						{1,0,0,0,0,0,2,1},
						{6,6,6,6,6,5,6,6},
						{0,0,0,0,0,0,0,0},
						{0,0,3,0,6,0,0,0},
						{0,0,0,0,12,0,0,4},
						{0,0,8,0,0,8,0,0},
						{9,12,12,12,0,0,12,12},
						{7,0,9,10,0,11,0,7}
			};
			Assert::AreEqual(m.CheckWhite1(figure), true);
		}
	};
}
