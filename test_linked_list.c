#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdbool.h>

#include "linked_list.h"

void test_lenght_void() { CU_ASSERT(linked_list_length(NULL) == 0); }

void test_create_linked_list() {
  int five = 5;
  linked_list list = linked_list_push(NULL, &five);
  CU_ASSERT(list->value == &five);
  CU_ASSERT(linked_list_length(list) == 1);
  CU_ASSERT(list->before == NULL);
  CU_ASSERT(list->next == NULL);
  linked_list_clean(list);
}

void test_push_multiple_elements() {
  int five = 5;
  linked_list list = linked_list_push(NULL, &five);
  linked_list_push(list, "salut");
  CU_ASSERT(linked_list_length(list) == 2);
  CU_ASSERT(list->before == NULL);
  CU_ASSERT(list->next != NULL);
  linked_list_clean(list);
}
void test_free_one_element() {
  int five = 5;
  linked_list list = linked_list_push(NULL, &five);
  linked_list_pop(list);
  CU_ASSERT(list == NULL);
  linked_list_clean(list);
}
void test_free_two_elements() {
  int five = 5;
  linked_list list = linked_list_push(NULL, &five);
  linked_list_push(list, "salut");
  linked_list_pop(list);
  CU_ASSERT(linked_list_length(list) == 1);
  CU_ASSERT(list->next == NULL);
  linked_list_clean(list);
}

void test_add_after() {
  
}

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }
int main() {

  CU_pSuite pSuite = NULL;

  /* initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* add a suite to the registry */
  pSuite = CU_add_suite("Suite_1", init_suite, clean_suite);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* add the tests to the suite */
  if (NULL == CU_add_test(pSuite, "test_lenght_void", test_lenght_void) ||
      NULL ==
          CU_add_test(pSuite, "test_lenght_void", test_create_linked_list) ||
      NULL ==
          CU_add_test(pSuite, "test_lenght_void", test_push_multiple_elements)

  ) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Run all tests using the CUnit Basic interface */
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
