#include <gtest/gtest.h>
#include "graph.h"

TEST(GraphTest, ExampleTest) {
    Graph G("./test.txt");
    // ASSERT_EQ(G.get_v(), 100);
    // ASSERT_EQ(G.get_e(), 120);
    EXPECT_EQ(G.get_v(), 10);
    EXPECT_EQ(G.get_e(), 12);
    std::string s = queryBridgeWords(G,"seek","to");
    EXPECT_EQ(s, "No bridge words from \"seek\" to \"to\"!");
    s = queryBridgeWords(G,"to","explore");
    EXPECT_EQ(s, "No bridge words from \"to\" to \"explore\"!");
    s = queryBridgeWords(G,"explore","new");
    EXPECT_EQ(s, "The bridge words from \"explore\" to \"new\" is:strange");
    s = queryBridgeWords(G,"new","and");
    EXPECT_EQ(s, "The bridge words from \"new\" to \"and\" is:life");
    s = queryBridgeWords(G,"and","exciting");
    EXPECT_EQ(s, "No \"exciting\" in the graph!");
    s = queryBridgeWords(G,"exciting","synergies");
    EXPECT_EQ(s, "No \"exciting\" and \"synergies\" in the graph!");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
