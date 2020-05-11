# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/11 06:50:00 by user42            #+#    #+#              #
#    Updated: 2020/05/11 06:50:04 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global			ft_strlen
section			.text

ft_strlen:
			mov				rax, -1 				; ici rax c'est i, et on l'initie à -1

start:												; la c'est la boucle, en c on utilise while, en asm on jump
			inc				rax						; on incremente rax, i++
			cmp				byte [rdi + rax], 0 	; byte c'est pour checker un seul caractère : est ce que le caractère sur lequel on est == '\0' ?
			jne				start					; si != '\0', on retourne au début de la boucle
return:
			ret										; si == '\0', on retourne : ret = rax 		
