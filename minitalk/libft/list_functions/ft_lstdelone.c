/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:01:43 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 14:57:12 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Deletes and frees a single node of a linked list.
 *
 * Applies the function 'del' to the content of the node before freeing the node itself.
 *
 * @param lst Pointer to the node to be deleted.
 * @param del Function pointer to delete the content of the node.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del && lst)
	{
		del(lst->content);
		free(lst);
	}
}

/* int main()
{
	t_list	*lst;
	lst = malloc(1 * sizeof(t_list));
	char	c[5] = "ciao";
	lst->content = malloc(5 * sizeof(char));
	if (lst->content == NULL)
		free(lst);
    ft_strlcpy(lst->content ,"ciao", 5);
	lst->next = NULL;
	printf("%s\n", (char *)lst->content);
	ft_lstdelone(lst, ft_lstdelete);
	printf("%s\n fdsgv", (char *)lst->content);
} */
