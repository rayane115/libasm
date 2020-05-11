# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/11 06:50:13 by user42            #+#    #+#              #
#    Updated: 2020/05/11 06:50:16 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global    ft_write
section   .text

ft_write:   
            mov             rax, 1      ; appel système pour l'écriture    
            syscall                     ; invoquer le système d'exploitation pour faire l'écriture
            cmp				rax, 0 	    ; byte c'est pour checker un seul caractère : est ce que le caractère sur lequel on est == '\0' ?
			jl				error		; si != '\0', on retourne au début de la boucle
            ret
        
error:
			mov			 	rax, -1
			ret	

