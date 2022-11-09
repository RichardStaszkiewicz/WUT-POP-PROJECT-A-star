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
    EXPECT_EQ(alg1.g.no_edges, 3);
}

TEST(functionality_tests, basic_bfs)
{
    Graph g(std::string("../test/test_data/test1"), false);
    Astar alg1(g);
    alg1.prep(0);
    auto x = alg1.get_vertex_dist();
    EXPECT_EQ(x[0], 0);
    EXPECT_EQ(x[1], 1);
    EXPECT_EQ(x[2], 1);
}

TEST(functionality_tests, basic_heuristic)
{
    Graph g(std::string("../test/test_data/test1"), false);
    Astar alg1(g);
    alg1.prep(2);
    EXPECT_EQ(alg1.heuristic(0, 2), 10);
}

TEST(example_tests, execution_test1)
{
    Graph g(std::string("../test/test_data/test1"), false);
    Astar alg1(g);
    EXPECT_EQ(alg1.exe(0, 2), 10);
}

TEST(example_tests, execution_test2)
{
    Graph g(std::string("../test/test_data/test2"), false);
    Astar alg1(g);
    EXPECT_EQ(alg1.exe(3, 1), 80);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}