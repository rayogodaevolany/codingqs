#include <gtest/gtest.h>
#include "recordCollection.h"

TEST(recordCollection, dumdum){
    EXPECT_EQ(1,1);
}

TEST(recordCollection, copyList){
    recordCollection rc;
    rc.addRecord(87, 1);

    recordCollection newrc;

    newrc = rc;

    EXPECT_EQ(newrc.averageRecords(), 87);
    
}
