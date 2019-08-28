/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 08:05:18 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/28 09:25:42 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int check_pawn(int k_row, int k_col, int p_row, int p_col)
{
	if (k_row == p_row - 1 || k_row == p_row + 1)
	{
		if (k_col == p_col - 1 || k_col == p_col + 1)
			return (1);
	}
	return (0);
}

int check_bishop(int k_row, int k_col, int b_row, int b_col, int r_len)
{
	int r;
	int c;

	r = 1;
	c = 1;
	while (r < r_len)
	{
		if (b_row == k_row + r && b_col == k_col + c)
			return (1);
		else
		{
			r++;
			c++;
		}
	}
	r = 1;
	c = 1;
	while (r < r_len)
	{
		if (b_row == k_row - r && b_col == k_col - c)
			return (1);
		else
		{
			r++;
			c++;
		}
	}
	return (0);
}

int	is_in_check(char **board, int row, int column)
{
	int r;
	int c;
	int r_len;

	r = 1;
	c = 0;
	r_len = 0;
	while (board[r][r_len])
		r_len++;
	while (board[r])
	{
		while (board[r][c])
		{
			if (board[r][c] == 'P')
				if (check_pawn(row, column, r, c))
					return (1);
			if (board[r][c] == 'B')
				if (check_bishop(row, column, r, c, r_len))
					return (1);
	//		if (board[r][c] == 'R')
	//			if (check_rook(row, column, r, c))
	//				return (1);
	//		if (board[r][c] == 'Q')
	//			if (check_queen(row, column, r, c))
	//				return (1);
			c++;
		}
		r++;
	}
	return (0);
}
#include <stdio.h>
int main(int ac, char **av)
{
	int		i;
	int		j;
	char	**board;

	i = 1;
	j = 0;
	board = av;
	if (ac > 1)
	{
		while (board[i])
		{
			j = 0;
			while (board[i][j])
			{
				if (board[i][j] == 'K')
				{
					if (is_in_check(board, i, j))
					{
						write(1, "Success", 7);
					}
					else
						write(1, "Fail", 4);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
