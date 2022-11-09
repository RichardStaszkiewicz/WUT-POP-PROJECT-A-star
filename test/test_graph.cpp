#include <gtest/gtest.h>
#include <../include/Graph.hpp>
#include <vector>
#include <string>

TEST(sanity_test, sanity_test)
{
    EXPECT_EQ(true, true);
}

TEST(import_basic, import_test)
{
    Graph g(std::string("test_data/test1"));
    EXPECT_EQ(g.no_edges, 3);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
