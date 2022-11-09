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

TEST(basic_bfs_test, functionality)
{
    Graph g(std::string("../test/test_data/test1"), false);
    Astar alg1(g);
    alg1.prep(0);
    auto x = alg1.get_vertex_dist();
    EXPECT_EQ(x[0], 0);
    EXPECT_EQ(x[1], 1);
    EXPECT_EQ(x[2], 1);
}

TEST(basic_heuristic_test, functionality)
{
    Graph g(std::string("../test/test_data/test1"), false);
    Astar alg1(g);
    EXPECT_EQ(alg1.heuristic(0, 2), 10);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}