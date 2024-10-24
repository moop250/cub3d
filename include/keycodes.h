/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:24:00 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/10/24 15:44:34 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

# ifdef __APPLE__
#  define KEY_W			13
#  define KEY_A			0
#  define KEY_S			1
#  define KEY_D			2
#  define KEY_LEFT		123
#  define KEY_RIGHT		124
#  define KEY_FORWARD 	126
#  define KEY_BACKWARD	125
#  define KEY_ESC 53
# endif

# ifndef __APPLE__
#  define KEY_ESC 65307
#  define KEY_PLUS 65451
#  define KEY_MINUS 65453
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_Z 122
#  define KEY_X 120
#  define KEY_P 112
#  define KEY_M 109
#  define KEY_R 114
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_W 119
#  define KEY_PAGE_UP 65365
#  define KEY_PAGE_DOWN 65366
#  define MOUSE_SCROLL_UP 4
#  define MOUSE_SCROLL_DOWN 5
# endif

#endif
