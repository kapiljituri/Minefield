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

TEST(FieldTest, isSafeWithEmptyHidden)
{
	Field minefield;
  minefield.placeMine(0,9);

  try{
	   ASSERT_TRUE( minefield.isSafe(9,9) );
   } catch (std::string x){
        std::cout << "Out of Bound Exception!" << std::endl;
   }
}

TEST(FieldTest, isSafeWithMine________DESIGNED_TO_FAIL)
{
	Field minefield;
  minefield.placeMine(9,9);

  try{
	   ASSERT_TRUE( minefield.isSafe(9,9) );
   } catch (std::string x){
        std::cout << "Out of Bound Exception!" << std::endl;
   }
}

TEST(FieldTest, revealAdjacentEmpty)
{
	Field minefield;
  int x=6, y=6;

  minefield.revealAdjacent(x,y);

  try{
	   ASSERT_EQ( EMPTY_SHOWN, minefield.get(x-1,y) );
     ASSERT_EQ( EMPTY_SHOWN, minefield.get(x+1,y) );
     ASSERT_EQ( EMPTY_SHOWN, minefield.get(x,y-1) );
     ASSERT_EQ( EMPTY_SHOWN, minefield.get(x,y+1) );
   } catch (std::string x){
        std::cout << "Out of Bound Exception!" << std::endl;
   }
}

TEST(FieldTest, revealAdjacentMine________DESIGNED_TO_FAIL)
{
	Field minefield;
  int x=6, y=6;

  minefield.placeMine(x-1, y);
  minefield.revealAdjacent(x,y);

  try{
	   ASSERT_EQ( EMPTY_SHOWN, minefield.get(x-1,y) );
     ASSERT_EQ( EMPTY_SHOWN, minefield.get(x+1,y) );
     ASSERT_EQ( EMPTY_SHOWN, minefield.get(x,y-1) );
     ASSERT_EQ( EMPTY_SHOWN, minefield.get(x,y+1) );
   } catch (std::string x){
        std::cout << "Out of Bound Exception!" << std::endl;
   }
}
