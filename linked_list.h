/**
 * @file linked_list.h
 * @author Sours
 * @brief Bibliothèque permettant la gestion de listes chaînées
 * @version 0.1
 * @date 2022-11-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/**
 * @brief Structure des listes chaînées
 * 
 */
typedef struct _linked_list{
    struct _linked_list* before;
    struct _linked_list* next;
    void* value;
}*linked_list;

/**
 * @brief Ajoute la valeur à la fin de la liste chaînée
 * 
 * @param root NULL si c'est le premier maillon
 * @param value 
 * @return linked_list l'adresse de la valeur 
 */
linked_list linked_list_push(linked_list root,void* value);

/**
 * @brief Supprime la dernière valeur de la liste chaînée
 * 
 * @param root 
 */
void linked_list_pop (linked_list root);

/**
 * @brief Renvoie le nombre d'éléments de la liste chaînée
 * 
 * @param root 
 * @return int 
 */
int linked_list_length(linked_list root);

/**
 * @brief ajoute un élément à l'adresse spécifiée
 * et déplace s'il y en avait un l'élément pourtant
 * le même index à l'élément d'après
 * 
 * @param root 
 * @param value 
 * @param index 
 * @return linked_list l'adresse de la valeur 
 */
linked_list linked_list_add(linked_list root,void* value,int index);

/**
 * @brief Ajoute un élément après le maillon demandé
 * soude la liste ensuite
 * 
 * @param target 
 * @param value 
 */
void linked_list_add_after(linked_list target,void* value);

/**
 * @brief Ajoute un élément après le maillon demandé
 * soude la liste ensuite
 * 
 * @param target 
 * @param value 
 * @return linked_list l'adresse de la valeur 
 */
linked_list linked_list_add_before(linked_list target,void* value);

/**
 * @brief Cherche un élément
 * 
 * @param root 
 * @param text 
 */
linked_list linked_list_search(linked_list root,linked_list searched);

/**
 * @brief Echange 2 éléments dans la liste
 * 
 * @param link1 
 * @param link2 
 */
linked_list linked_list_swap(linked_list link1, linked_list link2);

/**
 * @brief Inverse l'ordre de la liste
 * 
 * @param root 
 */
linked_list linked_list_revert(linked_list root);

/**
 * @brief libère toute la liste
 * 
 * @param root 
 */
void linked_list_clean(linked_list root);

/**
 * @brief Supprime l'élément de la liste
 * 
 * @param link 
 * @return linked_list 
 */
linked_list linked_list_remove(linked_list link);


void linked_test(linked_list* link);
#endif