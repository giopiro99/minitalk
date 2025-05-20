/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:05 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:02:01 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Returns the last node of a linked list.
 *
 * Traverses the list until reaching the last node, then returns it.
 *
 * @param lst Pointer to the first node of the list.
 * @return t_list* Pointer to the last node of the list, or NULL if the list is empty.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
/*void print_content(void *content)
{
	printf("%d\n", *((int *)content));
}
int main()
{
	t_list *lst = NULL;
	int *val1 = malloc(sizeof(int)), *val2 = malloc(sizeof(int));

	*val1 = 10;
	*val2 = 20;
	t_list *node1 = ft_lstnew(val1);
	t_list *node2 = ft_lstnew(val2);
	node1->next = node2;
	node2->next = NULL;
	lst = node1;
	t_list *last = ft_lstlast(lst);
	if (last)
	{
		print_content(last->content);
	}
	free(val1);
	free(val2);
	free(node1);
	free(node2);
}*/
