#include <gtest/gtest.h>
#include <tools/exception.hpp>
#include <string>

using namespace exception;

TEST(ExceptionTest, GetMessage){

    int value = 0;
    EXPECT_THROW({
        try {
            if(value == 0) throw Exception("new exception", "exception");
        } catch(Exception ex){
            ASSERT_EQ("new exception", ex.getMessage());
            ASSERT_EQ("exception", ex.getClassName());
            throw ex;
        }
    }, Exception); 
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}