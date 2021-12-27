#include "catch2/catch_test_macros.hpp"
#include "list.h"

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr)    (sizeof(arr) / sizeof((arr)[0]))
#endif

struct node_t
{
    int32_t data;
    struct list_head list;
};

TEST_CASE("ListTest", "[list test]")
{
    SECTION("add") {
        struct node_t *node;

        node = (struct node_t *)malloc(sizeof(struct node_t));
        LIST_HEAD(deque);

        int32_t array[] = {7, 5, 16, 8};

        for (uint32_t i = 0; i < ARRAY_SIZE(array); i++) {
            node = (struct node_t *)malloc(sizeof(struct node_t));
            node->data = array[i];
            list_add(&node->list, &deque);
        }

        struct list_head *pos;
        uint32_t i = 0;
        list_for_each_prev(pos, &deque) {
            struct node_t *node = list_entry(pos, struct node_t, list);
            REQUIRE(array[i++] == node->data);
        }
    }

    SECTION("add_tail") {
        struct node_t *node;

        node = (struct node_t *)malloc(sizeof(struct node_t));
        LIST_HEAD(deque);

        int32_t array[] = {7, 5, 16, 8};

        for (uint32_t i = 0; i < ARRAY_SIZE(array); i++) {
            node = (struct node_t *)malloc(sizeof(struct node_t));
            node->data = array[i];
            list_add_tail(&node->list, &deque);
        }

        struct list_head *pos;
        uint32_t i = 0;
        list_for_each(pos, &deque) {
            struct node_t *node = list_entry(pos, struct node_t, list);
            REQUIRE(array[i++] == node->data);
        }
    }
}