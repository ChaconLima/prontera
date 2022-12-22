#include <gtest/gtest.h>
#include <prontools/random.hpp>
#include <iostream>

using namespace pron_random;
using namespace std;

TEST(RandomTest, RandomTest){
    Random rand = Random();
    
    for (size_t i = 0; i < 10; i++){
        const long unsigned int cv = 100;
        cout<<rand.getRandomInt(&cv)<<"\t";
    }
    cout<<endl;

    for (size_t i = 0; i < 10; i++){
        cout<<rand.getRandomPercent()<<"\t";
    }
    cout<<endl;

    for (size_t i = 0; i < 10; i++){
        cout<<rand.getRandomBool()<<"\t";
    }
    cout<<endl;

    rand.endProcess();
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
