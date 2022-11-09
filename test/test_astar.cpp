#include <gtest/gtest.h>
#include <../include/Astar.hpp>
#include <../include/Graph.hpp>
#include <vector>
#include <string>

TEST(sanity_test, sanity_test)
{
    EXPECT_EQ(true, true);
}

TEST(construction_tests, graph_import)
{
    Graph g(std::string("../test/test_data/test1"), false);
    Astar alg1(g);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}