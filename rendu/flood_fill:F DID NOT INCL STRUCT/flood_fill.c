/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:38:54 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/06 14:05:44 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	flood_fill2(char **tab, char c, t_point size, t_point pos)
{
	t_point point[4];
	
	point[0].x = pos.x;
	point[0].y = pos.y + 1;
	point[1].x = pos.x;
	point[1].y = pos.y - 1;
	point[2].x = pos.x + 1;
	point[2].y = pos.y;
	point[3].x = pos.x - 1;
	point[3].y = pos.y;
	if (pos.x >= 0 && pos.x < size.x && pos.y >= 0 && pos.y < size.y)
	{
		if (tab[pos.y][pos.x] == 'F' || tab[pos.y][pos.x] != c)
			return ;
		tab[pos.y][pos.x] = 'F';
		flood_fill2(tab, c, size, point[0]);
		flood_fill2(tab, c, size, point[1]);
		flood_fill2(tab, c, size, point[2]);
		flood_fill2(tab, c, size, point[3]);
	}
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char c;

	c = tab[begin.y][begin.y];
	flood_fill2(tab, c, size, begin);

}
