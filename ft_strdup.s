# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/11 06:50:38 by user42            #+#    #+#              #
#    Updated: 2020/05/11 06:50:44 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global 	ft_strdup
	extern 	ft_strlen
	extern 	malloc
	extern 	ft_strcpy
 
ft_strdup:
	call 	ft_strlen             ;rax = len de str
	mov 	r8, rdi                ;r8 = str = source
	inc 	rax                      ;rax++

	mov 	rdi, rax		;pour envoyer la longueur a malloc
	call 	malloc		;rax = ptr de dest
	cmp 	rax, 0			;malloc failled
	jle 	error_malloc
	mov 	rdi, rax		;retour de malloc param 1 a ft_strcpy
	mov 	rsi, r8		;deplace str dans le param 2 de ft_strcpy
	call 	ft_strcpy	;appel de ft_strcpy
	ret

error_malloc:
	xor rax, rax ;retourne NULL
	ret
