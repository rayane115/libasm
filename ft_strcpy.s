# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rqouchic <rqouchic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/11 06:50:24 by user42            #+#    #+#              #
#    Updated: 2020/05/14 04:56:55 by rqouchic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global ft_strcpy
section        .text
	  
ft_strcpy:
			mov			rax, -1        ;index a -1

null:
        
			cmp			byte [rdi + rax], 0     ; if chaine null on return
			jne			return		

start:
            inc         rax     				;increment index
            cmp			byte [rsi + rax], 0  	; si la source arrive a la fin on return
			je			return          		;jump sur return
			mov			cl, byte [rsi + rax]    ;on met dans le registre cl chaque charact de source
			mov			byte[rdi + rax], cl     ; on met dans la destination chaque charact de cl qui a copier source
			jmp			start	    			; vu que c'est pas fini on revien a start

return:	
			mov			cl, 0
			mov			byte[rdi + rax], cl
			mov			rax, rdi
			ret             					; on return la chaine