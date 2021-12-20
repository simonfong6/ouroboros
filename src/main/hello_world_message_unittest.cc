#include "main/hello_world_message.h"

#include <gtest/gtest.h>


TEST(HelloWorldMessage, HelloWorldMesssageFunc) {
    // Test the message is correct.
    EXPECT_EQ("Hello World!!!", hello_world_message());
}

TEST(HelloWorldMessage, HelloWorldMesssageFuncNoOp) {
    // Empty test.
    EXPECT_EQ("", "");
}
