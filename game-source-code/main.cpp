#include "Game.h"
#include "Googletest.cpp"
#include <gtest/gtest.h>

using namespace std;

int main(int argc, char** argv)
{
//    google test.
//    testing::InitGoogleTest(&argc,argv);
//    RUN_ALL_TESTS();
//    
//    n game
    //cout << "Running tests" << std::endl;
//    testing::InitGoogleTest(&argc, argv);
//    RUN_ALL_TESTS();
    Game player;
    //player.creatingEnemyVector();
    //player.CreateLanderSprites();
    player.run();
    
    return 0;
}