#include <gtest/gtest.h>
#include <../include/Graph.hpp>
#include <vector>
#include <string>

TEST(sanity_test, sanity_test)
{
    EXPECT_EQ(true, true);
}

TEST(import_test, import_basic_params)
{
    Graph g(std::string("../test/test_data/test1"), false);
    EXPECT_EQ(g.no_edges, 3);
    EXPECT_EQ(g.no_vortex, 3);
    EXPECT_EQ(g.no_questions, 1);
}

TEST(import_test, import_vortex)
{
    Graph g(std::string("../test/test_data/test1"), false);
    EXPECT_EQ(g.connections[0][0].first, 1);
    EXPECT_EQ(g.connections[0][0].second, 4);
    EXPECT_EQ(g.connections[0][1].first, 2);
    EXPECT_EQ(g.connections[0][1].second, 20);
}

TEST(import_test, import_questions)
{
    Graph g(std::string("../test/test_data/test1"), false);
    EXPECT_EQ(g.questions[0].first, 0);
    EXPECT_EQ(g.questions[0].second, 2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
