#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

linked_list linked_list_push(linked_list root, void *value) {
  linked_list new_linked = (linked_list)malloc(sizeof(struct _linked_list));
  if (new_linked == NULL)
    return NULL;

  if (root == NULL) {
    root = new_linked;
    new_linked->before = NULL;

  } else {
    linked_list current_list = root;
    while (current_list->next != NULL) {
      current_list = root->next;
    }
    new_linked->before = current_list;
    current_list->next = new_linked;
  }
  new_linked->next = NULL;
  new_linked->value = value;
  return new_linked;
}

void linked_list_pop(linked_list root) {
  linked_list current_list = root;
  while (current_list->next != NULL) {
    current_list = current_list->next;
  }
  linked_list before = current_list->before;
  before->next = NULL;
  free(current_list);
}

int linked_list_length(linked_list root) {
  if (root == NULL)
    return 0;
  int length = 1;
  linked_list current_list = root;
  while (current_list->next != NULL) {
    length += 1;
    current_list = root->next;
  }
  return length;
}

linked_list linked_list_add(linked_list root, void *value, int index) {
  if (index >= linked_list_length(root))
    return NULL;
  linked_list before = root;
  for (int i = 1; i < index; i++) {
    before = before->next;
  }
  linked_list next = before->next;

  linked_list new_linked = (linked_list)malloc(sizeof(struct _linked_list));

  before->next = new_linked;

  if (next != NULL) {
    next->before = new_linked;
    new_linked->next = next;
  }

  new_linked->before = before;
  new_linked->value = value;
  return new_linked;
}

void linked_list_add_after(linked_list target, void *value) {

  linked_list new_linked = (linked_list)malloc(sizeof(struct _linked_list));
  linked_list next = target->next;

  target->next = new_linked;

  if (next != NULL) {
    next->before = new_linked;
    new_linked->next = next;
  }

  new_linked->before = target;
  new_linked->value = value;
}

linked_list linked_list_add_before(linked_list target, void *value) {
  linked_list before = target->before;

  linked_list new_linked = (linked_list)malloc(sizeof(struct _linked_list));

  before->next = new_linked;

  if (before != NULL) {
    before->next = new_linked;
    new_linked->before = before;
  }

  new_linked->before = before;
  new_linked->value = value;
  return new_linked;
}

linked_list linked_list_search(linked_list root, linked_list searched) {
  if (root == NULL)
    return NULL;
  linked_list current = root;
  while (current->next != NULL) {
    if (current == searched)
      return current;
    current = current->next;
  }
  if (current == searched)
    return current;
  return NULL;
}

linked_list linked_list_swap(linked_list link1, linked_list link2) {
  linked_list temp_linked = (linked_list)malloc(sizeof(struct _linked_list));
  if (temp_linked == NULL)
    return NULL;

  temp_linked->before = link1->before;
  temp_linked->next = link1->next;

  link1->before = link2->before;
  link1->next = link2->next;

  link2->before = temp_linked->before;
  link2->next = temp_linked->next;

  free(temp_linked);
  if (link2->before == NULL)
    return link2;
  return link1;
}

linked_list linked_list_revert(linked_list root) {
  if (root == NULL)
    return NULL;
  linked_list temp_linked = (linked_list)malloc(sizeof(struct _linked_list));
  linked_list current = root;
  while (current->next != NULL) {
    temp_linked->before = current->before;
    current->before = current->next;
    current->next = temp_linked->before;
    current = current->next;
  }
  temp_linked->before = current->before;
  current->before = current->next;
  current->next = temp_linked->before;
  free(temp_linked);
  return current;
}

void linked_list_clean(linked_list root) {
  if (root == NULL)
    return;
  while (root->next != NULL) {
    root = root->next;
    free(root->before);
  }
  free(root);
}

linked_list linked_list_remove(linked_list link) {
  if (link == NULL)
    return NULL;
  if (link->before != NULL) {
    linked_list before = link->before;
    if (link->next != NULL) {
      before->next = link->next;
      link->next->before = before;
    }
    free(link);
    return before;
  }
  if (link->next != NULL) {
    linked_list next = link->next;
    free(link);
    return next;
  }
  free(link);
  return NULL;
}  


void linked_test(linked_list* link) {
  static int six = 6;
  static int trois = 42;
  linked_list pt = *link;
  pt->value = (void*) &trois;
  linked_list temp_linked = (linked_list)malloc(sizeof(struct _linked_list));
  temp_linked->value = (void*)&six;
  temp_linked->next = *link;
  *link = temp_linked;
}
