#include "catch2/catch_test_macros.hpp"
#include "list.h"
#include "list_sort.h"

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr)    (sizeof(arr) / sizeof((arr)[0]))
#endif

struct node_t
{
    int32_t data;
    struct list_head list;
};

static int32_t list_entry_data(const struct list_head *head)
{
    struct node_t *node = list_entry(head, struct node_t, list);

    return node->data;
}

int __attribute__((nonnull(2,3)))
list_cmp_int32(void *priv, const struct list_head *a, const struct list_head *b)
{
    int32_t data_a = list_entry_data(a);
    int32_t data_b = list_entry_data(b);

    return (data_a > data_b);
}

int qsort_cmp_int32(const void *a, const void *b)
{
    int32_t data_a = *(int32_t *)a;
    int32_t data_b = *(int32_t *)b;

    return (data_a > data_b);
}

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

    SECTION("sort") {
        struct node_t *node;

        node = (struct node_t *)malloc(sizeof(struct node_t));
        LIST_HEAD(deque);

        int32_t array[] = {7, 5, 16, 8};

        for (uint32_t i = 0; i < ARRAY_SIZE(array); i++) {
            node = (struct node_t *)malloc(sizeof(struct node_t));
            node->data = array[i];
            list_add_tail(&node->list, &deque);
        }

        list_sort(NULL, &deque, list_cmp_int32);

        qsort(array, ARRAY_SIZE(array), sizeof(int32_t), qsort_cmp_int32);

        struct list_head *pos;
        uint32_t i = 0;
        list_for_each(pos, &deque) {
            struct node_t *node = list_entry(pos, struct node_t, list);
            REQUIRE(array[i++] == node->data);
        }
    }
}