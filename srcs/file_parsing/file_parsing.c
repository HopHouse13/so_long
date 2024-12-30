/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:22:37 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/30 23:33:35 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

// _____________________________________________________________________________
// 
// Fonction qui check si le fichier est bien un fichier. (et pas une repertoire)
// 
// -----------------------------------------------------------------------------
// 
// Le parametre tranmis est le nom du fichier.
// La fonction open tente d'ouvrir notre fichier en tant que repertoire.
// Si l'ouverture a été correctement exécutée, le fd aura une valeur. Si il y a
// eu une erreur, le fd prendra la valeur -1 (valeur d'erreur)
// Le return est en fonction de ce resultat.

int	ft_is_not_a_directory(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

// _____________________________________________________________________________
// 
// Fonction qui check si le fichier existe.
// 
// -----------------------------------------------------------------------------
// 
// Meme principe, si le fd a une valeur autre que -1, ce la indique que la
// fonction open a reussi a creer le fichier non existant.
// Les flag "O_CREAT | O_EXCL" fonctionne de la maniere suivante:
// O_CREAT -> si le fichier n'existe pas deja -> creation du fichier.
// O_EXCL -> ce flag serre a faire echouer la fonction open si le fichier est
// deja cree. (renvoit -1)
// O_EXCL peut avoir un souci si le fichier existant est un lien symboliques 
// (selon les systemes.
// si le fd est -1 -> non creation -> fichier existe deja -> return (0)
// !-1 -> fichier inexistant -> creation du fichier -> return (1) (erreur)
// La fonction remove (lib. standard <stdio.h>) est utilisee pour supprimer
// immediatement le fichier cree en cas de fichier inexistant. 
// (verifier si c'est une fonction autorisee)

int	ft_existing_file(char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_EXCL, 0777);
	if (fd != -1)
	{
		close(fd);
		remove(file); // surement a supp. -> fonction interdite (elle supp. le fichier cree si il m'existe pas)
		return (1);
	}
	return (0);
}

int	ft_valid_extension(char *file)
{
	int	size;

	size = ft_strlen(file);
	if (size < 4
		|| file[size - 4] != '.'
		|| file[size - 3] != 'b'
		|| file[size - 2] != 'e'
		|| file[size - 1] != 'r')
		return (1);
	return (0);
}

int	ft_file_not_openable(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

int	ft_empty_file(char *file)
{
	int		fd;
	char	buffer[1];

	fd = open(file, O_RDONLY);
	if ((read(fd, buffer, 1)) == 0)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
