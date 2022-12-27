/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:21:40 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/25 16:18:24 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <semaphore.h>

int	main(void)
{
	sem_t	*sem;

	// Tentative d'ouverture du sémaphore nommé "semaphore1" sans spécifier de flag
	sem = sem_open("semaphore1", O_CREAT, 0644, 1);
	if (sem == SEM_FAILED) {
		perror("Erreur lors de l'ouverture du sémaphore");
		return 1;
	}

	// Fermeture du sémaphore
	if (sem_unlink("semaphore1") == -1) {
		perror("Erreur lors de la fermeture du sémaphore");
		return 1;
	}

	return 0;
}

/*
La fonction sem_open() de la bibliothèque POSIX permet de créer ou d'ouvrir
un sémaphore nommé. Elle prend en entrée un nom de sémaphore et des flags
qui contrôlent son comportement, et retourne un pointeur sur un objet
de type sem_t qui représente le sémaphore. Si le sémaphore n'existe pas déjà,
il est créé et initialisé avec la valeur initiale spécifiée dans les flags.
Si le sémaphore existe déjà, il est ouvert et sa valeur initiale
est laissée inchangée.
*/
