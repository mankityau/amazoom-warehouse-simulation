#include <gtest/gtest.h>
#include "reality/spacemanager.cpp"
#include "reality/realityexception.h"
TEST(spacemanager_test, constructWithZeroDimension_expectZeroDimensionException){
    EXPECT_THROW(new reality::SpaceManager("FOO",{0,0,0}), reality::ZeroDimensionException);
}

TEST(spacemanager_test, constructWithProperDimension_expectNoException){
    new reality::SpaceManager("FOO",{5, 5, 5});
}

TEST(spacemanager_test, putItem_firstOccuranceProperItem_expectTrue){
    reality::SpaceManager spaceManager("putItem_firstOccuranceProperItem_expectTrue", {5, 5, 5});
    reality::Item item("ITEM_ID", {0,0,0}, 'I');
    EXPECT_EQ(spaceManager.putItem(item), true);
}


TEST(spacemanager_test, putItem_secondOccuranceProperItem_expectFalse){
    reality::SpaceManager spaceManager("putItem_secondOccuranceProperItem_expectFalse", {5, 5, 5});
    reality::Item item("ITEM_ID", {0,0,0}, 'I');
    spaceManager.putItem(item);
    EXPECT_EQ(spaceManager.putItem(item), false);
}

TEST(spacemanager_test, putItem_twoDifferentItemOnSameSpot_expectSpaceOccupiedException) {
    reality::SpaceManager spaceManager("putItem_twoDifferentItemOnSameSpot_expectSpaceOccupiedException", {5, 5, 5});
    reality::Item itemFoo("ITEM_ID_FOO", {0,0,0}, 'I');
    reality::Item itemBar("ITEM_ID_BAR", {0,0,0}, 'I');
    spaceManager.putItem(itemFoo);
    EXPECT_THROW(spaceManager.putItem(itemBar), reality::SpaceOccupiedException);
}

TEST(spacemanager_test, putItem_putRemoveThenPut_expectTrue) {
    reality::SpaceManager spaceManager("putItem_putRemoveThenPut_expectTrue", {5, 5, 5});
    reality::Item item("ITEM_ID", {0,0,0}, 'I');
    spaceManager.putItem(item);
    spaceManager.removeItem(item);
    EXPECT_EQ(spaceManager.putItem(item), true);
}

TEST(spacemanager_test, removeItem_noOccurrence_expectFalse) {
    reality::SpaceManager spaceManager("removeItem_noOccurrence_expectFalse", {5, 5, 5});
    reality::Item item("ITEM_ID", {0,0,0}, 'I');
    EXPECT_EQ(spaceManager.removeItem(item), false);
}


TEST(spacemanager_test, removeItem_firstOccurrence_expectFalse) {
    reality::SpaceManager spaceManager("removeItem_firstOccurrence_expectFalse", {5, 5, 5});
    reality::Item item("ITEM_ID", {0,0,0}, 'I');
    spaceManager.putItem(item);
    EXPECT_EQ(spaceManager.removeItem(item), true);
}


TEST(spacemanager_test, removeItem_firstOccurrenceAndRemoveTwice_expectFalse) {
    reality::SpaceManager spaceManager("removeItem_firstOccurrenceAndRemoveTwice_expectFalse", {5, 5, 5});
    reality::Item item("ITEM_ID", {0,0,0}, 'I');
    spaceManager.putItem(item);
    spaceManager.removeItem(item);
    EXPECT_EQ(spaceManager.removeItem(item), false);
}