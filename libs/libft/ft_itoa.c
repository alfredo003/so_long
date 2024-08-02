/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achivela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:45:57 by achivela          #+#    #+#             */
/*   Updated: 2024/07/31 14:59:32 by achivela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	nb_len(long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		n *= -1;
		len ++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	long int	nbr;

	nbr = n;
	len = nb_len(nbr);
	str = malloc ((len) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	len = len - 1;
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		nbr = nbr * -1;
		str[0] = '-';
	}
	while (nbr > 0)
	{
		str[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (str);
}
