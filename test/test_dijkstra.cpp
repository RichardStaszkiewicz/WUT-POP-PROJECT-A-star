#include <gtest/gtest.h>
#include <../include/Dijkstra.hpp>
#include <vector>
#include <string>

TEST(sanity_test, sanity_test)
{
    EXPECT_EQ(true, true);
}

TEST(construction_tests, set_Graph)
{
    Graph graph(std::string("../test/test_data/test1"), false);
    Dijkstra dijkstra(graph);
    ASSERT_EQ(dijkstra.get_Graph().no_edges, 3);
}

TEST(example_tests, exe)
{
    Graph graph(std::string("../test/test_data/test1"), false);
    Dijkstra dijkstra(graph);
    ASSERT_EQ(dijkstra.exe(0, 2), 10);
}
TEST(example_tests, exe1)
{
    Graph graph(std::string("../test/test_data/test1"), false);
    Dijkstra dijkstra(graph);
    ASSERT_EQ(dijkstra.exe(2, 1), 6);
}
TEST(example_tests, exe_disconnected)
{
    Graph graph(std::string("../test/test_data/test3"), false);
    Dijkstra dijkstra(graph);
    ASSERT_EQ(dijkstra.exe(6, 0), -1);
}
TEST(example_tests, exe_disconnected2)
{
    Graph graph(std::string("../test/test_data/test4"), false);
    Dijkstra dijkstra(graph);
    ASSERT_EQ(dijkstra.exe(0, 6), -1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}