# Projet printf en C
Ce projet consiste à recréer la fonction `printf` en langage C sans utiliser d'autres bibliothèques que `unistd.h` et `stdarg.h`. L'objectif est de comprendre le fonctionnement interne de la fonction printf standard et d'implémenter une version simplifiée.

## Fonctionnalités
La version personnalisée de `printf` prend en charge un sous-ensemble des spécificateurs de format de la version standard, notamment :

`%c` : Caractère  
`%s` : Chaîne de caractères  
`%p` : Pointeur  
`%d` et `%i` : Entier signé  
`%u` : Entier non signé  
`%x` : Entier non signé en hexadécimal (minuscule)  
`%X` : Entier non signé en hexadécimal (majuscule)  
`%%` : Afficher un '%'
## Exemple d'utilisation
```c
#include "my_printf.h"

int main() {
    my_printf("Hello, %s! This is a number: %d\n", "World", 42);
    return 0;
}
```
## Structure du Projet
ft_printf1.c : Fichier contenant l'implémentation de la fonction ft_printf ainsi que des fonctions necessaires.
ft_printf2.c : Fichier contenant le reste des fonctions necessaires.
ft_printf.h : Fichier d'en-tête déclarant les prototypes de fonctions et les structures nécessaires.
Makefile : Fichier pour la compilation du projet.
