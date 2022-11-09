#include <gtest/gtest.h>
#include <../include/Graph.hpp>

TEST(sanity_test, sanity_test)
{
    EXPECT_EQ(true, true);
}

TEST(init_test, sanity_test)
{
    Graph g;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
