# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rqouchic <rqouchic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/14 04:38:48 by user42            #+#    #+#              #
#    Updated: 2020/05/14 04:56:38 by rqouchic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global    ft_write
section   .text
extern     __errno_location

ft_write:   
            mov             rax, 1      ; appel système pour l'écriture    
            syscall                     ; invoquer le système d'exploitation pour faire l'écriture
            cmp				rax, 0 	    ; byte c'est pour checker un seul caractère : est ce que le caractère sur lequel on est == '\0' ?
			jl				error		; si != '\0', on retourne au début de la boucle
            ret
        
error:
            neg             rax
            mov             rdi, rax
            call            __errno_location
            mov             [rax], rdi
            mov             rax, -1
            ret
          	

