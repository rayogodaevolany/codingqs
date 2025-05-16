#include <gtest/gtest.h>
#include "recordCollection.h"
#include <gmock/gmock.h>  // for ::testing::ElementsAre
                          
using ::testing::ElementsAre;

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

TEST(recordCollection, grades){
    recordCollection rc;
    rc.addRecord(90, 4);
    rc.addRecord(89, 3);
    rc.addRecord(67, 2);
    rc.addRecord(87, 1);

    int *a; a = rc.grades();
    int b[4] =  {87, 67, 89, 90};
    for (int i = 0; i<4; i++){
        EXPECT_EQ(a[i], b[i]);
    }

    
}

TEST(recordCollection, RecordsWithinRange){
    recordCollection rc;
    rc.addRecord(90, 4);
    rc.addRecord(89, 3);
    rc.addRecord(67, 2);
    rc.addRecord(87, 1);


    recordCollection  newrc = rc.RecordsWithinRange(80, 90);

    int *a; a = newrc.grades();
    int b[3] = {90, 89, 87} ;
    for (int i = 0; i<3; i++){
        EXPECT_EQ(a[i], b[i]);
    }
}

