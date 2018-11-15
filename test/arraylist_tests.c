#include "../headers/arraylist.h"
#include "Unity/unity.h"
#include "Unity/unity_internals.h"

static void test_arraylist_new_not_null() {
    ArrayList* arraylist = ArrayList_create();
    TEST_ASSERT_NOT_NULL(arraylist);

    ArrayList_free(arraylist);
}

static void test_arraylist_new_size_zero() {
    ArrayList* arraylist = ArrayList_create();
    TEST_ASSERT_EQUAL_INT(0, arraylist->size);

    ArrayList_free(arraylist);
}

static void test_arraylist_new_size_is_correct() {
    ArrayList* arraylist = ArrayList_create();
    ArrayList_add(arraylist, (int*)new_int(10));
    TEST_ASSERT_EQUAL_INT(1, arraylist->size);

    ArrayList_free(arraylist);
}

static void test_arraylist_new_capacity_is_correct() {
    ArrayList* arraylist = ArrayList_create();
    TEST_ASSERT_EQUAL_INT(10, arraylist->capacity);

    ArrayList_free(arraylist);
}

static void test_arraylist_insert() {
    ArrayList* arraylist = ArrayList_create();
    ArrayList_add(arraylist, (int*)new_int(10));
    TEST_ASSERT_EQUAL_INT(10, *(int*)arraylist->data[0]);

    ArrayList_free(arraylist);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_arraylist_new_not_null);
    RUN_TEST(test_arraylist_new_size_zero);
    RUN_TEST(test_arraylist_new_size_is_correct);
    RUN_TEST(test_arraylist_new_capacity_is_correct);
    RUN_TEST(test_arraylist_insert);
    UNITY_END();

    return 0;
}

