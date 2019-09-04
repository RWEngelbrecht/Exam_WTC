/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 08:05:18 by rengelbr          #+#    #+#             */
/*   Updated: 2019/09/04 09:36:34 by rengelbr         ###   ########.fr       */
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

int check_bishop(int k_row, int k_col, int b_row, int b_col, int row_len)
{
	int r;
	int c;

	r = 1;
	c = 1;
	while (r < row_len)
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
	while (r < row_len)
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

int check_rook(int k_row, int k_col, int r_row, int r_col)
{
	if (r_row == k_row || r_col == k_col)
			return (1);
		return (0);
}

int check_queen(int k_row, int k_col, int q_row, int q_col, int row_len)
{
	if (check_rook(k_row, k_col, q_row, q_col)
			|| check_bishop(k_row, k_col, q_row, q_col, row_len))
		return (1);
	return (0);
}

int	is_in_check(char **board, int row, int column)
{
	int r;
	int c;
	int r_len;

	r = 1;
	r_len = 0;
	while (board[r][r_len])
		r_len++;
	while (board[r])
	{
		c = 0;
		while (board[r][c])
		{
			if (board[r][c] == 'P')
				if (check_pawn(row, column, r, c))
					return (1);
			if (board[r][c] == 'B')
				if (check_bishop(row, column, r, c, r_len))
					return (1);
			if (board[r][c] == 'R')
				if (check_rook(row, column, r, c))
					return (1);
			if (board[r][c] == 'Q')
				if (check_queen(row, column, r, c, r_len))
					return (1);
			c++;
		}
		r++;
	}
	return (0);
}

int main(int ac, char **av)
{
	int		r;
	int		c;
	char	**board;

	r = 1;
	c = 0;
	board = av;
	if (ac > 1)
	{
		while (board[r])
		{
			c = 0;
			while (board[r][c])
			{
				if (board[r][c] == 'K')
				{
					if (is_in_check(board, r, c))
					{
						write(1, "Success", 7);
					}
					else
						write(1, "Fail", 4);
				}
				c++;
			}
			r++;
		}
	}
	write(1, "\n", 1);
}
