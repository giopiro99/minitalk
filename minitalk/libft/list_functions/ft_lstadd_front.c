/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:23:21 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 14:56:19 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Adds a new node at the beginning of a linked list.
 *
 * If the list is empty, the new node becomes the first element.
 * Otherwise, the new node is inserted before the current first node.
 *
 * @param lst Pointer to the pointer of the first node in the list.
 * @param new The new node to add at the front of the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
/*void print_content(void *content)
{
	printf("%d\n", *((int *)content));
}
int main()
{
	t_list *lst = NULL;
	int *val1 = malloc(sizeof(int));
	int *val2 = malloc(sizeof(int));
	int *val3 = malloc(sizeof(int));

	*val1 = 10;
	*val2 = 20;
	*val3 = 30;
	t_list *node1 = ft_lstnew(val1);
	t_list *node2 = ft_lstnew(val2);
	t_list *node3 = ft_lstnew(val3);
	ft_lstadd_front(&lst, node1);
	ft_lstadd_front(&lst, node2);
	ft_lstadd_front(&lst, node3);
	t_list *current = lst;
	while (current)
	{
		print_content(current->content);
		current = current->next;
	}
	free(val1);
	free(val2);
	free(val3);
}*/
