/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:51:07 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 14:55:56 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Adds a new node at the end of a linked list.
 *
 * If the list is empty, the new node becomes the first element.
 * Otherwise, it appends the new node to the last node of the list.
 *
 * @param lst Pointer to the pointer of the first node in the list.
 * @param new The new node to add at the end of the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}
/*int main()
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
	ft_lstadd_back(&lst, node1);
	ft_lstadd_back(&lst, node2);
	ft_lstadd_back(&lst, node3);
	t_list *current = lst;
	while (current)
	{
		printf("%d\n", *((int*)current->content));
		current = current->next;
	}
	free(val1);
	free(val2);
	free(val3);
}*/
