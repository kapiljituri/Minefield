/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"

class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;

	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}

TEST(FieldTest, isSafeTest)
{
	Field minefield;
  minefield.placeMine(0,9);

  try{
	   ASSERT_TRUE( minefield.isSafe(9,9) );
   } catch (std::string x){
        std::cout << "Out of Bound Exception!" << std::endl;
   }
}
